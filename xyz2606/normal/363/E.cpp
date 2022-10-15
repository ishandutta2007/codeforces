#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, r, a[503][503], s[503][503], mx[503][503], eq[503][503], cir[503][503], l[1111], ans,  dlt[1111], tmp;
long long tot;
int main()
{
    scanf("%d%d%d", &n, &m, &r);
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) 
    {
        scanf("%d", &a[i][j]);
        s[i][j] = a[i][j] + s[i][j - 1];
        //printf("%d %d %d\n", i, j, s[i][j]);
    }
    for(int i = 0; i <= r; i++)
    {
        l[i] = 0;
        while(l[i] * l[i] + i * i <= r * r) l[i]++;
        l[i] -= 1;
    }
    memset(mx, 0, sizeof(mx));
    memset(eq, 0, sizeof(eq));
    
    for(int i = r + 1; i <= n - r; i++) for(int j = m - r; j >= r + 1; j--)
    {
        cir[i][j] = 0;
        for(int k = -r; k <= r; k++)
        {
            cir[i][j] += s[i + k][j + l[abs(k)]] - s[i + k][j - l[abs(k)] - 1];
            //printf("%d %d %d %d\n", k, j + l[abs(k)], j - l[abs(k)], s[k][j + l[abs(k)]] - s[k][j - l[abs(k)] - 1]);
        }
        //printf("cir[%d][%d] = %d\n", i, j, cir[i][j]);
        if(mx[i][j + 1] == cir[i][j])
        {
            mx[i][j] = mx[i][j + 1];
            eq[i][j] = eq[i][j + 1] + 1;
        }else if(mx[i][j + 1] < cir[i][j])
        {
            mx[i][j] = cir[i][j];
            eq[i][j] = 1;
        }else
        {
            mx[i][j] = mx[i][j + 1];
            eq[i][j] = eq[i][j + 1];
        }
    }
    ans = 0;
    memset(dlt, -1, sizeof(dlt));
    for(int i = 0; i <= 2 * r; i++)
    {
        for(int j = -r; j <= r - i; j++) dlt[i] = max(dlt[i], l[abs(j)] + l[abs(i + j)]);
        //printf("%d %d\n", i, dlt[i]);
    }
    tot = 0;
    for(int i = r + 1; i <= n - r; i++) for(int j = r + 1; j <= m - r; j++)
    {
        for(int i1 = r + 1; i1 <= n - r; i1++)
        {
            if(abs(i - i1) <= 2 * r)
            {
                if((tmp = j + dlt[abs(i1 - i)] + 1) <= m - r)
                {
                    if(ans < cir[i][j] + mx[i1][tmp])
                    {
                        //if(cir[i][j] + mx[i1][tmp] == 35) printf("%d %d %d %d\n", i, j, i1, tmp);
                        ans = cir[i][j] + mx[i1][tmp];
                        tot = eq[i1][tmp];
                    }else if(ans == cir[i][j] + mx[i1][tmp])
                    {
                        tot += eq[i1][tmp];
                    }
                }
            }else
            {
                tmp = i1 < i?j + 1:j;
                if(ans < cir[i][j] + mx[i1][tmp])
                {
                    ans = cir[i][j] + mx[i1][tmp];
                    tot = eq[i1][tmp];
                }else if(ans == cir[i][j] + mx[i1][tmp])
                {
                    tot += eq[i1][tmp];
                }
            }
        }
    }
    printf("%d %I64d\n", ans, tot);
    fclose(stdin);
    return 0;
}