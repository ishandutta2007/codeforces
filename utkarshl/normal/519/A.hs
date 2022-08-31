module Main(main) where

import Control.Monad
import Data.Functor

find :: Char -> Int
find '.' = 0
find 'q' = -9
find 'r' = -5
find 'b' = -3
find 'n' = -3
find 'p' = -1
find 'k' = 0
find 'Q' = 9
find 'R' = 5
find 'B' = 3
find 'N' = 3
find 'P' = 1
find 'K' = 0

process :: String -> Int
process = sum . (map find)

main = do
	vals <- sum <$> (replicateM 8 $ process <$> getLine)
	putStrLn $ if vals < 0 then "Black" else if vals > 0 then "White" else "Draw"