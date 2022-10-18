using System;
using System.Linq;

public static class Program
{
    public static void Main()
    {
        var n = Convert.ToInt32(Console.ReadLine());
        string ans = "";
        if (n%2 == 0) ans += '1';
        else ans += '7';
        for(int i = 1; i <= n/2-1; ++i) ans += '1';
        
        //Console.WriteLine(ans.Length);
        Console.WriteLine(ans);
    }
}