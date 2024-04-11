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
        static int n, vb, vs, xu, yu;
        static int[] x;

        static double Distance(long dx, long dy)
        {
            return Math.Sqrt(dx * dx + dy * dy);
        }

        static double CalcTime(int p)
        {
            return (double)x[p] / vb + Distance(xu - x[p], yu) / vs;
        }

        static void Main(string[] args)
        {
            n = Reader.NextInt();
            vb = Reader.NextInt();
            vs = Reader.NextInt();

            x = new int[n];
            for (int i = 0; i < n; ++i)
                x[i] = Reader.NextInt();

            xu = Reader.NextInt();
            yu = Reader.NextInt();

            int sol = 1;
            for (int i = 2; i < n; ++i)
            {
                double ds = CalcTime(sol), di = CalcTime(i);
                if (ds > di || (Math.Abs(ds - di) < 1e-9 && Distance(xu - x[sol], yu) > Distance(xu - x[i], yu)))
                    sol = i;
            }

            Console.WriteLine(sol + 1);
        }
    }
}