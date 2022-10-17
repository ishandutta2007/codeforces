import Data.List (transpose)

-- Calculates the value of shortest route

shortest (i,j,0) g = g !! (i-1) !! (j-1) -- Transition value from graph
shortest (i,j,k) g = min (shortest (i,j,k-1) g) $
                         (shortest (i,k,k-1) g) + (shortest (k,j,k-1) g)

main = interact $ show . f . g . lines

g :: [[Char]]->(Int,[[Int]])
g (x:xs) = (read x, readGraph ( unlines xs))

f (n,x) = maximum [shortest (a,b,n) x | a<-[1..n], b<-[1..n]]


readGraph = str2int . map words . lines
str2int = map.map $ fromIntegral . (\xs -> read xs :: Int)