module Main(main) where
import qualified Data.ByteString.Char8 as B
import Data.Functor
import Data.List
import Data.Array
import Data.Maybe
import qualified Data.Map.Strict as Map
import Control.Monad

getNums :: B.ByteString -> [Int]
getNums =
	let
		f1 = (map ((fst.fromJust) . B.readInt))
		f2 = (B.split ' ')
	in f1.f2
readInts :: IO [Int]
readInts = getNums <$> B.getLine

cpy [] = []
cpy ([a, b]:xs) = (a,b):(b,a):(cpy xs)

handle :: [Int] -> Int
handle [] = 0
handle (7:_) = 7
handle (5:_) = 7
handle (4:[]) = 4
handle (4:0:[]) = 5
handle (4:_) = 7
handle (3:3:_) = 7
handle (3:2:_) = 7
handle (3:1:_) = 7
handle (3:[]) = 4
handle (3:0:[]) = 4
handle (3:0:0:[]) = 5
handle (3:_) = 7
handle (2:2:2:_) = 7
handle (2:2:_) = 3
handle (2:_) = 2
handle (1:_) = 2
handle (0:0:0:_) = 2
handle (0:0:_) = 1
handle (0:_) = 0


dfs tree = go where
	go parent me =
		let
			ch = reverse $ sort $ map (go me) $ filter (/= parent) $ tree ! me
		in
			handle ch

main = do
	n <- (read <$> getLine)::IO Int
	tree <-((accumArray (flip (:)) [] (1, n)) .cpy) <$> replicateM (n-1) readInts
	let res = (dfs tree 0 1)::Int
	putStrLn $ if res<7 then "Yes" else "No"
	return ()