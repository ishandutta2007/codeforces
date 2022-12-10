using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication9
{
    class Program
    {
        static void Main (string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var inp = Console.ReadLine().Split(' ');
            var c = inp.Select(int.Parse).ToArray();
            var res = "";
            var last = 'a';
            for (var i = n - 1; i >= 0; --i)
            {
                for (var j = i - 1; j >= 0; --j)
                    c[j] -= (i - j + 1)*c[i];
                for (; c[i] > 0; --c[i])
                {
                    res += new string(last == 'a' ? 'b' : 'a', i + 1);
                    last = last == 'a' ? 'b' : 'a';
                }
            }
            Console.WriteLine(res);
        }
    }
}