module Main (main) where

import Control.Monad
import Data.Functor
import Data.Char(ord)
import qualified Data.Map.Strict as Map

isDigit x = x=='-' || (x>='0' && x<='9')
split f l@(a:as) lft
	| f a = split f as (a:lft)
	| otherwise = (reverse lft, as)
split _ [] lft = (reverse lft, [])
readInts::String -> [Integer]
readInts [] = []
readInts l@(x:xs)
	| isDigit x = let (a, b) = split isDigit l [] in (read a):(readInts b)
	| otherwise = readInts xs

main = do
	wts <- Map.fromList . (zip ['a'..'z']) . readInts <$> getLine
	let mapping (w, _, _) c = ((+) w $ wts Map.! c, w, c)
	str <- scanl mapping (0, 0, '-') <$> getLine
	let
		fn (mp, sm) (ps, pps, c) = (mp', sm') where
			mp' = Map.insertWith (+) (ps, c) 1 mp
			sm' = (+) sm $ Map.findWithDefault 0 (pps, c) mp
	let res = snd $ foldl fn (Map.empty, 0) str
	print res