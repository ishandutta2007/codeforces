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
        static long ExtGCD(long a, long b, out long x, out long y)
        {
            long g = a;
            x = 1;
            y = 0;
            if (b != 0)
            {
                g = ExtGCD(b, a % b, out y, out x);
                y -= (a / b) * x;
            }
            return g;
        }

        static void Main(string[] args)
        {
            int A, B, C;

            A = Reader.NextInt();
            B = Reader.NextInt();
            C = Reader.NextInt();

            long x, y, g;
            g = ExtGCD(A, B, out x, out y);

            if (C % g != 0)
            {
                Console.WriteLine(-1);
            }
            else
            {
                Console.WriteLine("{0} {1}", x * (-C / g), y * (-C / g));
            }
        }
    }
}