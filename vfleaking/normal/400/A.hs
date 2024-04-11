checkX :: String -> Int -> [Bool]
checkX [] t = replicate t True
checkX s t = map (\(x, y) -> (x && y)) (zip (map (=='X') cur) (checkX rest t))
    where
        (cur, rest) = splitAt t s

handle :: String -> [String]
handle str = [show $ length res] ++ res
    where
        handle_i :: Int -> [String]
        handle_i 13 = []
        handle_i i = if 12 `mod` a == 0 && (or $ checkX str b) then ((show a) ++ "x" ++ (show b)) : rest else rest
            where
                a = i
                b = 12 `div` i
                rest = handle_i (i + 1)
        
        res = handle_i 1

handleAllCase :: Int -> IO ()
handleAllCase 0 = return ()
handleAllCase n = do
    str <- getLine
    putStrLn $ unwords $ handle str
    handleAllCase (n - 1)

main :: IO ()
main = do
    sNCases <- getLine
    handleAllCase $ read sNCases