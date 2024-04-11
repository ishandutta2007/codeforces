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
        static long[,] memo;
        static bool[,] done;

        static long Rec(int n, int h)
        {
            if (n <= 1 && n == h)
                return 1;
            if (n < h)
                return 0;
            if (done[n, h])
                return memo[n, h];

            long ret = 0;
            for (int i = 1; i <= n; ++i)
            {
                int l = i - 1, r = n - i;
                for (int lh = 0; lh < h - 1; ++lh)
                    ret += Rec(l, lh) * Rec(r, h - 1);
                for (int rh = 0; rh <= h - 1; ++rh)
                    ret += Rec(l, h - 1) * Rec(r, rh);
            }
            done[n, h] = true;
            return memo[n, h] = ret;
        }

        static void Main(string[] args)
        {
            int n = Reader.NextInt(), h = Reader.NextInt();

            memo = new long[36, 36];
            done = new bool[36, 36];

            long sol = 0;
            for (int i = h; i <= n; ++i)
                sol += Rec(n, i);
            Console.WriteLine(sol);
        }
    }
}