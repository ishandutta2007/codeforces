module Main(main) where

import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Functor

getNums :: B.ByteString -> [Int]
getNums =
	let
		f1 = (map ((fst.fromJust) . B.readInt))
		f2 = (B.split ' ')
	in f1.f2
readInts :: IO [Int]
readInts = getNums <$> B.getLine

main::IO ()
main = do
	_ <- readInts
	h <- readInts
	let fn a b = min (a+1) b
	let lft = tail $ scanl fn 0 h
	let rt = reverse $ tail $ scanl fn 0 $ reverse h
	let ans = (foldl max 0 $ zipWith min lft rt)::Int
	print ans