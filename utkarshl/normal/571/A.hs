module Main(main) where

import qualified Data.ByteString.Char8 as B
import Data.Int (Int64)
import Control.Monad(replicateM)
import Data.Functor
import Data.List
import Data.Array
import Data.Maybe

getNums :: B.ByteString -> [Int]
getNums =
	let
		f1 = (map ((fst.fromJust) . B.readInt))
		f2 = (B.split ' ')
	in f1.f2
readInts :: IO [Int]
readInts = getNums <$> B.getLine

contrib a b c rem = 
	if a+b>c
		then 0
		else
			let
				d = c-a-b
			in
				c2 $ (min rem d)+2

term a b c l =
	let
		start = max a $ max b c
		end = c + l
	in
		sum $ map (\x -> contrib a b x $ end-x) [start..end]

c2 x = (x * (x-1)) `div` 2
c3 x = (x * (x-1) * (x-2)) `div` 6
main = do
	input <- ((map fromIntegral <$> readInts)::IO [Int64])
	let [x, y, z, l] = input
	let [a, b, c] = sort [x, y, z]
	let ans = (c3 (l+3)) - (term a b c l) - (term b c a l) - (term a c b l)
	print ans