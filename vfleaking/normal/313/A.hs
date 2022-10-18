handle :: [String] -> [[String]]
handle [n] = [[show $ max (max (read t1 :: Int) (read t2 :: Int)) (read n)]]
    where
        t1 = init n
        t2 = (init $ init n) ++ [last n]

main :: IO ()
main = interact $ unlines . map unwords . handle . words