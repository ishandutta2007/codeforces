#include <bits/stdc++.h>
using namespace std;

vector<bitset<1000>> bs[1000];
int bidx[1000][1000];
bool graph[1000][1000];

char buf[5000005];

int main()
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", buf);
        for (int j = 0; buf[j]; j++) if (buf[j] == ':' || buf[j] == ',') buf[j] = ' ';

        for (char *p = strtok(buf, "-"); p; p = strtok(nullptr, "-"))
        {
            istringstream iss(p);

            int k;
            iss >> k;

            bitset<1000> st;

            while (k--)
            {
                int x;
                iss >> x;
                --x;

                st[x] = true;
                bidx[i][x] = bs[i].size();
            }

            bs[i].push_back(st);
        }
    }

    bitset<1000> all_set;
    for (int i = 0; i < n; i++) all_set[i] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;

            bitset<1000> org = all_set;
            org &= ~bs[i][bidx[i][j]];

            // org: i j      

            if (org == bs[j][bidx[j][i]])
            {
                graph[i][j] = true;
            }
        }
    }

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++) cnt += graph[i][j];
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != graph[j][i])
            {
                printf("-1\n");
                return 0;
            }
        }

        if (cnt != bs[i].size())
        {
            printf("-1\n");
            return 0;
        }
        total += cnt;
    }

    if (total != (n - 1) * 2)
    {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j]) printf("%d %d\n", i + 1, j + 1);
        }
    }
}