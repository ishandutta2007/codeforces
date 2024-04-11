#include <bits/stdc++.h>
using namespace std;

int tab[4];
int res[4][2];

int query(int x = -1, int k = -1)
{
    int b;
    if(k != -1)
    {
        b = tab[k];
        tab[k] = x;
    }
    if(tab[0]>tab[2] || tab[1]>tab[3]) return 0;
    printf("? %d %d %d %d\n", tab[0],tab[1],tab[2],tab[3]);
    fflush(stdout);
    if(k != -1)
        tab[k] = b;
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    tab[0] = tab[1] = 1;
    tab[2] = tab[3] = n;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        {
            int a = 1, b = n, c;
            while(a < b)
            {
                c = (a + b + 1) / 2;
                if(query(c, i) > j)
                    a = c;
                else b = c - 1;
            }
//             fprintf(stderr, "debug: %d %d %d\n", i, j, a);
            res[i][j] = a;
        }
    for(int i = 2; i < 4; i++)
        for(int j = 0; j < 2; j++)
        {
            int a = 1, b = n, c;
            while(a < b)
            {
                c = (a + b) / 2;
                if(query(c, i) > j)
                    b = c;
                else a = c + 1;
            }
//             fprintf(stderr, "debug: %d %d %d\n", i, j, a);
            res[i][j] = a;
        }
    for(int i = 0; i < (1 << 4); i++)
    {
        for(int j = 0; j < 4; j++)
            tab[j] = res[j][(i >> j) & 1];
        if(query() != 1) continue;
        for(int j = 0; j < 4; j++)
            tab[j] = res[j][((i >> j) & 1) ^ 1];
        if(query() != 1) continue;
        printf("! %d %d %d %d", tab[0],tab[1],tab[2],tab[3]);
        for(int j = 0; j < 4; j++)
            tab[j] = res[j][(i >> j) & 1];
        printf(" %d %d %d %d\n", tab[0],tab[1],tab[2],tab[3]);
        break;
    }
}