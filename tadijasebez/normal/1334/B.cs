using System;

namespace Middle_Class
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            while (t > 0)
            {
                string[] o = Console.ReadLine().Split(' ');
                int n = int.Parse(o[0]);
                int x = int.Parse(o[1]);
                string[] tmp = Console.ReadLine().Split(' ');
                int[] a = new int[n];
                for(int i = 0; i < n; i++)
                {
                    a[i] = int.Parse(tmp[i]);
                }
                Array.Sort(a);
                long sz = 0, sum = 0;
                long ans = 0;
                for(int i = n - 1; i >= 0; i--)
                {
                    sum += a[i];
                    sz++;
                    if (sum >= sz * x)
                        ans = sz;
                }
                Console.WriteLine(ans);
                t--;
            }
        }
    }
}