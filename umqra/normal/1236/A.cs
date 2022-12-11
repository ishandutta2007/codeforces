using System;
using System.Linq;

namespace A
{
    public static class A
    {
        static int Solve(int[] sizes)
        {
            var result = 0;
            for (int i = 0; i <= sizes[0]; i++)
            {
                if (2 * i <= sizes[1])
                {
                    int a = sizes[1] - 2 * i;
                    int b = sizes[2];
                    int secondRound = Math.Min(a, b / 2);
                    result = Math.Max(result, 3 * i + 3 * secondRound);
                }
            }

            return result;
        }

        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                var sizes = Console.ReadLine().Split().Select(int.Parse).ToArray();
                Console.WriteLine(Solve(sizes));
            }
        }
    }
}