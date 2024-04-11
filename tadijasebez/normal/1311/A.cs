using System;

namespace Add_Odd_or_Subtract_Even {
    class Program {
        static void Main(string[] args) {
            int t = int.Parse(Console.ReadLine());
            while (t-->0) {
                int a, b;
                string[] inp = Console.ReadLine().Split();
                a = int.Parse(inp[0]);
                b = int.Parse(inp[1]);
                int dist = b - a;
                if (dist == 0) Console.WriteLine(0);
                else if (dist > 0 && dist % 2 == 1) Console.WriteLine(1);
                else if (dist > 0) Console.WriteLine(2);
                else if (dist % 2 == 0) Console.WriteLine(1);
                else Console.WriteLine(2);
            }
        }
    }
}