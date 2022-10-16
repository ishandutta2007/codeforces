import Control.Monad

sumDigits :: Integer -> Integer 
sumDigits x
    | x < 10 = x
    | otherwise = sumDigits (div x 10) + mod x 10

solve :: Integer -> Integer 
solve x = if gcd x (sumDigits x) == 1 then solve (x+1) else x

main = do
    line <- getLine
    let tc = read line :: Integer
    ans <- forM_ [1..tc] (\a -> do
            line <- getLine
            let x = read line :: Integer
            print (solve x)
        )
    return ()