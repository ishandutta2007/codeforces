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
            int n = Reader.NextInt(), k = Reader.NextInt();
            int[] h = new int[n];

            for (int i = 0; i < n; ++i)
                h[i] = Reader.NextInt();

            int f1, r1, f2, r2;
            int[] a1 = new int[n], b1 = new int[n];
            int[] a2 = new int[n], b2 = new int[n];
            int[] left = new int[n];

            f1 = r1 = f2 = r2 = b1[0] = b2[0] = left[0] = 0;
            a1[0] = a2[0] = h[0];
            for (int i = 1; i < n; ++i)
            {
                left[i] = left[i - 1];
                while (f1 <= r1 && a1[r1] <= h[i]) r1--;
                while (f2 <= r2 && a2[r2] >= h[i]) r2--;
                a1[++r1] = h[i]; b1[r1] = i;
                a2[++r2] = h[i]; b2[r2] = i;
                while (a1[f1] - a2[f2] > k)
                {
                    left[i]++;
                    if (b1[f1] < left[i]) f1++;
                    if (b2[f2] < left[i]) f2++;
                }
            }

            int A = 0, B = 0;
            for (int i = 0; i < n; ++i)
            {
                if (i - left[i] + 1 > A)
                {
                    A = i - left[i] + 1;
                    B = 1;
                }
                else if (i - left[i] + 1 == A)
                {
                    B++;
                }
            }

            Console.WriteLine("{0} {1}", A, B);
            for (int i = 0; i < n; ++i)
                if (i - left[i] + 1 == A)
                    Console.WriteLine("{0} {1}", left[i] + 1, i + 1);
        }
    }
}