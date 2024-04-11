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

            while (!char.IsDigit(c = (char)Console.Read())) { }
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

            while (!char.IsDigit(c = (char)Console.Read())) { }
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
            int[] x = new int[4];
            for (int i = 0; i < 4; ++i)
                x[i] = Reader.NextInt();
            Array.Sort(x);
            if (x[0] + x[1] > x[2] || x[1] + x[2] > x[3])
                Console.WriteLine("TRIANGLE");
            else if (x[0] + x[1] == x[2] || x[1] + x[2] == x[3])
                Console.WriteLine("SEGMENT");
            else
                Console.WriteLine("IMPOSSIBLE");
        }
    }
}