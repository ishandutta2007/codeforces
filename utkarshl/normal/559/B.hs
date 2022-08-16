module Main(main) where

norm :: String -> String
norm str
	| (length str) `mod` 2 == 1 = str
	| otherwise = let
			l = (length $ str) `quot` 2
			a = norm $ take l str
			b = norm $ drop l str
		in if a<b then a++b else b++a

main = do
	s1 <- getLine
	s2 <- getLine
	let res = if norm s1 == norm s2 then "YES" else "NO"
	putStrLn res