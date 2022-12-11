using System;
using System.Collections.Generic;
using System.Linq;

namespace C
{
    class C
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var answers = new List<List<int>>();
            for (var i = 0; i < n; i++)
            {
                var currentList = new List<int>();
                for (var a = 0; a < n; a++)
                {
                    var offset = a % 2 == 0 ? i : n - i - 1;
                    int id = a * n + offset + 1;
                    currentList.Add(id);
                }

                answers.Add(currentList);
            }
            Console.WriteLine(string.Join("\n", answers.Select(x => string.Join(" ", x))));
        }
    }
}