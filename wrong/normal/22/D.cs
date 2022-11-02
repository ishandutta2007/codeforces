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
            int[] A = new int[n], B = new int[n];

            for (int i = 0; i < n; ++i)
            {
                A[i] = Reader.NextInt();
                B[i] = Reader.NextInt();
                if (A[i] > B[i])
                {
                    int t = A[i];
                    A[i] = B[i];
                    B[i] = t;
                }
            }

            var S = Enumerable.Range(0, n).Select(i => new { a = A[i], b = B[i] }).OrderBy(x => x.b);
            int last = -10001;
            List<int> sol = new List<int>();

            foreach (var s in S)
            {
                if (last < s.a)
                {
                    last = s.b;
                    sol.Add(last);
                }
            }

            Console.WriteLine(sol.Count);
            Console.WriteLine(string.Join(" ", sol.Select(x => x.ToString()).ToArray()));
        }
    }
}