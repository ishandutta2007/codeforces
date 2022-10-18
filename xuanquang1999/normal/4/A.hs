waturrmelon :: Integer -> String
waturrmelon n = 
  if (n `mod` 2) == 0 && n > 2 then "YES" else "NO"

main = do
  line <- getLine
  let n = read line :: Integer
  putStrLn (waturrmelon n)