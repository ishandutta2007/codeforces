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

        static bool CheckWord(string w)
        {
            if (w.Length < 1 || w.Length > 16)
                return false;
            foreach (char c in w)
                if (!char.IsLetterOrDigit(c) && c != '_')
                    return false;
            return true;
        }

        static void Main(string[] args)
        {
            string[] s = Reader.NextToken().Split('@');

            if (s.Length != 2 || !CheckWord(s[0]))
                No();

            string[] t = s[1].Split('/');

            if (t[0].Length < 1 || t[0].Length > 32)
                No();

            foreach (string w in t[0].Split('.'))
                if (!CheckWord(w))
                    No();

            if (t.Length != 1 && t.Length != 2)
                No();

            if (t.Length == 2 && !CheckWord(t[1]))
                No();

            Console.WriteLine("YES");
        }
    }
}