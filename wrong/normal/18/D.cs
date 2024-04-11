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
            int n = Reader.NextInt();
            bool[] busy = new bool[n];
            List<int>[] win = new List<int>[2001];
            int[] sell = new int[2001];

            for (int i = 0; i <= 2000; ++i)
            {
                win[i] = new List<int>();
                sell[i] = -1;
            }

            for (int i = 0; i < n; ++i)
            {
                if (Reader.NextToken() == "win")
                    win[Reader.NextInt()].Add(i);
                else
                    sell[Reader.NextInt()] = i;
            }
            
            int[] res = new int[2000];
            int digits = 1;
            for (int i = 2000; i >= 0; --i)
            {
                int j = 0, carry = 0;

                if (sell[i] >= 0 && win[i].Count > 0 && win[i][0] < sell[i])
                {
                    int get = 0;
                    bool ok = true;

                    for (int k = 0; k < win[i].Count && win[i][k] < sell[i]; ++k)
                        get = win[i][k];
                    for (int k = get; ok && k <= sell[i]; ++k)
                        if (busy[k])
                            ok = false;
                    if (ok)
                    {
                        carry = 1;
                        for (int k = get; k <= sell[i]; ++k)
                            busy[k] = true;
                    }
                }

                for (; j < digits || carry > 0; ++j)
                {
                    res[j] = res[j] * 2 + carry;
                    carry = res[j] / 10;
                    res[j] %= 10;
                }
                digits = j;
            }
            Console.WriteLine(string.Join("", Array.ConvertAll(res.AsEnumerable().Take(digits).Reverse().ToArray(), Convert.ToString)));
        }
    }
}