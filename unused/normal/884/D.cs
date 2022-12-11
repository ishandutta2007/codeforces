using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static char[] buffer = new char[524288];
    static int end = 0;
    static int ptr = 0;

    static char GetChar()
    {
        while (ptr == end)
        {
            end = Console.In.Read(buffer, 0, 524288);
            if (end == 0) return ' ';
            ptr = 0;
        }
        return buffer[ptr++];
    }

    static int ReadInt()
    {
        int ret = 0;
        char ch;
        while ((ch = GetChar()) < '-')
            ;
        bool neg = (ch == '-'); if (neg) ch = GetChar();
        do ret = ret * 10 + ch - '0'; while ((ch = GetChar()) >= '0');
        return neg ? -ret : ret;
    }

    static List<long> pq = new List<long>();

    static void Swap(int x, int y)
    {
        long t = pq[x]; pq[x] = pq[y]; pq[y] = t;
    }

    static void Push(long x)
    {
        pq.Add(x);
        for (int idx = pq.Count - 1; idx > 1; idx >>= 1)
        {
            int p = idx >> 1;
            if (pq[p] <= x) return;
            Swap(p, idx);
        }
    }

    static long Pop()
    {
        long ret = pq[1];
        Swap(1, pq.Count - 1);
        pq.RemoveAt(pq.Count - 1);
        for (int idx = 1; idx < pq.Count;)
        {
            int L = idx << 1, R = L + 1;
            if (R < pq.Count && pq[L] > pq[R]) L = R;
            if (L < pq.Count && pq[L] < pq[idx])
            {
                Swap(L, idx);
                idx = L;
            }
            else break;
        }

        return ret;
    }

    static void Main()
    {
        int n = ReadInt();
        pq.Add(0);

        for (int i = 0; i < n; i++) Push(ReadInt());

        if (n % 2 == 0) Push(0);

        long ans = 0;

        while (pq.Count - 1 > 1)
        {
            long sum = 0;
            for (int i = 0; i < 3; i++)
            {
                sum += Pop();
            }
            ans += sum;
            Push(sum);
        }

        Console.WriteLine(ans);
    }
}