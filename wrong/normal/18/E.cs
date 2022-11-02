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
            int n, m;

            n = Reader.NextInt();
            m = Reader.NextInt();

            string[] F = new string[n];
            for (int i = 0; i < n; ++i)
                F[i] = Reader.NextToken();

            int[, ,] cost = new int[n, 26, 26];
            for (int i = 0; i < n; ++i)
            {
                int[,] cost_ch = new int[2, 26];

                for (int j = 0; j < m; ++j)
                    for (int k = 0; k < 26; ++k)
                        if (F[i][j] != 'a' + k)
                            cost_ch[j % 2, k]++;

                for (int j = 0; j < 26; ++j)
                    for (int k = 0; k < 26; ++k)
                        cost[i, j, k] = cost_ch[0, j] + cost_ch[1, k];
            }

            int[, ,] dp = new int[n, 26, 26];
            int[, , ,] prev = new int[n, 26, 26, 2];

            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                    if (i != j)
                        dp[0, i, j] = cost[0, i, j];
            for (int i = 1; i < n; ++i)
            {
                int best_a = 0, best_b = 1;

                for (int j = 0; j < 26; ++j)
                {
                    for (int k = 0; k < 26; ++k)
                    {
                        if (j != k && dp[i - 1, j, k] < dp[i - 1, best_a, best_b])
                        {
                            best_a = j;
                            best_b = k;
                        }
                    }
                }

                for (int j = 0; j < 26; ++j)
                {
                    for (int k = 0; k < 26; ++k)
                    {
                        if (j != k)
                        {
                            if (j != best_a && k != best_b)
                            {
                                dp[i, j, k] = dp[i - 1, best_a, best_b] + cost[i, j, k];
                                prev[i, j, k, 0] = best_a;
                                prev[i, j, k, 1] = best_b;
                            }
                            else
                            {
                                dp[i, j, k] = int.MaxValue;
                                for (int a = 0; a < 26; ++a)
                                {
                                    for (int b = 0; b < 26; ++b)
                                    {
                                        if (a != b && j != a && k != b && dp[i, j, k] > dp[i - 1, a, b])
                                        {
                                            dp[i, j, k] = dp[i - 1, a, b];
                                            prev[i, j, k, 0] = a;
                                            prev[i, j, k, 1] = b;
                                        }
                                    }
                                }

                                dp[i, j, k] += cost[i, j, k];
                            }
                        }
                    }
                }
            }

            int cur_a = 0, cur_b = 1;

            for (int i = 0; i < 26; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (i != j && dp[n - 1, i, j] < dp[n - 1, cur_a, cur_b])
                    {
                        cur_a = i;
                        cur_b = j;
                    }
                }
            }

            Console.WriteLine(dp[n - 1, cur_a, cur_b]);

            List<string> sol = new List<string>();
            for (int i = n - 1; i >= 0; --i)
            {
                string line = "";

                for (int j = 0; j < m; ++j)
                    line += (char)('a' + (j % 2 == 0 ? cur_a : cur_b));
                sol.Add(line);

                if (i == 0)
                    break;

                int next_a = prev[i, cur_a, cur_b, 0];
                int next_b = prev[i, cur_a, cur_b, 1];
                cur_a = next_a;
                cur_b = next_b;
            }

            sol.Reverse();
            foreach (string line in sol)
                Console.WriteLine(line);
        }
    }
}