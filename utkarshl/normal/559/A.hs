module Main (main) where

triA::Float
triA = (sqrt 3)/4

ta::Float -> Float -> Float -> Float
ta a b c = let s = (a+b+c)/2 in sqrt $ s * (s-a) * (s-b) * (s-c)

sq :: Float -> Float
sq a = a * a

len :: Integer -> Integer -> Float
len a b = sqrt $ (sq $ (fromInteger a)+((fromInteger b)/2.0)) + (fromInteger $ b*b*3)/4.0

calc::Integer->Integer->Integer->Integer->Integer->Integer->Integer
calc a b c d e f = let hA = (fromInteger $ a*b + c*d + e*f)*(sqrt 3)/4 + (ta (len a b) (len c d) (len e f)) in round $ hA/triA

splitOn::Char -> String -> [String]
splitOn _ [] = [""]
splitOn c (x:xs)
	| x==c  = [""] ++ (splitOn c xs)
	| otherwise = let (y:ys) = splitOn c xs in (x:y):ys

main:: IO ()
main = do
	line <- getLine
	let [a,b,c,d,e,f] = (map read $ splitOn ' ' line)::[Integer]
	print $ calc a b c d e f