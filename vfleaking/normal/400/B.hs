import Data.List
import Data.Maybe

handle :: Int -> Int -> IO [Int]
handle 0 _ = return []
handle n m = do
	cur <- getLine
	let
		pG = fromJust $ elemIndex 'G' cur
		pS = fromJust $ elemIndex 'S' cur
	rest <- handle (n - 1) m
	return ((pS - pG) : rest)

unique :: Ord a => [a] -> [a]
unique [] = []
unique [x] = [x]
unique (x0 : x1 : xs)
	| x0 == x1 = unique (x0 : xs)
	| otherwise = x0 : unique(x1 : xs)

main :: IO ()
main = do
	sNM <- getLine
	let
		[n, m] = map read $ words sNM
	a <- handle n m 
	print (if any (<0) a then -1 else length $ unique $ sort a)