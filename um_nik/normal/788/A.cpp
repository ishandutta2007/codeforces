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

const ll INF = (ll)1e18;
const int N = 200200;
int n;
ll a[N];
ll ans = -INF;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll x;
    scanf("%d%lld", &n, &x);
    n--;
    for (int i = 0; i < n; i++)
    {
        ll y;
        scanf("%lld", &y);
        a[i] = abs(x - y);
        x = y;
    }
    ll best0 = 0, best1 = -INF;
    ll curSum = 0;
    for (int i = 0; i < n; i++)
    {
        curSum += (i % 2 == 0 ? a[i] : -a[i]);
        ans = max(ans, curSum - best0);
        ans = max(ans, best1 - curSum);
        if (i % 2 == 0)
            best1 = max(best1, curSum);
        else
            best0 = min(best0, curSum);
    }
    printf("%lld\n", ans);

    return 0;
}