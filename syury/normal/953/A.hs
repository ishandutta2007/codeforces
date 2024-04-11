import qualified Data.List.Split as Spl

ptwo :: Integer -> Integer
ptwo 0 = 1
ptwo x = (ptwo $ x - 1) * 2

pth :: Integer -> Integer
pth 0 = 1
pth x = (pth $ x - 1) * 3

check :: Integer -> Integer -> Integer -> Integer -> Int

check l r x y =
    if ((((ptwo x) * (pth y)) >= l) && (((ptwo x) * (pth y)) <= r))
    then 1
    else 0

solveY :: Integer -> Integer -> Integer -> Integer -> Int

solveY l r x y = 
    if y > 20 then 0
    else (solveY l r x (y + 1)) + (check l r x y)

solveX :: Integer -> Integer -> Integer -> Int

solveX l r x = 
    if x > 32 then 0
    else (solveX l r (x + 1)) + (solveY l r x 0)

main = do
    input <- getLine
    let keks = Spl.splitOn " " input
    let l =  read (keks !! 0) :: Integer
    let r =  read (keks !! 1) :: Integer
    print $ solveX l r 0