#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);

    int cur = 1;
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (cur <= a[i])
            ans += (a[i] - cur);
        else
            ans += (n - cur) + a[i];
        cur = a[i];
    }
    printf("%I64d", ans);
    
    return 0;
}