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
        static int GCD(int n, int m)
        {
            return m == 0 ? n : GCD(m, n % m);
        }

        static void Main(string[] args)
        {
            int A = Reader.NextInt();
            int num = 0, den = 0;

            for (int b = 2; b < A; ++b)
            {
                den++;
                for (int t = A; t > 0; t /= b)
                    num += t % b;
            }

            int g = GCD(num, den);
            Console.WriteLine("{0}/{1}", num / g, den / g);
        }
    }
}