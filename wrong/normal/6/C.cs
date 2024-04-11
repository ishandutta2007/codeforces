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
            int n = Reader.NextInt();
            int[] t = new int[n];

            for (int i = 0; i < n; ++i)
                t[i] = Reader.NextInt();

            int a = 0, b = 0, ai = 0, bi = n - 1;
            while (ai <= bi)
            {
                if (ai == bi)
                {
                    a++;
                    break;
                }
                int c = Math.Min(t[ai], t[bi]);
                t[ai] -= c;
                t[bi] -= c;
                if (t[ai] == 0 && t[bi] == 0 && ai + 1 == bi - 1)
                {
                    a += 2;
                    b++;
                    break;
                }
                if (t[ai] == 0)
                {
                    a++;
                    ai++;
                    if (ai == bi)
                    {
                        b++;
                        break;
                    }
                }
                if (t[bi] == 0)
                {
                    b++;
                    bi--;
                    if (ai == bi)
                    {
                        a++;
                        break;
                    }
                }
            }
            Console.WriteLine("{0} {1}", a, b);
        }
    }
}