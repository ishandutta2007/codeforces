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
            double[,] p = new double[n, n];

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    p[i, j] = Reader.NextDouble();

            double[] dp = new double[1 << n];

            dp[(1 << n) - 1] = 1;
            for (int i = (1 << n) - 1; i >= 0; --i)
            {
                int b = 0;
                for (int j = 0; j < n; ++j)
                    if ((i & (1 << j)) != 0)
                        b++;
                for (int j = 0; j < n; ++j)
                    if ((i & (1 << j)) != 0)
                        for (int k = 0; k < n; ++k)
                            if ((i & (1 << k)) != 0)
                                dp[i ^ (1 << k)] += dp[i] * p[j, k] / (b * (b - 1) / 2);
            }

            for (int i = 0; i < n; ++i)
                Console.Write("{0:f7} ", dp[1 << i]);
            Console.WriteLine();
        }
    }
}