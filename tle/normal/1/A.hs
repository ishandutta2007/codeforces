module Main where

solve [n,m,a]=x*y
    where
        x=(n+a-1)`div`a
        y=(m+a-1)`div`a

main = do
    line <- getLine
    let input = map (read::String->Integer) (words line)
    putStrLn $ show $ solve input