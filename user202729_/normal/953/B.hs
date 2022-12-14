import Data.List

main = interact $ show . f . map read . words . last . lines

f :: [Int] -> Int
f ls = ((maximum ls - minimum ls) `div` 
  (foldl1' gcd $ zipWith (-) ls (tail ls))) + 1 - length ls