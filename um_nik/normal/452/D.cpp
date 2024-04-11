#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
#define x first
#define y second

int n;
int m[4];
int t[4];
int s[4];
pii b[4];
set<pii> a[4];
int ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &m[i]);
        for (int j = 0; j < m[i]; j++)
            a[i].insert( mp(0, j) );
    }
    for (int i = 0; i < 3; i++)
        scanf("%d", &t[i]);
    for (int i = 1; i < 4; i++)
        s[i] = s[i - 1] + t[i - 1];
    while(n--)
    {
        int x = 0;
        for (int i = 0; i < 3; i++)
        {
            b[i] = *a[i].begin();
            a[i].erase(a[i].begin());
            x = max(x, b[i].x - s[i]);
        }
        ans = x + s[3];
        for (int i = 0; i < 3; i++)
            a[i].insert( mp(x + s[i + 1], b[i].second) );
    }
    printf("%d\n", ans);
    return 0;
}