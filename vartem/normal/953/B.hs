import Data.List (sort)

main = do
	(n:as) <- fmap (map read . words) getContents
	let a = sort as
	let b = zipWith (-) (tail a) a
	let g = foldl1 gcd b
	print $ (quot ((a !! (n - 1)) - (a !! 0)) g) - (n - 1)