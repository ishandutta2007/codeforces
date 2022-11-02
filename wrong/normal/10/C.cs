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
        static void Main(string[] args)
        {
            int N = Reader.NextInt();
            long S = 0;

            for (int A = 1; A <= N; ++A)
            {
                for (int B = 1; B <= 9; ++B)
                {
                    if (B > N)
                        continue;

                    int m = (N - B) / 9 + 1;
                    int k = N - A * B < 0 ? 0 : (N - A * B) / (9 * A) + 1;
                    int d = A * B % 9 == 0 ? 9 : A * B % 9;
                    int x = N - d < 0 ? 0 : (N - d) / 9 + 1;
                    S += (long)m * x - k;
                }
            }

            Console.WriteLine(S);
        }
    }
}