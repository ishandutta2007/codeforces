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
            int n, x0, left = 0, right = 1000;

            n = Reader.NextInt();
            x0 = Reader.NextInt();
            
            for (int i = 0; i < n; ++i)
            {
                int a, b;

                a = Reader.NextInt();
                b = Reader.NextInt();
                left = Math.Max(left, Math.Min(a, b));
                right = Math.Min(right, Math.Max(a, b));
            }

            if (left > right)
                Console.WriteLine(-1);
            else if (left <= x0 && x0 <= right)
                Console.WriteLine(0);
            else
                Console.WriteLine(Math.Min(Math.Abs(left - x0), Math.Abs(right - x0)));
        }
    }
}