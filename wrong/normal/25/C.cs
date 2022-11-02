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
            int n = Reader.NextInt();
            int[,] d = new int[n, n];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i, j] = Reader.NextInt();

            int q = Reader.NextInt();
            long[] sol = new long[q];
            for (int i = 0; i < q; ++i)
            {
                int a, b, c;

                a = Reader.NextInt() - 1;
                b = Reader.NextInt() - 1;
                c = Reader.NextInt();

                if (d[a, b] > c)
                {
                    d[a, b] = d[b, a] = c;
                    for (int j = 0; j < n; ++j)
                        for (int k = 0; k < n; ++k)
                            d[j, k] = Math.Min(d[j, k], Math.Min(d[j, a] + d[a, b] + d[b, k], d[j, b] + d[b, a] + d[a, k]));
                }

                for (int j = 0; j < n; ++j)
                    for (int k = j + 1; k < n; ++k)
                        sol[i] += d[j, k];
            }

            Console.WriteLine(string.Join(" ", sol.Select(x => x.ToString()).ToArray()));
        }
    }
}