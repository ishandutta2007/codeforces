isEqual :: Integer -> Integer -> [Integer] -> Bool
isEqual p q [] = q == 0
isEqual _ 0 _ = False
isEqual p q (x : xs) = div p q >= x && isEqual q (p - q * x) xs

handle :: [[String]] -> String
handle [[sp, sq], _, sa] = if isEqual (read sp) (read sq) (map read sa) then "YES" else "NO"

main :: IO ()
main = interact $ handle . map words . lines