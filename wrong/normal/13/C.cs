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

            int[] seq, nums;
            seq = new int[n];
            nums = new int[n];
            for (int i = 0; i < n; ++i)
                seq[i] = nums[i] = Reader.NextInt();

            long[] dp = new long[n + 1];
            dp[0] = 0;
            for (int i = 1; i <= n; ++i)
                dp[i] = 1L << 60;

            Array.Sort(nums);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dp[j + 1] = Math.Min(dp[j + 1], dp[j] + Math.Abs(seq[j] - nums[i]));

            Console.WriteLine(dp[n]);
        }
    }
}