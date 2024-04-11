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
        static int GCD(int n, int m)
        {
            return m > 0 ? GCD(m, n % m) : n;
        }

        static void Get(out int A, out int B, out int C)
        {
            int a = Reader.NextInt();
            int b = Reader.NextInt();
            int c = Reader.NextInt();

            int g = GCD(Math.Abs(a), GCD(Math.Abs(b), Math.Abs(c)));
            if (g == 0)
                g = 1;

            A = a / g;
            B = b / g;
            C = c / g;
        }

        static void Main(string[] args)
        {
            int A1, B1, C1, A2, B2, C2;

            Get(out A1, out B1, out C1);
            Get(out A2, out B2, out C2);

            bool inf = (A1 == 0 && B1 == 0 && C1 == 0) || (A2 == 0 && B2 == 0 && C2 == 0);
            bool no = (A1 == 0 && B1 == 0 && C1 != 0) || (A2 == 0 && B2 == 0 && C2 != 0);

            if (!no && ((A1 == A2 && B1 == B2 && C1 == C2) || (A1 == -A2 && B1 == -B2 && C1 == -C2) || inf))
            {
                Console.WriteLine(-1);
                return;
            }

            if (A1 * B2 == A2 * B1 || no)
            {
                Console.WriteLine(0);
                return;
            }

            Console.WriteLine(1);
        }
    }
}