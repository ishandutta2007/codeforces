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
    }

    class Program
    {
        static void Main(string[] args)
        {
            int n = Reader.NextInt();
            int[,] mat = new int[n, n];

            for (int i = 0; i < n - 1; ++i)
                for (int j = 0; j < n - 1; ++j)
                    mat[i, j] = (i + j) % (n - 1) + 1;
            for (int i = 0; i < n - 1; ++i)
                mat[i, n - 1] = mat[n - 1, i] = mat[i, i];
            for (int i = 0; i < n; ++i)
                mat[i, i] = 0;

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    Console.Write(mat[i, j].ToString() + (j == n - 1 ? "\n" : " "));
        }
    }
}