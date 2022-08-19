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

const int N = 500100;
ll AB[N], BA[N], AC[N], CA[N], BC[N], CB[N];
ll sumBC[N];
ll ans;
ll X, Y, Z;

void read()
{
    int n;
    scanf("%d%lld%lld%lld", &n, &X, &Y, &Z);
    ans = X * Y * Z;
    while(n--) {
        ll x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        AB[x] = max(AB[x], y);
        AC[x] = max(AC[x], z);
        BA[y] = max(BA[y], x);
        BC[y] = max(BC[y], z);
        CA[z] = max(CA[z], x);
        CB[z] = max(CB[z], y);
    }
    for (ll x = X; x > 0; x--) {
        AB[x - 1] = max(AB[x - 1], AB[x]);
        AC[x - 1] = max(AC[x - 1], AC[x]);
    }
    for (ll y = Y; y > 0; y--) {
        BA[y - 1] = max(BA[y - 1], BA[y]);
        BC[y - 1] = max(BC[y - 1], BC[y]);
    }
    for (ll z = Z; z > 0; z--) {
        CA[z - 1] = max(CA[z - 1], CA[z]);
        CB[z - 1] = max(CB[z - 1], CB[z]);
    }
    for (ll y = 1; y <= Y; y++)
        sumBC[y] = sumBC[y - 1] + BC[y];
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();

/*
    ll sum1 = 0, sum2 = 0;
    for (ll x = 1; x <= X; x++)
        sum1 += AC[x];
    for (ll z = 1; z <= Z; z++)
        sum2 += CA[z];
    printf("%lld = %lld\n", sum1, sum2);
*/

    for (ll x = 1; x <= X; x++) {
        ans -= AB[x] * Z;
        ans -= AC[x] * Y;
    }
    for (ll y = 1; y <= Y; y++) {
        ans -= BC[y] * X;
    }

    //printf("%lld\n", ans);

    for (ll x = 1; x <= X; x++)
        ans += AB[x] * AC[x];
    for (ll y = 1; y <= Y; y++)
        ans += BA[y] * BC[y];
    for (ll z = 1; z <= Z; z++)
        ans += CA[z] * CB[z];

    //printf("%lld\n", ans);

    for (ll x = 1; x <= X; x++) {
        ll ry = AB[x], rz = AC[x];
        if (ry == 0 || rz == 0) continue;
        ll ly = CB[rz];
        ly = min(ly, ry);
        ans -= ly * rz + sumBC[ry] - sumBC[ly];
    }

    printf("%lld\n", ans);

    return 0;
}