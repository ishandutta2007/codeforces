using System;
using System.Linq;

namespace A
{
    public static class A
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var bookPages = Console.ReadLine().Split().Select(int.Parse).Select(x => x - 1).ToArray();
            var daysCount = 0;
            for (var i = 0; i < bookPages.Length; i++)
            {
                var targetPage = bookPages[i];
                while (i < bookPages.Length && i < targetPage)
                {
                    i++;
                    targetPage = Math.Max(targetPage, bookPages[i]);
                }

                daysCount++;
            }

            Console.WriteLine(daysCount);
        }
    }
}