handle = do
	line <- getLine
	l2 <- getLine
	let n = read line :: Int
	let ar = map read (words l2) :: [Int]
	let s = sum ar
	let res = (s+n-1) `div` n
	putStrLn (show res)

handleCase 0 = return ()
handleCase n = do
	handle
	handleCase (n-1)
	

main = do
	lineq <- getLine
	let q = (read lineq :: Int)
	handleCase q
	{-
	line2 <- getLine
	let n = (read line :: Int)
	let x = n+1
	let s = show x
	let z = words line2
	let ar = map read z :: [Int]
	let s2 = map (show . (+ 1)) ar
	putStrLn s
	putStrLn (concat s2) -}