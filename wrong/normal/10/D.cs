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
            int n, m;
            int[] A, B;

            n = Reader.NextInt();
            A = new int[n];
            for (int i = 0; i < n; ++i)
                A[i] = Reader.NextInt();

            m = Reader.NextInt();
            B = new int[m];
            for (int i = 0; i < m; ++i)
                B[i] = Reader.NextInt();

            int[,] max, prev, dp;
            max = new int[n, m];
            prev = new int[n, m];
            dp = new int[n, m];

            for (int j = 0; j < m; ++j)
            {
                max[0, j] = dp[0, j] = (A[0] == B[j] ? 1 : 0);
                if (j > 0)
                    max[0, j] = Math.Max(max[0, j], max[0, j - 1]);
                prev[0, j] = -1;
            }

            for (int i = 1; i < n; ++i)
            {
                max[i, 0] = dp[i, 0] = (A[i] == B[0] ? 1 : 0);
                prev[i, 0] = -1;

                for (int j = 1; j < m; ++j)
                {
                    if (A[i] != B[j])
                        continue;
                    dp[i, j] = 1;
                    prev[i, j] = -1;

                    for (int k = 0; k < i; ++k)
                    {
                        if (A[k] < A[i] && dp[i, j] < max[k, j - 1] + 1)
                        {
                            dp[i, j] = max[k, j - 1] + 1;
                            prev[i, j] = k;
                        }
                    }
                }

                for (int j = 1; j < m; ++j)
                    max[i, j] = Math.Max(max[i, j - 1], dp[i, j]);
            }

            int mi = -1, mj = -1, sol = -1;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (sol < dp[i, j])
                    {
                        sol = dp[i, j];
                        mi = i;
                        mj = j;
                    }
                }
            }

            int[] seq = new int[sol];
            for (int s = sol - 1; s >= 0; --s)
            {
                seq[s] = A[mi];
                mi = prev[mi, mj];
                if (s == 0)
                    break;
                for (int j = 0; j < mj; ++j)
                    if (dp[mi, j] == s)
                        mj = j;
            }

            Console.WriteLine(sol);
            Console.WriteLine(string.Join(" ", Array.ConvertAll(seq, Convert.ToString)));
        }
    }
}