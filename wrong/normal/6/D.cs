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
        static int sol, n, a, b;
        static int[] best, cnt, h;

        static void dfs(int x, int s)
        {
            if (s >= sol) return;
            if (x == n - 2)
            {
                int c = 0;
                while (h[x] - c * a > 0 || h[x + 1] - c * b > 0 || h[x - 1] - c * b > 0)
                    c++;
                cnt[x] = c;
                if (s + c < sol)
                {
                    sol = s + c;
                    for (int i = 0; i < n; ++i)
                        best[i] = cnt[i];
                }
                return;
            }
            int lo = 0;
            while (h[x - 1] - lo * b > 0) lo++;
            for (int c = lo; ; ++c)
            {
                if (c > 0 && h[x - 1] - (c - 1) * b <= 0 && h[x] - (c - 1) * a <= 0 && h[x + 1] - (c - 1) * b <= 0)
                    break;
                h[x - 1] -= c * b;
                h[x] -= c * a;
                h[x + 1] -= c * b;
                cnt[x] = c;
                dfs(x + 1, s + c);
                h[x - 1] += c * b;
                h[x] += c * a;
                h[x + 1] += c * b;
            }
        }

        static void Main(string[] args)
        {
            n = Reader.NextInt();
            a = Reader.NextInt();
            b = Reader.NextInt();

            h = new int[n];
            for (int i = 0; i < n; ++i)
                h[i] = Reader.NextInt() + 1;

            int cnt1 = 0, cnt2 = 0;
            while (h[0] > 0)
            {
                h[0] -= b;
                h[1] -= a;
                h[2] -= b;
                cnt1++;
            }
            while (h[n - 1] > 0)
            {
                h[n - 1] -= b;
                h[n - 2] -= a;
                h[n - 3] -= b;
                cnt2++;
            }

            best = new int[n];
            cnt = new int[n];
            sol = 1000;
            dfs(1, 0);

            best[1] += cnt1;
            best[n - 2] += cnt2;
            Console.WriteLine(sol + cnt1 + cnt2);
            for (int i = 1; i <= n - 2; ++i)
                for (int j = 0; j < best[i]; ++j)
                    Console.Write("{0} ", i + 1);
            Console.WriteLine("");
        }
    }
}