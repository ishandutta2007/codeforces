#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

const ll INF = 1e18;
const int MAXN = 1005;

ll v[MAXN][MAXN];

ll vv[2][MAXN * MAXN];
ll sum[2][MAXN * MAXN];

set<pair<ll, int> > st[2];
set<pair<ll, int> > ::iterator it;

void solve(){
    int n, m, i, j, k;
    ll p;
    scanf("%d%d%d%lld", &n, &m, &k, &p);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%lld", &v[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        ll s = 0;
        for(j = 0; j < m; j++){
            s += v[i][j];
        }
        st[0].insert(mp(s, i));
    }
    for(j = 0; j < m; j++){
        ll s = 0;
        for(i = 0; i < n; i++){
            s += v[i][j];
        }
        st[1].insert(mp(s, j));
    }
    for(int l = 0; l < 2; l++){
        for(i = 1; i <= k; i++){
            it = st[l].end();
            it--;
            vv[l][i] = it->first;
            sum[l][i] = sum[l][i - 1] + vv[l][i];
            st[l].insert(mp(it->first - p * ((l == 0) ? m : n), it->second));
            st[l].erase(it);
        }
    }
    ll ans = -INF;
    for(i = 0; i <= k; i++){
        //printf("%lld %lld\n", sum[0][i], sum[1][i]);
        ll tmp = sum[0][i] + sum[1][k - i] - p * (ll)i * (ll)(k - i);
        ans = max(ans, tmp);
    }
    cout << ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = 1;
    while(t--){
        solve();    
    }
}