module Main(main) where

import Control.Monad(replicateM)
import Data.Functor
import Data.List
import Data.Array

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

factorials = go 0 1 where
	go 200001 _ = []
	go i j = (i,j):(go (i+1) ((j*(i+1)) `rem` p))

p::Integer
p = 1000000007
(<**>) x y = (x * y) `rem` p
(<+>) x y = let t = x + y in if t < p then t else t-p
(<->) x y = let t = x - y in if t < 0 then t+p else t
pow x 0 = 1
pow x a = let ll = pow (x<**>x) (a `quot` 2) in if a `rem` 2 > 0 then (ll <**> x) else ll
inverse x = pow x (p-2)
facs = array (0, 200000) factorials
ifacs = array (0, 200000) $ map (\(x,y) -> (x, inverse y)) factorials
choose a b
	| 0<=b && 0<=a = (facs ! (a+b)) <**> (ifacs ! a) <**> (ifacs ! b)
	| otherwise = 0

dp (prev) me@((i, j)) =
	let
		fn (d, (a, b)) = d <**> (choose (i-a) (j-b))
	in
		((choose (i-1) (j-1)) <-> (foldl (<+>) 0 $ map fn prev), me):prev
runDp :: [(Integer, Integer)] -> [Integer]
runDp l = let t = foldl dp ([]) l in map fst t
--runDp (a:as) = let 

main = do
	l <- getLine
	let [h, w, n] = readInts l
	let srt = sortBy (\x y -> compare (sum x) (sum y))
	blacks <- ((map (\x->(head x, x!!1))).srt) <$> replicateM (fromInteger n) (readInts <$> getLine)
	let all = blacks ++ [(h, w)]
	putStrLn $ show $ head.runDp $ all