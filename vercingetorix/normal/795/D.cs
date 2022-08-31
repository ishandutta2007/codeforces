using System;
using System.Linq;

public static class Program
{
    public static void Main()
    {
        var nn = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var l = nn[1];
        var r = nn[2];
        l--;
        r--;
        var n = nn[0];
        var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var b = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var s = "TRUTH";
        for(int i = 0; i <n; i++) {
            if (i>=l && i<=r) continue;
            if(a[i]!=b[i]) s="LIE";
        }
        Console.WriteLine(s);
        
    }
}