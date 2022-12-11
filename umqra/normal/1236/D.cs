using System;
using System.Collections.Generic;
using System.Linq;

namespace D
{
    class D
    {
        private const int UP = 0;
        private const int RIGHT = 1;
        private const int DOWN = 2;
        private const int LEFT = 3;

        static int Go(int direction, int source, int[] obstacles, int minBound, int maxBound)
        {
            if (direction == RIGHT || direction == DOWN)
            {
                if (obstacles == null)
                    return maxBound - 1;
                var result = ~Array.BinarySearch(obstacles, 0, obstacles.Length, source);
                return result == obstacles.Length ? maxBound - 1 : Math.Min(obstacles[result] - 1, maxBound - 1);
            }
            else
            {
                if (obstacles == null)
                    return minBound + 1;
                var result = ~Array.BinarySearch(obstacles, 0, obstacles.Length, source);
                return result == 0 ? minBound + 1 : Math.Max(obstacles[result - 1] + 1, minBound + 1);
            }
        }

        static bool Solve(int n, int m, int k, int[][] rows, int[][] columns)
        {
            long cellsToVisit = n * (long) m - k - 1;
            int minX = 0, minY = -1, maxX = n, maxY = m;
            int currentX = 0, currentY = 0;
            int direction = ((rows[0] == null || rows[0][0] > 1) && m > 1) ? RIGHT : DOWN;
            while (cellsToVisit > 0)
            {
                if (direction == RIGHT || direction == LEFT)
                {
                    var nextY = Go(direction, currentY, rows[currentX], minY, maxY);
                    if (nextY <= minY || nextY >= maxY || nextY == currentY)
                        return false;
                    cellsToVisit -= Math.Abs(nextY - currentY);
                    currentY = nextY;
                    if (direction == RIGHT)
                        maxY = currentY;
                    else
                        minY = currentY;
                }
                else
                {
                    var nextX = Go(direction, currentX, columns[currentY], minX, maxX);
                    if (nextX <= minX || nextX >= maxX || nextX == currentX)
                        return false;
                    cellsToVisit -= Math.Abs(nextX - currentX);
                    currentX = nextX;
                    if (direction == DOWN)
                        maxX = currentX;
                    else
                        minX = currentX;
                }

                direction = (direction + 1) % 4;
            }

            return cellsToVisit == 0;
        }

        static void Main(string[] args)
        {
            var tokens = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var n = tokens[0];
            var m = tokens[1];
            var k = tokens[2];
            var rows = new int[n][];
            var columns = new int[m][];
            var cells = new List<(int X, int Y)>();
            for (int i = 0; i < k; i++)
            {
                var coords = Console.ReadLine().Split().Select(int.Parse).ToArray();
                cells.Add((coords[0] - 1, coords[1] - 1));
            }

            foreach (var group in cells.GroupBy(x => x.X))
                rows[group.Key] = group.Select(x => x.Y).OrderBy(x => x).ToArray();
            foreach (var group in cells.GroupBy(x => x.Y))
                columns[group.Key] = group.Select(x => x.X).OrderBy(x => x).ToArray();
            Console.WriteLine(Solve(n, m, k, rows, columns) ? "Yes" : "No");
        }
    }
}