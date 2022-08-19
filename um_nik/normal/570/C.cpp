#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 300100;
int n, m;
int ans;

bool u[N];
char s[N];

void query()
{
    int x;
    char c;
    scanf("%d %c", &x, &c);
    bool t = (c == '.');
    x--;
    if (u[x] == t)
    {
        printf("%d\n", ans);
        return;
    }
    u[x] = t;
    if (u[x])
    {
        ans++;
        if (x != 0 && u[x - 1]) ans++;
        if (!u[x + 1]) ans--;
    }
    else
    {
        ans--;
        if (x != 0 && u[x - 1]) ans--;
        if (!u[x + 1]) ans++;
    }
    printf("%d\n", ans);
    return;
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf(" %s ", s);
    for (int i = 0; i < n; i++)
        if (s[i] == '.')
        {
            u[i] = 1;
            ans++;
        }
    for (int i = 0; i < n; i++)
        if (u[i] && !u[i + 1])
            ans--;
    while(m--)
        query();

    return 0;
}