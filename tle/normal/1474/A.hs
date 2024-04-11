module Main where

work [] t=[]
work ('1':xs) 2='0':work xs 1
work ('1':xs) t='1':work xs 2
work ('0':xs) 1='0':work xs 0
work ('0':xs) t='1':work xs 1

run 1 = do
    l1 <- getLine
    l2 <- getLine
    let str=l2
    putStrLn $ work str 5

run x = do
    run 1
    run (x-1)

main = do
    l1 <- getLine
    let t = (read::String->Integer) l1
    run t