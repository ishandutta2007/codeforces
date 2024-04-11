using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApp1
{
    class Program
    {
        static List<KeyValuePair<int, int>>[] graph;
        static bool[] visit;
        static int[] weight;
        static int[] echelon = new int[31];

        static void addcycle(int t)
        {
            for (int i = 30; i >= 0; i--)
            {
                if ((t & (1 << i)) == 0) continue;

                if (echelon[i] == 0)
                {
                    echelon[i] = t;
                    return;
                }

                t ^= echelon[i];
            }
        }

        static void dfs(int t, int now)
        {
            visit[t] = true;
            weight[t] = now;

            foreach (var edge in graph[t])
            {
                int nxt = edge.Key;
                int w = edge.Value;

                if (visit[nxt]) addcycle(now ^ w ^ weight[nxt]);
                else
                {
                    dfs(nxt, now ^ w);
                }
            }
        }

        static void Main(string[] args)
        {
            int n, m;
            var line = Console.ReadLine().Split(null);

            n = int.Parse(line[0]);
            m = int.Parse(line[1]);

            graph = new List<KeyValuePair<int, int>>[n + 1];
            visit = new bool[n + 1];
            weight = new int[n + 1];

            for (int i = 1; i <= n; i++) graph[i] = new List<KeyValuePair<int, int>>();

            for (int i = 0; i < m; i++)
            {
                int a, b, w;
                line = Console.ReadLine().Split(null);
                a = int.Parse(line[0]);
                b = int.Parse(line[1]);
                w = int.Parse(line[2]);

                graph[a].Add(new KeyValuePair<int, int>(b, w));
                graph[b].Add(new KeyValuePair<int, int>(a, w));
            }

            dfs(1, 0);

            int ans = weight[n];

            for (int i = 30; i >= 0; i--)
            {
                ans = Math.Min(ans, ans ^ echelon[i]);
            }

            Console.WriteLine(ans);
        }
    }
}