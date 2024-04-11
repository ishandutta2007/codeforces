import Data.Bits

lowbit :: Int -> Int
lowbit x = x .&. (-x)

getVal :: [Int] -> Int
getVal [] = -1
getVal xs = if andAll /= 0 then lowbit andAll else -1
	where
		andAll = foldl1 (.&.) xs

getBest :: [Int] -> [Int] -> [Int]
getBest xs ys
	| valX /= valY = if valX > valY then xs else ys
	| otherwise    = if length xs > length ys then xs else ys
	where
		valX = getVal xs
		valY = getVal ys

calc :: [Int] -> [Int]
calc xs = foldl1 getBest (xs : [filter (\x -> testBit x b) xs | b <- [0 .. 30]])

handle :: [String] -> [[String]]
handle (_ : sa) = [[show $ length res], map show res]
	where
		res = calc $ map read sa

main :: IO ()
main = interact $ unlines . map unwords . handle . words