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
            int n, m;

            n = Reader.NextInt();
            m = Reader.NextInt();

            string col = Console.ReadLine();
            string[] office = new string[n];
            for (int i = 0; i < n; ++i)
                office[i] = Console.ReadLine();

            bool[] adj = new bool[26];
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (office[i][j] != col[0])
                        continue;
                    for (int y = -1; y <= 1; ++y)
                    {
                        for (int x = -1; x <= 1; ++x)
                        {
                            if (Math.Abs(x) + Math.Abs(y) != 1)
                                continue;
                            if (i + y < 0 || i + y >= n || j + x < 0 || j + x >= m)
                                continue;
                            if (office[i + y][j + x] != '.')
                                adj[office[i + y][j + x] - 'A'] = true;
                        }
                    }
                }
            }

            int cnt = 0;
            for (int i = 0; i < 26; ++i)
                if (adj[i] && i != col[0] - 'A')
                    cnt++;
            Console.WriteLine(cnt);
        }
    }
}