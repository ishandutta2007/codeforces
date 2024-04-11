using System;
using System.Collections.Generic;

class main
{
    static string[] buffer = null;
    static int ptr = 0;
    
    static string GetToken()
    {
        while (buffer == null || ptr == buffer.Length)
        {
            buffer = Console.ReadLine().Split(' ', '\n', '\t', '\r');
            ptr = 0;
        }
        return buffer[ptr++];
    }
    
    static long ReadInt()
    {
        return long.Parse(GetToken());
    }
    
    public static void Main()
    {
        int n = (int)ReadInt(); long k = ReadInt();
        var list = new LinkedList<int>();
        for (int i = 0; i < n; i++)
            list.AddLast((int)ReadInt());
            
        int win = 0;
        while (win < k && list.First.Value != n)
        {
            if (list.First.Value > list.First.Next.Value)
            {
                win++;
                list.AddLast(list.First.Next.Value);
                list.Remove(list.First.Next);
            }
            else
            {
                win = 1;
                list.AddLast(list.First.Value);
                list.RemoveFirst();
            }
        }
        
        Console.WriteLine(list.First.Value);
    }
}