module Main where

sieve a b
    |b==[] = []
    |(head b)>a = sieve (a+1) b
    |(head b)==a = (head b):(sieve (a+1) (filter (\e->(e`mod`a)/=0) (tail b)))
    |otherwise = sieve (a+1) (filter (\e->(e`mod`a)/=0) b)

primes=sieve 2 [2..30000]

search_geq (x:xs) b
    | x>=b = x
    | otherwise = search_geq xs b

work t=p*q
    where
        p=search_geq primes $ t+1
        q=search_geq primes $ p+t

run 1 = do
    l1 <- getLine
    putStrLn $ show $ work ((read::String->Integer) l1)

run x = do
    run 1
    run (x-1)

main = do
    l1 <- getLine
    let t = (read::String->Integer) l1
    run t