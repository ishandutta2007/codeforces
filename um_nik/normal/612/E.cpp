#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second
const int N = (int)1e6 + 100;
int n;
int a[N];
int m = 0;
pii b[N];
int ans[N];
bool used[N];

void Fail()
{
    printf("-1\n");
    exit(0);
}

int getLen(int v)
{
    int cnt = 0;
    while(!used[v])
    {
        cnt++;
        used[v] = 1;
        v = a[v];
    }
    return cnt;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i]) continue;
        int l = getLen(i);
        b[m++] = mp(l, i);
    }
    sort(b, b + m);
    int it = 0;
    while(it < m)
    {
        if (b[it].X & 1)
        {
            int v = b[it].Y;
            int u = v;
            for (int i = 0; i < b[it].X / 2 + 1; i++)
                u = a[u];
            do
            {
                ans[v] = u;
                v = a[a[v]];
                u = a[a[u]];
            }
            while(v != b[it].Y);
            it++;
        }
        else if (it == m - 1 || b[it].X != b[it + 1].X)
            Fail();
        else
        {
            int v = b[it].Y, u = b[it + 1].Y;
            for (int i = 0; i < b[it].X; i++)
            {
                ans[v] = u;
                v = a[v];
                ans[u] = v;
                u = a[u];
            }
            it += 2;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i] + 1);
    printf("\n");

    return 0;
}