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
        int n = ReadInt(), t = ReadInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = ReadInt();

        for (int i = 0; i < n; i++)
        {
            t -= 86400 - a[i];
            if (t <= 0)
            {
                Console.WriteLine(i + 1);
                return;
            }
        }
    }
}