module Main(main) where

import qualified Data.ByteString.Char8 as B
import Data.Int (Int64)
import Control.Monad(replicateM)
import Data.Functor
import Data.List
import Data.Array
import Data.Maybe

isDigit '-' = True
isDigit x = x>='0' && x<='9'
split f (a:as) lft
	| f a = split f as (a:lft)
	| otherwise = (reverse lft, as)
split _ [] lft = (reverse lft, [])

readInts :: IO [Int]
readInts = (map ((fst.fromJust) . B.readInt)) . (B.split ' ') <$> B.getLine

data Mono = INC | DEC
fn::([[Int]], Mono) -> Int -> ([[Int]], Mono)
fn ((t:ts):as, INC) x = if x >= t then ((x:t:ts):as, INC) else ((x:[t]):(t:ts):as, DEC)
fn ((t:ts):as, DEC) x = if x <= t then ((x:t:ts):as, DEC) else ((x:[t]):(t:ts):as, INC)
break :: [Int] -> [[Int]]
break l@(f:s:r) =
	let
		nature = if f<s then INC else DEC
	in
		fst $ foldl fn ([s:f:[]], nature) r
break (f:[]) = [[f]]

cost :: [Int] -> Int64
cost [] = 0
cost [a] = 0
cost l =
	let
		a = fromIntegral . head $ l
		b = fromIntegral . last $ l
	in
		(max a b) - (min a b)

ff (incl, excl) l@(a:as) =
	let
		inside = reverse . tail . reverse $ as
	in
		(max (incl + (cost as)) (excl + (cost l)), max (incl + (cost inside)) (excl + (cost $ a:inside)))
main = do
	getLine
	nums <- Main.break . reverse <$> readInts
	print $ fst $ foldl ff (0::Int64, 0::Int64) nums
	return ()