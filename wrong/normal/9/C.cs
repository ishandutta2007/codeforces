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
            int n = Reader.NextInt(), sol = 0;
            Dictionary<int, bool> C = new Dictionary<int, bool>();

            for (int i = 0; i < (1 << 10); ++i)
            {
                int t = 0;
                for (int j = 0; j < 10; ++j)
                    t = t * 10 + ((i & (1 << j)) != 0 ? 1 : 0);
                if (!C.ContainsKey(t))
                {
                    C[t] = true;
                    if (t > 0 && t <= n)
                        sol++;
                }
            }

            Console.WriteLine(sol);
        }
    }
}