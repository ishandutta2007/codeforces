using System;
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

    static void Main()
    {
        int n = ReadInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++)
            p[i] = ReadInt() - 1;

        bool[] visit = new bool[n];
        var lst = new List<int>();
        lst.Add(0);

        for (int i = 0; i < n; i++)
        {
            if (visit[i]) continue;

            int cnt = 0;

            for (int ii = i; visit[ii] == false; visit[ii] = true, ii = p[ii], ++cnt)
                ;

            lst.Add(cnt);
        }

        lst.Sort();
        lst[lst.Count - 1] += lst[lst.Count - 2];
        lst[lst.Count - 2] = 0;
        long ans = 0;
        foreach (int t in lst)
            ans += (long)t * t;
        Console.WriteLine(ans);
    }
}