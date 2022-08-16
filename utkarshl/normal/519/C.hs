module Main (main) where

import Control.Monad
import Data.Functor

isDigit x = x>='0' && x<='9'
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
	[a, b] <- readInts <$> getLine
	let x = min a b
	let y = min (2*x) $ max a b
	print $ (x+y) `quot` 3