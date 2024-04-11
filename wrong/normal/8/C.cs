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
        static int xs, ys, n;
        static int[] x, y, memo;
        static int[,] d, take;

        static int SquaredDist(int dx, int dy)
        {
            return dx * dx + dy * dy;
        }

        static int Rec(int mask, int cur)
        {
            if (mask == 0)
                return 0;
            if ((mask & (1 << cur)) == 0)
                return Rec(mask, cur + 1);
            if (memo[mask] > 0)
                return memo[mask];

            int opt = int.MaxValue;
            for (int i = cur; i < n; ++i)
            {
                if ((mask & (1 << i)) != 0)
                {
                    int tmp = Rec(mask ^ ((1 << cur) | (1 << i)), cur + 1) + d[cur, i];
                    if (opt > tmp)
                    {
                        opt = tmp;
                        take[mask, 0] = cur;
                        take[mask, 1] = i;
                    }
                }
            }

            return memo[mask] = opt;
        }

        static void Main(string[] args)
        {
            xs = Reader.NextInt();
            ys = Reader.NextInt();
            n = Reader.NextInt();

            x = new int[n];
            y = new int[n];
            d = new int[n, n];
            for (int i = 0; i < n; ++i)
            {
                x[i] = Reader.NextInt();
                y[i] = Reader.NextInt();
            }

            for (int i = 0; i < n; ++i)
            {
                d[i, i] = 2 * SquaredDist(x[i] - xs, y[i] - ys);
                for (int j = i + 1; j < n; ++j)
                    d[i, j] = d[j, i] = SquaredDist(x[i] - xs, y[i] - ys) + SquaredDist(x[i] - x[j], y[i] - y[j]) + SquaredDist(x[j] - xs, y[j] - ys);
            }

            memo = new int[1 << n];
            take = new int[1 << n, 2];
            
            Console.WriteLine(Rec((1 << n) - 1, 0));

            int state = (1 << n) - 1;
            List<int> way = new List<int>();
            way.Add(0);
            while (state > 0)
            {
                int t1 = take[state, 0], t2 = take[state, 1];
                way.Add(t1 + 1);
                if (t1 != t2)
                    way.Add(t2 + 1);
                way.Add(0);
                state ^= (1 << t1) | (1 << t2);
            }

            for (int i = 0; i < way.Count; ++i)
                Console.Write("{0} ", way[i]);
            Console.WriteLine("");
        }
    }
}