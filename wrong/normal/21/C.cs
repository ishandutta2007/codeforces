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
            int n = Reader.NextInt(), S;
            int[] a = new int[n];

            for (int i = 0; i < n; ++i)
                a[i] = Reader.NextInt();
            S = a.Sum();

            if(S % 3 != 0)
            {
                Console.WriteLine(0);
                return;
            }

            int[] left, right;
            left = new int[n];
            right = new int[n];

            for (int i = 0, s = 0; i < n; ++i)
            {
                s += a[i];
                if (s == S / 3)
                    left[i] = 1;
            }

            for (int i = n - 1, s = 0; i >= 0; --i)
            {
                s += a[i];
                if (s == S / 3)
                    right[i] = 1;
            }

            long sol = 0;
            int sum = 0;
            for (int i = n - 1; i >= 2; --i)
            {
                sum += right[i];
                if (left[i - 2] == 1)
                    sol += sum;
            }

            Console.WriteLine(sol);
        }
    }
}