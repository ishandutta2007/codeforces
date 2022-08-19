#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)2e5 + 100;
int n, k, a;
int q[N];
int s[N];


bool check(int p)
{
    for (int i = 0; i <= n; i++)
        s[i] = 0;
    for (int i = 0; i < p; i++)
        s[q[i]]++;
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1];
    int cnt = 0;
    int x = 0;
    while(x + a <= n && cnt < k)
    {
        if (s[x] == s[x + a])
        {
            cnt++;
            x += a + 1;
        }
        else
            x++;
    }
    return (cnt == k);
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &k, &a);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &q[i]);
    if (check(m))
    {
        printf("-1\n");
        return 0;
    }
    int l = 0, r = m;
    while(r - l > 1)
    {
        m = (r + l) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    printf("%d\n", r);

    return 0;
}