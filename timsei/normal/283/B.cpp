#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

#define int long long

int n , a[N] , dp[N][2] , ans[N];
bool ba[N];
vector < pair<int,int> > G[N];

void dance(int x) {
    for(auto Q : G[x]) {
	int V = Q.first;
	ans[V] = ans[x] + Q.second;
	dance(V);
    }
}

void ban(int x) {
    ba[x] = 1;
    for(auto Q : G[x]) {
	int V = Q.first;
	ban(V);
    }
}

main(void) {
    cin >> n; for(int i = 2;i <= n;++ i) cin >> a[i];
    for(int i = 2;i <= n;++ i) {
	if(i + a[i] > n) dp[i][0] = -1; else G[i + a[i] + n].push_back(make_pair(i , a[i]));
	if(i - a[i] <= 0) dp[i][1] = -1;
	else
	if(i - a[i] == 1) dp[i][1] = -2;
	else G[i - a[i]].push_back(make_pair(i + n , a[i]));
    }
    for(int i = 2;i <= n * 2;++ i) ans[i] = -1;
    for(int i = 2;i <= n;++ i) {
	if(dp[i][0] == -1) {
	    ans[i] = a[i];
	    dance(i);
	}
	if(dp[i][1] == -1) ans[i + n] = a[i]  , dance(i + n);
	else if(dp[i][1] == -2) ban(i + n);
    }
    for(int i = 1;i < n;++ i) {
	int cur = i + 1;
	if(ba[cur + n] || ans[cur + n] == -1) {
	    puts("-1"); continue;
	}
        cout << ans[cur + n] + i << endl;
    }
}