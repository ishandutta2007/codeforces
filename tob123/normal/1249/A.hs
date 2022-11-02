import Data.List
import Control.Monad

inputNum = do
  line <- getLine
  return ((read line) :: Int)

inputArr = do
  line <- getLine
  let ar = map read (words line) :: [Int]
  return ar

solveRec [] = True
solveRec [x] = True
solveRec (a:b:xs) = b-a /= 1 && solveRec (b:xs)

solveCase = do
  n <- inputNum
  a <- inputArr
  let erg = if solveRec (sort a) then 1 else 2
  putStrLn (show erg)

main = do
  line <- getLine
  let n = (read line :: Int)
  replicateM_ n solveCase
  {-
  line2 <- getLine
  let x = n+1
  let s = show x
  let z = words line2
  let ar = map read z :: [Int]
  let s2 = map (show . (+ 1)) ar
  putStrLn s
  putStrLn (concat s2)
  -}