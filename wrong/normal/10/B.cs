using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeForces
{
    static class Reader
    {
        public static int NextInt()
        {
            int ret = 0;
            char c;

            while (!char.IsDigit(c = (char)Console.Read()))
            {
                if (c == '-')
                    return -NextInt();
            }
            do
            {
                ret = ret * 10 + c - '0';
            } while (char.IsDigit(c = (char)Console.Read()));

            return ret;
        }

        public static double NextDouble()
        {
            double ret = 0;
            char c;

            while (!char.IsDigit(c = (char)Console.Read())) 
            {
                if (c == '-')
                    return -NextDouble();
            }
            do
            {
                ret = ret * 10 + c - '0';
            } while (char.IsDigit(c = (char)Console.Read()));
            if (c != '.') return ret;

            double p10 = 0.1;
            while (char.IsDigit(c = (char)Console.Read()))
            {
                ret += p10 * (c - '0');
            }

            return ret;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int N, K, C;
            N = Reader.NextInt();
            K = Reader.NextInt();
            C = (K + 1) / 2;

            int[,] S = new int[K + 2, K + 2];
            for (int i = 0; i < N; ++i)
            {
                int M = Reader.NextInt();
                int best = int.MaxValue, by = -1, bx = -1;

                for (int y = 1; y <= K; ++y)
                {
                    int ys = Math.Abs(y - C) * M;
                    int xs = 0;

                    for (int x = 1; x <= M; ++x)
                        xs += Math.Abs(x - C);
                    for (int x = M + 1; x <= K + 1; ++x)
                    {
                        if (S[y, x - 1] - S[y, x - M - 1] == 0 && best > xs + ys)
                        {
                            best = xs + ys;
                            by = y;
                            bx = x - M;
                        }
                        xs = xs - Math.Abs(x - M - C) + Math.Abs(x - C);
                    }
                }

                if (best == int.MaxValue)
                    Console.WriteLine("-1");
                else
                {
                    Console.WriteLine("{0} {1} {2}", by, bx, bx + M - 1);
                    for (int x = bx; x <= K; ++x)
                        S[by, x] += Math.Min(M, x - bx + 1);
                }
            }
        }
    }
}