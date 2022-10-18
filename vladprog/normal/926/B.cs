using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution {
    static int gcd(int x,int y)
    {
        if(y==0)
            return x;
        else
            return gcd(y,x%y);
    }
    static void Main(String[] args) {
        int n=Convert.ToInt32(Console.ReadLine());
        int[] a=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        Array.Sort(a);
        int g=0;
        for(int i=0;i<n-1;i++)
            g=gcd(g,a[i+1]-a[i]);
        int ans=0;
        for(int i=0;i<n-1;i++)
            ans+=(a[i+1]-a[i])/g-1;
        Console.WriteLine(ans);
    }
}