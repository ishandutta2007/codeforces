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
            int n, t;

            n = Reader.NextInt();
            t = Reader.NextInt();
            long[, , , ,] dp = new long[n, 4, 4, t + 2, t + 2];

            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if(i != j)
                        dp[1, i, j, 0, 0] = 1;
            for (int i = 2; i < n; ++i)
                for (int j = 0; j < 4; ++j)
                    for (int k = 0; k < 4; ++k)
                        if (j != k)
                            for (int l = 0; l <= t; ++l)
                                for (int m = 0; m <= t; ++m)
                                    for (int y = 0; y < 4; ++y)
                                        if (k != y)
                                            if (j < k && k > y)
                                                dp[i, k, y, l + 1, m] += dp[i - 1, j, k, l, m];
                                            else if (j > k && k < y)
                                                dp[i, k, y, l, m + 1] += dp[i - 1, j, k, l, m];
                                            else
                                                dp[i, k, y, l, m] += dp[i - 1, j, k, l, m];

            long sol = 0;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if (i != j)
                        sol += dp[n - 1, i, j, t, t - 1];

            Console.WriteLine(sol);
        }
    }
}