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
            int m = Reader.NextInt();
            int sol = 0;

            int[] deg = new int[n];
            int[,] adj = new int[n, n];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    adj[i, j] = i == j ? 0 : int.MaxValue / 2;

            for (int i = 0; i < m; ++i)
            {
                int x, y, w;

                x = Reader.NextInt() - 1;
                y = Reader.NextInt() - 1;
                w = Reader.NextInt();

                adj[x, y] = adj[y, x] = Math.Min(adj[x, y], w);
                deg[x]++;
                deg[y]++;
                sol += w;
            }

            for (int k = 0; k < n; ++k)
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        adj[i, j] = Math.Min(adj[i, j], adj[i, k] + adj[k, j]);

            for (int i = 1; i < n; ++i)
            {
                if (deg[i] > 0 && adj[0, i] == int.MaxValue / 2)
                {
                    Console.WriteLine(-1);
                    return;
                }
            }

            List<int> o = new List<int>();
            for (int i = 0; i < n; ++i)
                if (deg[i] % 2 == 1)
                    o.Add(i);

            int v = o.Count;
            int[] dp = new int[1 << v];

            for (int i = 1; i < (1 << v); ++i)
                dp[i] = int.MaxValue / 2;

            for (int i = 1; i < (1 << v); ++i)
            {
                int j = 0;

                while ((i & (1 << j)) == 0)
                    ++j;
                for (int k = j + 1; k < v; ++k)
                    if ((i & (1 << k)) != 0)
                        dp[i] = Math.Min(dp[i], dp[i ^ (1 << k) ^ (1 << j)] + adj[o[j], o[k]]);
            }

            Console.WriteLine(sol + dp[(1 << v) - 1]);
        }
    }
}