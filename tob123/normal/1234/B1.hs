import Data.Set (Set)
import qualified Data.Set as Set

inputArr = do
  line <- getLine
  let ar = map read (words line) :: [Int]
  return ar

sim cur cur2 st [] rem = cur ++ (reverse cur2)
sim [] [] st (x:xs) rem = sim [] [x] (Set.insert x st) xs (rem-1)
sim (c:cs) [] st xs rem = sim [] (reverse (c:cs)) st xs rem
sim cur (c:cs) st (x:xs) rem
  | Set.member x st = sim cur (c:cs) st xs rem
  | rem > 0 = sim (x:cur) (c:cs) (Set.insert x st) xs (rem-1)
  | otherwise = sim (x:cur) cs newSt xs rem
      where newSt = Set.insert x (Set.delete c st)

main = do
  [n,k] <- inputArr
  a <- inputArr
  let res = sim [] [] Set.empty a k
  putStrLn (show (length res))
  putStrLn (concat (map ((++ " ") . show) res))