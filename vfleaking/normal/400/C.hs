data Point = Point Int Int

instance Show Point where
    show (Point x y) = (show x) ++ " " ++ (show y)

getPoints :: Int -> IO [Point]
getPoints 0 = return []
getPoints n = do
    sXY <- getLine
    let
        [x, y] = map read $ words sXY
    rest <- getPoints (n - 1)
    return ((Point x y) : rest)

operX :: Int -> (Int, Int, [Point]) -> (Int, Int, [Point])
operX 0 (n, m, po) = (n, m, po)
operX t (n, m, po) = operX (t - 1) (m, n, po')
    where
        po' = map (\(Point x y) -> Point y (n + 1 - x)) po

operY :: Int -> (Int, Int, [Point]) -> (Int, Int, [Point])
operY 0 (n, m, po) = (n, m, po)
operY t (n, m, po) = operY (t - 1) (n, m, po')
    where
        po' = map (\(Point x y) -> Point x (m + 1 - y)) po

operZ :: Int -> (Int, Int, [Point]) -> (Int, Int, [Point])
operZ 0 (n, m, po) = (n, m, po)
operZ t (n, m, po) = operZ (t - 1) (m, n, po')
    where
        po' = map (\(Point x y) -> Point (m + 1 - y) x) po

main :: IO ()
main = do
    sNMXYZP <- getLine
    let
        [n, m, x, y, z, p] = map read $ words sNMXYZP
    po <- getPoints p

    let
        (n', m', po') = ((operZ (z `mod` 4)) . (operY (y `mod` 2)) . (operX (x `mod` 4))) (n, m, po)
    putStr $ unlines $ map show po'