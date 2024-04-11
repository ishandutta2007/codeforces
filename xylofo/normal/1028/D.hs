--import Debug.Trace
import qualified Data.ByteString.Char8 as B
import Control.Applicative
import Control.Arrow
import Control.Monad
import Data.List
import Data.Int
import Data.Maybe
import Data.Set (Set)
import qualified Data.Set as S

newtype Mod = M Int64 deriving(Show,Eq)
md a = M $ mod a 1000000007
instance Num Mod where
  (M a) + (M b) = md $ a + b
  (M a) * (M b) = md $ a * b
  negate (M a) = md $ negate a
  fromInteger = md . fromInteger
  signum _ = md 1
  abs x = x

main = do
  n <- lineInt
  ins <- replicateM n lineIns
  let (M ans) = doIns ins S.empty S.empty S.empty
  print ans

doIns :: [(Int,X)] -> Set Int -> Set Int -> Set Int -> Mod
doIns [] _ _ uk = 1 + fromIntegral (S.size uk)
doIns ((x, Add):rest) sell buy uk = doIns rest nsell nbuy nuk -- ## [nsell,nbuy,nuk]
  where s = maybe False (<x) $ lookupMin sell
        b = maybe False (>x) $ lookupMax buy
        nsell = if s then S.insert x sell else sell
        nbuy = if b then S.insert x buy else buy
        nuk = if not s && not b then S.insert x uk else uk

doIns ((x, Accept):rest) sell buy uk = y * doIns rest nsell nbuy nuk -- ## [nsell,nbuy,nuk]
  where s = maybe False (<x) $ lookupMin sell
        b = maybe False (>x) $ lookupMax buy
        ss = (== Just x) $ lookupMin sell
        bb = (== Just x) $ lookupMax buy
        uu = not bb && not ss && S.member x uk
        (addbuy, addsell) = S.split x uk
        nsell = if ss then S.deleteMin sell else S.union sell addsell
        nbuy  = if bb then S.deleteMax buy  else S.union buy  addbuy
        nuk = S.empty
        y | s  || b   = 0
          | ss || bb  = 1
          | uu        = 2
          | otherwise = 0

lookupMin = S.lookupGE 0
lookupMax = S.lookupLE 1000000000


data X = Accept | Add

lineIns = do
  [a,b] <- B.words <$> B.getLine
  return (readInt b, if a == B.pack "ADD" then Add else Accept)

readInt = fst . fromJust . B.readInt
lineInt = readInt <$> B.getLine
lineInts = map readInt . B.words <$> B.getLine

--infixr 0 ##
--(##) x msg = traceShow msg x