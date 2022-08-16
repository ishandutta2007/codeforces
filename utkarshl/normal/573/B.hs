module Main(main) where

import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Functor
import Data.Int (Int64)

getNums64 :: B.ByteString -> [Int64]
getNums64 =
	let
		f1 = (map (fromInteger . (fst.fromJust) . B.readInteger))
		f2 = (B.split ' ')
	in f1.f2
getNums :: B.ByteString -> [Int]
getNums =
	let
		f1 = (map ((fst.fromJust) . B.readInt))
		f2 = (B.split ' ')
	in f1.f2
readInts :: IO [Int]
readInts = getNums <$> B.getLine
readInts64 :: IO [Int64]
readInts64 = getNums64 <$> B.getLine

foldmap fn v [] = []
foldmap fn v (x:xs) = let v2 = fn v x in (v2 `seq` v2) : foldmap fn v2 xs

main = do
	n <- readInts
	h <- readInts
	let fn a b = min (a+1) b
	let lft = foldmap fn 0 h
	let rt = reverse $ foldmap fn 0 $ reverse h
	let ans = foldl max 0 $ map (\(a,b) -> min a b) $ zip lft rt
	print ans