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
        static void No()
        {
            Console.WriteLine("NO");
            Environment.Exit(0);
        }

        static void Main(string[] args)
        {
            List<List<int>> X, Y;

            X = new List<List<int>>();
            Y = new List<List<int>>();
            X.Add(new List<int>());
            Y.Add(new List<int>());

            for (int i = 0; i < 4; ++i)
            {
                int x1, y1, x2, y2;

                x1 = Reader.NextInt();
                y1 = Reader.NextInt();
                x2 = Reader.NextInt();
                y2 = Reader.NextInt();

                bool xeq = x1 == x2, yeq = y1 == y2;
                if (!(xeq ^ yeq))
                    No();
                else if (xeq)
                {
                    X[0].Add(x1);
                    Y.Add(new List<int>(new int[] { y1, y2 }));
                }
                else
                {
                    Y[0].Add(y1);
                    X.Add(new List<int>(new int[] { x1, x2 }));
                }
            }

            if (X.Count != 3 || Y.Count != 3)
                No();

            for (int i = 0; i < X.Count; ++i)
            {
                X[i].Sort();
                if (X[i].Count != X[0].Count)
                    No();
                for (int j = 0; j < X[i].Count; ++j)
                    if (X[i][j] != X[0][j])
                        No();
            }
            for (int i = 0; i < Y.Count; ++i)
            {
                Y[i].Sort();
                if (Y[i].Count != Y[0].Count)
                    No();
                for (int j = 0; j < Y[i].Count; ++j)
                    if (Y[i][j] != Y[0][j])
                        No();
            }

            Console.WriteLine("YES");
        }
    }
}