module Main(main) where

import qualified Data.ByteString.Char8 as B
import Data.Functor
import Data.List
import Data.Array
import Data.Maybe
import qualified Data.Map.Strict as Map

getNums :: B.ByteString -> [Int]
getNums =
	let
		f1 = (map ((fst.fromJust) . B.readInt))
		f2 = (B.split ' ')
	in f1.f2
readInts :: IO [Int]
readInts = getNums <$> B.getLine

deepEval a = deepEval' a [] where
	deepEval' [] b = reverse b
	deepEval' (a:as) b = deepEval' as $! ((:) $! eval a) $ b

dpRunner g x_lim y_lim =
	let
		f2 lst y =
			let
				next = undefined : (map (\(x, y_last, x_last) -> g x y x_last y_last) $ zip3 [0..x_lim] lst next)
			in
				deepEval $ tail next
	in
		last $ foldl' (\lst y -> f2 lst y) (take (x_lim+1) $ repeat undefined) [0..y_lim]

contrib :: Int -> Int -> Array Int Int -> Int -> Int -> Int
contrib l1 l2 a c1 c2 = dpRunner solve c1 c2 where
	solve 0 0 _ _ = 0
	solve 0 1 _ _ = 0
	solve 1 0 _ _ = 0
	solve x y xp yp =
		let
			opt1 = if x>0 then (a ! ((x-1)*l1+y*l2-1)) + xp else 0
			opt2 = if y>0 then (a ! (x*l1+(y-1)*l2-1)) + yp else 0
		in
			max opt1 opt2

eval x = if x == x then x else error "meh"

diffs :: (Num t, Eq t) => [t] -> [t]
diffs (a:b:as) = (eval b-a):(diffs $ b:as)
diffs _ = []

main :: IO ()
main = do
	nk <- readInts
	let [n, k] = nk
	a <- sort <$> readInts
	let c1 = ((n-1) `mod` k)+1
	let l1=(n+k-1) `div` k
	let c2 = k-c1
	let l2=l1-1
	let dffs = (listArray (0, n-2) $ diffs a)
	let ans = (last a) - (head a) - (contrib l1 l2 dffs c1 c2)
	print ans