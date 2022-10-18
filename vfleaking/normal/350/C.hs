import Data.List
import Data.Maybe
import Data.Ord
import qualified Data.ByteString as ByteString
import qualified Data.ByteString.Char8 as Char8

readInt :: Char8.ByteString -> Int
readInt = fst . fromJust . Char8.readInt

calc :: [(Int, Int)] -> [[String]]
calc [] = []
calc ((x, y) : xs) = goX ++ goY ++ [["2"]] ++ backX ++ backY ++ [["3"]] ++ calc xs
	where
		goX
			| x < 0 = [["1", show (-x), "L"]]
			| x > 0 = [["1", show x, "R"]]
			| otherwise = []
		goY
			| y < 0 = [["1", show (-y), "D"]]
			| y > 0 = [["1", show y, "U"]]
			| otherwise = []
		backX
			| x < 0 = [["1", show (-x), "R"]]
			| x > 0 = [["1", show x, "L"]]
			| otherwise = []
		backY
			| y < 0 = [["1", show (-y), "U"]]
			| y > 0 = [["1", show y, "D"]]
			| otherwise = []

zipXY :: [Int] -> [(Int, Int)]
zipXY [] = []
zipXY (x : y : xs) = (x, y) : zipXY xs

handle :: [Char8.ByteString] -> [[String]]
handle (_ : xs) = [show $ length res] : res
	where
		px = sortBy (comparing (\(x, y) -> (abs x) + (abs y))) $ zipXY $ map readInt xs
		res = calc px

main :: IO ()
main = do
	input <-ByteString.getContents
	putStr $ unlines $ map unwords $ handle $ Char8.words input