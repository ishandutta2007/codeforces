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
            var logs =
                Enumerable.Range(1, int.Parse(Console.ReadLine()))
                    .Select(x =>
                    {
                        string s = Console.ReadLine();
                        int h = int.Parse(s.Substring(1, 2)) % 12 + (s[7] == 'p' ? 12 : 0);
                        int m = int.Parse(s.Substring(4, 2));
                        return h * 60 + m;
                    });
            
            int sol = 1, prev = -1, cons = 0;
            foreach (var log in logs)
            {
                if (log < prev)
                    sol++;
                if (log == prev)
                {
                    cons++;
                    if (cons > 10)
                    {
                        sol++;
                        cons = 1;
                    }
                }
                else
                {
                    cons = 1;
                }
                prev = log;
            }

            Console.WriteLine(sol);
        }
    }
}