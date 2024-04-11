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
        static double[] SolveTridiagonalSystem(double[] a, double[] b, double[] c, double[] d)
        {
            int n = b.Length;

            for (int i = 1; i < n; ++i)
            {
                double m = a[i] / b[i - 1];
                b[i] = b[i] - m * c[i - 1];
                d[i] = d[i] - m * d[i - 1];
            }

            double[] ret = new double[n];

            ret[n - 1] = d[n - 1] / b[n - 1];
            for (int i = n - 2; i >= 0; --i)
                ret[i] = (d[i] - c[i] * ret[i + 1]) / b[i];

            return ret;
        }

        static void Main(string[] args)
        {
            int N, M, R, C;

            N = Reader.NextInt();
            M = Reader.NextInt();
            R = Reader.NextInt();
            C = Reader.NextInt();

            if (M == 1)
            {
                Console.WriteLine("{0:f9}", 2 * (N - R));
                return;
            }

            double[] z = new double[M];
            double[] a = new double[M];
            double[] b = new double[M];
            double[] c = new double[M];

            for (int r = N - 1; r >= R; --r)
            {
                z[0] += 3;
                b[0] = 2;
                c[0] = -1;
                for (int i = 1; i < M - 1; ++i)
                {
                    z[i] += 4;
                    a[i] = -1;
                    b[i] = 3;
                    c[i] = -1;
                }
                z[M - 1] += 3;
                a[M - 1] = -1;
                b[M - 1] = 2;

                z = SolveTridiagonalSystem(a, b, c, z);
            }

            Console.WriteLine("{0:f9}", z[C - 1]);
        }
    }
}