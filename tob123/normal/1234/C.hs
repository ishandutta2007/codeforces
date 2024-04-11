import Data.Char (isDigit)
import Data.Set (Set)
import qualified Data.Set as Set

inputNum = do
  line <- getLine
  return ((read line) :: Int)

inputArr = do
  line <- getLine
  let ar = ((map (\x -> read [x]) line) :: [Int])
  return ar

solve3 (_, b) [] [] = b
solve3 (p1, p2) (a:r1) (b:r2) = solve3 (newp1, newp2) r1 r2
  where newp1 = (p1 && (a==1)) || (p2 && (a==2) && (b==2))
        newp2 = (p2 && (b==1)) || (p1 && (a==2) && (b==2))

solve = do
  n <- inputNum
  r1 <- inputArr
  r2 <- inputArr
  let f x = map (\z -> if z<3 then 1 else 2) x
  let pos = solve3 (True, False) (f r1) (f r2)
  putStrLn (if pos then "YES" else "NO")

solveCases 0 = return ()
solveCases q = do
  solve
  solveCases (q-1)

main = do
  q <- inputNum
  solveCases q