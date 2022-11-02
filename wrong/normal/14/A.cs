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
            int n, m;

            n = Reader.NextInt();
            m = Reader.NextInt();

            string[] s = new string[n];
            int xmin, xmax, ymin, ymax;

            xmin = ymin = int.MaxValue;
            xmax = ymax = int.MinValue;
            for (int i = 0; i < n; ++i)
            {
                s[i] = Reader.NextToken();
                for (int j = 0; j < m; ++j)
                {
                    if (s[i][j] == '*')
                    {
                        xmin = Math.Min(xmin, j);
                        xmax = Math.Max(xmax, j);
                        ymin = Math.Min(ymin, i);
                        ymax = Math.Max(ymax, i);
                    }
                }
            }

            for (int y = ymin; y <= ymax; ++y)
                Console.WriteLine(s[y].Substring(xmin, xmax - xmin + 1));
        }
    }
}