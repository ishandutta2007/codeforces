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

const int N = 3003;
const ll INF = (ll)1e12;
int n, m;
ll a[N], b[N];
int L[N], R[N];
ll p;

bool solve(ll T)
{
    for (int i = 0; i < n; i++) {
        L[i] = R[i] = -1;
        for (int j = 0; j < m; j++) {
            if (abs(a[i] - b[j]) + abs(b[j]) <= T) {
                if (L[i] == -1)
                    L[i] = j;
                R[i] = j;
            }
        }
        if (L[i] == -1) return false;
    }
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            if (R[j] - L[i] < j - i)
                return false;
        }
    return true;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);


    scanf("%d%d%lld", &n, &m, &p);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] -= p;
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
        b[i] -= p;
    }
    sort(a, a + n);
    sort(b, b + m);

    ll l = 0, r = INF;
    for (int i = 0; i < n; i++)
        l = max(l, abs(a[i]));
    l--;
    while(r - l > 1) {
        ll x = (l + r) / 2;
        if (solve(x))
            r = x;
        else
            l = x;
    }
    printf("%lld\n", r);

    return 0;
}