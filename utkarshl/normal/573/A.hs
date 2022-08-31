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

check 1 = True
check a = if a `mod` 2 == 0 then check $ a `div` 2 else if a `mod` 3 == 0 then check $ a `div` 3 else False

main = do
	n <- readInts
	a <- readInts
	let g = foldl gcd 0 a
	let b = map (\x -> x `div` g) a
	let c = all check b
	putStrLn $ if c then "Yes" else "No"