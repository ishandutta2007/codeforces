import Data.Char (isSpace)
import Data.List (elemIndex, take, drop)
import Data.Maybe (fromJust)

split []                 = []
split (c:cs) | isSpace c = split cs
             | otherwise = case split cs of
                                []     -> (c:[]):[]
                                (s:ss) -> (c:s):ss

main = do ts <- getLine
          solve (read ts)

solve 0 = return ()
solve t = do l <- getLine
             let i = fromJust $ elemIndex ' ' l
             let n = read $ take i l
             let k = read $ drop (i + 1) l
             putStrLn $ winner $ answer n k
             solve $ t - 1

winner True = "Alice"
winner False = "Bob"

answer n k | mod k 3 == 0 = mod (n + 1) (k + 1) == 0 || mod (mod n (k + 1)) 3 /= 0
           | otherwise    = mod n 3 /= 0