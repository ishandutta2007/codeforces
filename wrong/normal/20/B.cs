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
            long A = Reader.NextInt();
            long B = Reader.NextInt();
            long C = Reader.NextInt();

            if (A == 0)
            {
                if (B == 0)
                {
                    if (C == 0)
                        Console.WriteLine(-1);
                    else
                        Console.WriteLine(0);
                }
                else
                {
                    Console.WriteLine(1);
                    Console.WriteLine("{0:f7}", -C / (double)B);
                }
            }
            else
            {
                long D = B * B - 4 * A * C;

                if (D > 0)
                {
                    Console.WriteLine(2);

                    double R1 = (-B - Math.Sqrt(D)) / 2 / A;
                    double R2 = (-B + Math.Sqrt(D)) / 2 / A;
                    if (R1 > R2)
                    {
                        double t = R1;
                        R1 = R2;
                        R2 = t;
                    }

                    Console.WriteLine("{0:f7}\n{1:f7}", R1, R2);
                }
                else if (D == 0)
                {
                    Console.WriteLine(1);
                    Console.WriteLine("{0:f7}", -B / 2.0 / A);
                }
                else
                    Console.WriteLine(0);
            }
        }
    }
}