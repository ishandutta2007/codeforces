import Data.Int

modadd :: Int -> Int -> Int -> Int
modadd m lhs rhs = if t < m then t else t - m
	where
		t = lhs + rhs

modsub :: Int -> Int -> Int -> Int
modsub m lhs rhs = if t >= 0 then t else t + m
	where
		t = lhs - rhs

modmul :: Int -> Int -> Int -> Int
modmul m lhs rhs = fromIntegral $ t `mod` fromIntegral m
	where
		t = (fromIntegral lhs * fromIntegral rhs) :: Int64

exgcd :: Int -> Int -> (Int, Int, Int)
exgcd a 0 = (1, 0, a)
exgcd a b = (y, (x - (a `div` b) * y), d)
	where
		(x, y, d) = exgcd b (a `mod` b)

modrev :: Int -> Int -> Int
modrev m a
	| d == 1    = if y >= 0 then y else y + m
	| otherwise = error $ show m ++ " and " ++ show a ++ " are not coprime."
	where
		(x, y, d) = exgcd m a

moddiv :: Int -> Int -> Int -> Int
moddiv m lhs rhs = modmul m lhs (modrev m rhs)

binom :: Int -> Int -> Int -> Int
binom m n k = moddiv m a b
	where
		a = foldl (modmul m) 1 [n - k + 1 .. n]
		b = foldl (modmul m) 1 [1 .. k]

calc :: Int -> Int -> Int -> Int
calc n 0 g = if (n - 1) `mod` 2 == g then 1 else 0
calc n 1 g = (length . filter (\k -> (k - 1) `mod` 2 == g)) [1 .. n] + if (n + 1) `mod` 2 == g then 1 else 0
calc n m g = foldl (modadd modNum) 0 $ zipWith (modmul modNum) isGL binomL
	where
		modNum = 1000000007
		isGL   = [if k `mod` 2 == g then 1 else 0 | k <- [0 .. n]]
		binomL = binom modNum (n + m - 1) (m - 1) : (zipWith nextBinom [0 .. ] binomL)
		nextBinom k x = modmul modNum x (moddiv modNum (n - k) (n + m - k - 1))

handle :: [String] -> [[String]]
handle [sn, sm, sg] = [[show $ calc (read sn) (read sm) (read sg)]]

main :: IO ()
main = interact $ unlines . map unwords . handle . words