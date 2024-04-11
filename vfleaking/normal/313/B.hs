import Data.Array

getQu :: [String] -> [(Int, Int)]
getQu [] = []
getQu (sl : sr : xs) = (read sl, read sr) : (getQu xs)

getSufSum :: String -> [Int]
getSufSum [x] = [0]
getSufSum (x1 : x2 : xs) = ((if x1 == x2 then 1 else 0) + head t) : t
    where
        t = getSufSum (x2 : xs)

getAns :: Array Int Int -> (Int, Int) -> [String]
getAns sum (l, r) = [show $ (sum ! l)  - (sum ! r)]

handle :: [String] -> [[String]]
handle (s : _ : sq) = map (getAns (listArray (1, length(sum)) sum)) (getQu sq)
    where
        sum = getSufSum s

main :: IO ()
main = interact $ unlines . map unwords . handle . words