#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5;

set<pii> listA;
int a[N];

bool checkMax(int n, int Max, ll t)
{
    for (int i = 1; i < n; i++)
    {
        if (a[0] + Max < a[i])
            return false;
        if (a[i] > Max)
            t -= (ll)(a[i] - Max);
    }                               
    if (t < 0)
        return false;
    return true;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);     

    ll t = (ll)a[0] * (ll)(n - 2);
    int l = -1, r = (int)1e9 + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (checkMax(n, m, t))
            r = m;
        else
            l = m;
    }                  
    cout << (ll)a[0] + (ll)r;

    return 0;
}