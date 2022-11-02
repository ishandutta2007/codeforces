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
            int T = Reader.NextInt();

            for (int t = 0; t < T; ++t)
            {
                int N = Reader.NextInt();
                int[] A = new int[2 * N], B = new int[2 * N];

                for (int i = 1; i <= 2 * N - 1; ++i)
                {
                    A[i] = Reader.NextInt();
                    B[i] = Reader.NextInt();
                }

                var boxes = Enumerable.Range(1, 2 * N - 1).Select(i => new { a = A[i], o = B[i], idx = i }).OrderByDescending(x => x.a).ToArray();
                int[] sol = new int[N];

                Console.WriteLine("YES");
                sol[0] = boxes[0].idx;
                for (int i = 1; i < 2 * N - 1; i += 2)
                {
                    var p = boxes[i];
                    var q = boxes[i + 1];
                    sol[i / 2 + 1] = p.o < q.o ? q.idx : p.idx;
                }

                Array.Sort(sol);
                Console.WriteLine(string.Join(" ", sol.Select(x => x.ToString()).ToArray()));
            }
        }
    }
}