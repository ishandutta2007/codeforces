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
        const int SQRT_N = 320;

        static int n, m;
        static int[] jump, next, cnt;

        static void Update(int l, int p)
        {
            int r = l + SQRT_N;
            for (int i = Math.Min(r, p) - 1; i >= l; --i)
            {
                if (i < jump[i] && jump[i] < r)
                {
                    next[i] = next[jump[i]];
                    cnt[i] = cnt[jump[i]] + 1;
                }
                else
                {
                    next[i] = jump[i];
                    cnt[i] = 1;
                }
            }
        }


        static void Main(string[] args)
        {
            n = Reader.NextInt();
            m = Reader.NextInt();

            jump = new int[n + 1];
            next = new int[n + 1];
            cnt = new int[n + 1];

            for (int i = 0; i < n; ++i)
            {
                jump[i] = Reader.NextInt() + i;
                if (jump[i] >= n)
                    jump[i] = i;
            }

            for (int i = 0; i < n; i += SQRT_N)
                Update(i, n);

            for (int i = 0; i < m; ++i)
            {
                int a, b;

                if (Reader.NextInt() == 0)
                {
                    a = Reader.NextInt() - 1;
                    b = Reader.NextInt();

                    jump[a] = a + b;
                    if (jump[a] >= n)
                        jump[a] = a;
                    Update(a / SQRT_N * SQRT_N, a + 1);
                }
                else
                {
                    int ans = 0;

                    a = Reader.NextInt() - 1;
                    for (int pos = a / SQRT_N * SQRT_N; ; pos = a / SQRT_N * SQRT_N)
                    {
                        ans += cnt[a];
                        a = next[a];
                        if (a < pos + SQRT_N)
                            break;
                    }

                    Console.WriteLine("{0} {1}", a + 1, ans);
                }
            }
        }
    }
}