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
                p10 *= 0.1;
            }

            return ret;
        }

        public static string NextToken()
        {
            StringBuilder ret = new StringBuilder();
            char c;

            while (char.IsWhiteSpace(c = (char)Console.Read())) ;
            do
            {
                ret.Append(c);
            } while (!char.IsWhiteSpace(c = (char)Console.Read()));

            return ret.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int[] x, y;

            x = new int[3];
            y = new int[3];
            for (int i = 0; i < 3; ++i)
            {
                x[i] = Reader.NextInt();
                y[i] = Reader.NextInt();
            }

            Func<int, int, int> sqdist =
                (a, b) => (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
            Func<bool> check =
                () =>
                {
                    var d = Enumerable.Range(0, 3)
                        .Select(i => sqdist(i, (i + 1) % 3))
                        .OrderBy(t => t);
                    return d.ElementAt(0) != 0 && d.Take(2).Sum() == d.ElementAt(2);
                };

            if (check())
            {
                Console.WriteLine("RIGHT");
                return;
            }
            else
            {
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = -1; j <= 1; ++j)
                    {
                        x[i] += j;
                        if (check())
                        {
                            Console.WriteLine("ALMOST");
                            return;
                        }
                        x[i] -= j;

                        y[i] += j;
                        if (check())
                        {
                            Console.WriteLine("ALMOST");
                            return;
                        }
                        y[i] -= j;
                    }
                }
            }

            Console.WriteLine("NEITHER");
        }
    }
}