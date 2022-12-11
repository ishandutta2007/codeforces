#include <bits/stdc++.h>
using namespace std;

const int N = 2001;
int p[N];
int o[N];

int opponent()
{
    int x;
    scanf("%d", &x);
    p[x] = 0;
    int ret = 0;
    if(o[x]) ret = o[x];
    o[x] = 0;
    return ret;
}

void my_move(int x)
{
    printf("%d\n", x);
    fflush(stdout);
    p[x] = 0;
    o[x] = 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 2 * n; i++)
        scanf("%d", p + i);
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        o[a] = b;
        o[b] = a;
    }
    int t;
    scanf("%d", &t);
    t--;
    int must_take = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        if(t == 0)
        {
            if(must_take && p[must_take]) my_move(must_take);
            else
            {
                int *mx = max_element(o + 1, o + 2 * n + 1);
                if(*mx)
                    my_move(p[*mx] > p[mx - o] ? *mx : mx - o);
                else my_move(max_element(p + 1, p + 2 * n + 1) - p);
            }
        }
        else
            must_take = opponent();
        t = 1 - t;
    }
}