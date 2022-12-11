using System;
using System.Linq;

namespace B
{
    class B
    {
        private const long mod = (long) 1e9 + 7;

        static long BinaryPower(long a, long k)
        {
            if (k == 0)
                return 1;
            if (k % 2 == 1)
                return (BinaryPower(a, k - 1) * a) % mod;
            long t = BinaryPower(a, k / 2);
            return t * t % mod;
        }

        static long Sub(long a, long b)
        {
            return (a - b + mod) % mod;
        }

        static void Main(string[] args)
        {
            var values = Console.ReadLine().Split().Select(long.Parse).ToArray();
            Console.WriteLine(BinaryPower(Sub(BinaryPower(2, values[1]), 1), values[0]));
        }
    }
}