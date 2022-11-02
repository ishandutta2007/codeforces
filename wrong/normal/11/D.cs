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
    }

    class Program
    {
        static void Main(string[] args)
        {
            int n, m;

            n = Reader.NextInt();
            m = Reader.NextInt();

            bool[,] graph = new bool[n, n];
            for (int i = 0; i < m; ++i)
            {
                int a, b;

                a = Reader.NextInt() - 1;
                b = Reader.NextInt() - 1 ;
                graph[a, b] = graph[b, a] = true;
            }

            long[,] dp = new long[1 << n, n];
            for (int i = 0; i < n; ++i)
                dp[1 << i, i] = 1;

            for (int visit = 0; visit < (1 << n); ++visit)
            {
                for (int last = 0; last < n; ++last)
                {
                    if (dp[visit, last] == 0)
                        continue;

                    int next = 0;
                    while ((visit & (1 << next)) == 0)
                        next++;

                    for (; next < n; ++next)
                        if (graph[last, next] && (visit & (1 << next)) == 0)
                            dp[visit | (1 << next), next] += dp[visit, last];
                }
            }

            long res = 0;
            for (int visit = 0; visit < (1 << n); ++visit)
            {
                int cnt = 0;
                for (int i = 0; i < n; ++i)
                    if ((visit & (1 << i)) != 0)
                        cnt++;

                if (cnt >= 3)
                {
                    int first = 0;
                    while ((visit & (1 << first)) == 0)
                        first++;

                    for (int last = 0; last < n; ++last)
                        if (graph[last, first])
                            res += dp[visit, last];
                }
            }

            Console.WriteLine(res / 2);
        }
    }
}