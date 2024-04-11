--import Debug.Trace
import qualified Data.ByteString.Char8 as B
import Control.Applicative
import Control.Arrow
import Control.Monad
import Data.List
import Data.Maybe

mx = 2000000000
mn = negate mx
large = [mn,mn,mx,mx]

main = do
  n <- lineInt
  rects <- replicateM n lineInts :: IO [[Int]]
  let pre = scanl int large rects
      suf = scanr int large rects
      both = zipWith int (large:pre) (suf ++ [large])
      ans = snd $ head $ filter (snd . second nempt) $ zip [1..] both
  putStrLn $ unwords $ map show $ take 2 ans

int a b = zipWith uncurry [max, max, min, min] $  zip a b
nempt [x1,y1,x2,y2] = x1 <= x2 && y1 <= y2



readInt = fst . fromJust . B.readInt
lineInt = readInt <$> B.getLine
lineInts = map readInt . B.words <$> B.getLine

--infixr 0 ##
--(##) x msg = traceShow msg x