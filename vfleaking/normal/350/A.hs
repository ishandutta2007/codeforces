calc :: [Int] -> [Int] -> Int
calc a b = if vMin < vMax then vMin else -1
	where
		vMin = max (maximum a) ((minimum a) * 2)
		vMax = minimum b

handle :: [String] -> [[String]]
handle (sn : sm : xs) = [[show $ calc a b]]
	where
		n = read sn
		a = map read $ take n xs
		b = map read $ drop n xs

main :: IO ()
main = interact $ unlines . map unwords . handle . words