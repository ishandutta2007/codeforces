import Data.List
import Control.Monad
import Data.IntMap.Strict (IntMap)
import qualified Data.IntMap.Strict as IntMap


listMap = Data.List.map

inputNum = do
  line <- getLine
  return ((read line) :: Int)

inputArr = do
  line <- getLine
  let ar = listMap read (words line) :: [Int]
  return ar

buildGraph p = IntMap.fromList res1
  where res1 = listMap (\(ind, x) -> (ind, (x-1, False))) (zip [0..((length p) - 1)] p)

dfs cur to g m s
  | cur == to = (IntMap.adjust (\(n, vis) -> (n, True)) cur g, IntMap.insert cur s m)
  | otherwise = let
                  nxt = (fst (g IntMap.! cur))
                  (newG, newM) = dfs nxt to g m (s+1)
                in (IntMap.adjust (\(n, vis) -> (n, True)) cur newG, IntMap.insert cur (newM IntMap.! nxt) newM)


dfsAll (-1) graph m = m
dfsAll ind graph m
  | vis = dfsAll (ind-1) graph m
  | otherwise = let
                  (nxtG, nxtM) = dfs (fst (graph IntMap.! ind)) ind graph m 1
                in dfsAll (ind-1) nxtG nxtM
    where (nxt, vis) = graph IntMap.! ind

solveCase = do
  n <- inputNum
  p <- inputArr
  let graph = buildGraph p
  let res = dfsAll (n-1) graph (IntMap.fromList [])
  let erg1 = listMap ((' ':) . show) (listMap snd (IntMap.toList res))
  let (_:erg) = concat erg1
  putStrLn erg

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