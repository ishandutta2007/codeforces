#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 30000
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q;


ll b[100500];
vector<ll> g, f;
ll a[400500];
ll pa[400500][22], sum[22], pr[22][22];
ll dp[N+15];
ll get_sum(ll num, ll l, ll r) {
    return pa[r+1][num] - pa[l][num];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 1; j <= 20; j++) {
            pa[i + 1][j] = pa[i][j];
        }
        pa[i+1][a[i]]++;
        for (int j = 1; j <= 20; j++) {
            pr[a[i]][j] += get_sum(j, 0, i);
        }
        sum[a[i]]++;
    }
    //cout << pr[4][2] << endl;


    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        dp[i] = 1LL * MOD * MOD;
    }
    for (int i = 0; i < N; i++) {
        ll sm = 0;
        for (int j = 0; j < 20; j++) {
            if ((i >> j) & 1) {
                sm += sum[j+1];
            }
        }
        for (int j = 0; j < 20; j++) {
            if (!((i>>j)&1)) {
                ll need = 0;
                for (int k = 0; k < 20; k++) {
                    if (k != j && !((i>>k)&1)) {
                        need += pr[j + 1][k + 1];
                    }
                }
                dp[i | (1<<j)] = min(dp[i | (1<<j)], dp[i] + need);
            }
        }
    }
    cout << dp[N-1] << endl;


    return 0;
}