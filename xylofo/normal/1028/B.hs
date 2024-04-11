--import Debug.Trace
import qualified Data.ByteString.Char8 as B
import Control.Applicative
import Control.Arrow
import Control.Monad
import Data.List
import Data.Maybe

main = do
  let a = (10^2000 - 1) `div` 9
      b = 10^2000 - a
  print a
  print b



-- Below is template code
readInt = fst . fromJust . B.readInt
lineInt = readInt <$> B.getLine
lineInts = map readInt . B.words <$> B.getLine

--infixr 0 ##
--(##) x msg = traceShow msg x