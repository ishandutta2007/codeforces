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
        static int[] MaxPath(List<int>[] e, int u, int p)
        {
            int[] next = new int[3];
            int[] ret = new int[2];

            foreach (int v in e[u])
            {
                if (v == p)
                    continue;

                int[] t = MaxPath(e, v, u);
                ret[0] = Math.Max(ret[0], t[0]);
                next[2] = t[1];
                Array.Sort(next);
                Array.Reverse(next);
            }

            ret[0] = Math.Max(ret[0], next[0] + next[1]);
            ret[1] = next[0] + 1;
            return ret;
        }

        static void Main(string[] args)
        {
            int n = Reader.NextInt();

            List<int>[] e = new List<int>[n];
            for (int i = 0; i < n; ++i)
                e[i] = new List<int>();

            for (int i = 0; i < n - 1; ++i)
            {
                int a, b;

                a = Reader.NextInt() - 1;
                b = Reader.NextInt() - 1;
                e[a].Add(b);
                e[b].Add(a);
            }

            int sol = 0;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < e[i].Count; ++j)
                {
                    int v = e[i][j];

                    sol = Math.Max(sol, MaxPath(e, i, v)[0] * MaxPath(e, v, i)[0]);
                }
            }

            Console.WriteLine(sol);
        }
    }
}