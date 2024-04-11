#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 10;
int a[N], val[N];

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        ans += (ll)a[i] * (ll)x;
    }
    
    for (int i = 0; i < n; i++)
        val[i] = min(i, x - 1);
    sort(val, val + n, greater<int>());
    sort(a, a + n, greater<int>());
    
    for (int i = 0; i < n; i++)
        ans -= (ll)val[i] * a[i];
    cout << ans;
    
    return 0;
}