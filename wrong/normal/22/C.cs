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
            int n = Reader.NextInt();
            int m = Reader.NextInt();
            int v = Reader.NextInt();

            if (m < n - 1 || (m - n + 1) > ((long)n - 2) * (n - 3) / 2)
                Console.WriteLine(-1);
            else
            {
                List<int> w = new List<int>();

                for (int i = 1; i <= n; ++i)
                    if (i != v)
                        w.Add(i);

                m -= n - 1;
                for (int i = 0; i < n - 1; ++i)
                    Console.WriteLine("{0} {1}", w[i], v);

                for (int i = 1; m > 0 && i < n - 1; ++i)
                {
                    for (int j = i + 1; m > 0 && j < n - 1; ++j)
                    {
                        Console.WriteLine("{0} {1}", w[i], w[j]);
                        m--;
                    }
                }       
            }
        }
    }
}