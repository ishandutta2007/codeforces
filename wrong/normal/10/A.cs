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
            int n, P1, P2, P3, T1, T2;

            n = Reader.NextInt();
            P1 = Reader.NextInt();
            P2 = Reader.NextInt();
            P3 = Reader.NextInt();
            T1 = Reader.NextInt();
            T2 = Reader.NextInt();

            int W = 0, last;
            int l, r;

            l = Reader.NextInt();
            r = Reader.NextInt();
            W += P1 * (r - l);
            last = r;

            for (int i = 1; i < n; ++i)
            {
                l = Reader.NextInt();
                r = Reader.NextInt();
                if (l - last <= T1)
                    W += P1 * (r - last);
                else if (l - last <= T1 + T2)
                    W += P1 * (r - l + T1) + P2 * (l - last - T1);
                else
                    W += P1 * (r - l + T1) + P2 * T2 + P3 * (l - last - T1 - T2);
                last = r;
            }
            Console.WriteLine(W);
        }
    }
}