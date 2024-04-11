--import Debug.Trace
import qualified Data.ByteString.Char8 as B
import Control.Applicative
import Control.Arrow
import Control.Monad
import Data.List
import Data.Maybe

main = do
  [n,m] <- lineInts
  board <- replicateM n getLine
  let (u,d) = g board
      (l,r) = g $ transpose board
  putStrLn $ unwords $ map (show . flip div 2) [l+r, u+d]

f l = if null t then (100000, 0) else (fst $ head t, fst $ last t)
  where t = filter (\(_,y) -> y == 'B') (zip [1..] l)
g :: [String] -> (Int, Int)
g = foldr ((\(x,y) -> min x *** max y). f) (100000,0)

-- Below is template code
readInt = fst . fromJust . B.readInt
lineInt = readInt <$> B.getLine
lineInts = map readInt . B.words <$> B.getLine

--infixr 0 ##
--(##) x msg = traceShow msg x