transTo01 :: String -> String
transTo01 [] = []
transTo01 (x : xs) = (if x == '0' then '0' else '1') : (transTo01 xs)

handle :: [String] -> [[String]]
handle (_ : xs) = [[show $ length res], res]
    where
    res
        | null $ x1 ++ x10 = x0 ++ x11 ++ x100
        | otherwise        = x0 ++ x1 ++ x10 ++ x100
    x0   = take 1 [x | x <- xs, transTo01 x == "0"  ]
    x1   = take 1 [x | x <- xs, transTo01 x == "1"  ]
    x10  = take 1 [x | x <- xs, transTo01 x == "10" ]
    x11  = take 1 [x | x <- xs, transTo01 x == "11" ]
    x100 = take 1 [x | x <- xs, transTo01 x == "100"]

main :: IO ()
main = interact $ unlines . map unwords . handle . words