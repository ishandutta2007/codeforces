#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100100;
int n;
int a[N];
int ed[N][2];
int b[N];
int bad = 0;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        ed[i][0] = v;
        ed[i][1] = u;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        if (a[ed[i][0]] == a[ed[i][1]]) continue;
        bad++;
        b[ed[i][0]]++;
        b[ed[i][1]]++;
    }
    for (int i = 0; i < n; i++)
        if (b[i] == bad)
        {
            printf("YES\n%d\n", i + 1);
            return 0;
        }
    printf("NO\n");

    return 0;
}