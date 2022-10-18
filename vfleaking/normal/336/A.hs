calc :: Int -> Int -> (Int, Int, Int, Int)
calc x y
	| x > 0 && y > 0 = (0, l, l, 0)
	| x > 0 && y < 0 = (0, -l, l, 0)
	| x < 0 && y > 0 = (-l, 0, 0, l)
	| x < 0 && y < 0 = (-l, 0, 0, -l)
	| otherwise      = (0, 0, 0, 0)
	where
		l = abs x + abs y

handle :: [String] -> [[String]]
handle [sx, sy] = [map show [x1, y1, x2, y2]]
	where
		(x1, y1, x2, y2) = calc (read sx) (read sy)

main :: IO ()
main = interact $ unlines . map unwords . handle . words