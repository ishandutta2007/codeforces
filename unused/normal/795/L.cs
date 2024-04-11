using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class CS
{
    static List<int> lst;
    static int n, k;

    static bool Check(int t)
    {
        int last = 0;
        int remain = k - 1;
        for (int i = 1; i < lst.Count; i++)
        {
            if (lst[i] - last > t + 1) return false;
            if (i == lst.Count - 1 || lst[i + 1] - last > t + 1)
            {
                last = lst[i];
                if (remain-- == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    static void Main(string[] args)
    {
        var line = Console.ReadLine().Split();
        n = int.Parse(line[0]);
        k = int.Parse(line[1]);
        var dat = Console.ReadLine().Trim();

        lst = new List<int>();
        for (int i = 0; i < dat.Length; i++)
        {
            if (dat[i] == '0') lst.Add(i);
        }

        int lo = 0, hi = n, ans = n + 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (Check(mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        Console.WriteLine(ans);
    }
}