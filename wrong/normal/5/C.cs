using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeForces
{
    class Program
    {
        static void Main(string[] args)
        {
            string S = Console.ReadLine();
            int[] pos = new int[1 << 21];
            int depth = S.Length;

            for (int i = 0; i < 1 << 21; ++i)
                pos[i] = int.MaxValue;

            int maxlen = 0, cnt = 1;

            for (int i = 0; i < S.Length; ++i)
            {
                if (S[i] == '(')
                {
                    depth++;
                    if (pos[depth] > i)
                        pos[depth] = i;
                }
                else
                {
                    int len = i - pos[depth] + 1;
                    if (len > maxlen)
                    {
                        maxlen = len;
                        cnt = 1;
                    }
                    else if (len == maxlen)
                    {
                        cnt++;
                    }
                    pos[depth + 1] = int.MaxValue;
                    depth--;
                }
            }

            Console.WriteLine("{0} {1}", maxlen, cnt);
        }
    }
}