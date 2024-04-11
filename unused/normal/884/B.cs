using System;

class Program
{
    static string buffer = null;
    static int ptr = 0;

    static char GetChar()
    {
        while (buffer == null || ptr == buffer.Length)
        {
            buffer = Console.ReadLine();
            if (buffer == null) buffer = " ";
            ptr = 0;
            return ' ';
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
        int n, x;
        n = ReadInt();
        x = ReadInt();

        int[] a = new int[n];

        int total = -1;

        for (int i = 0; i < n; i++)
        {
            a[i] = ReadInt();
            total += a[i] + 1;
        }

        if (total == x) Console.WriteLine("YES");
        else Console.WriteLine("NO");
    }
}