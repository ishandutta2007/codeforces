#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define int long long

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int x[N] , y[N] , n , m , scc[N] , fa[N] , num[N] , ans = 0 , cnt , S[N] , Pow[N];

map<int,int>mx,my;
map<int,int>cx,cy;

int f[N] , t[N] , tot;

int getf(int x) {
	return (fa[x] == x) ? x : (fa[x] = getf(fa[x]));
}

main(void) {
	cin>>n;
	for(int i = 1;i <= n;i ++) cin>>x[i] >> y[i] , mx[x[i]] ++ , my[y[i]] ++;
	map<int,int>::iterator  it;
	for(int i = 1;i <= n * 2;i ++) fa[i] = i;
	for(it = mx.begin();it != mx.end();it ++) cx[it->first] = ++ cnt;
	for(it = my.begin();it != my.end();it ++) cy[it->first] = ++ cnt;
	for(int i = 1;i <= n;i ++) {
		f[++ tot] = cx[x[i]]; t[tot] = cy[y[i]];
		fa[getf(f[tot])] = getf(t[tot]);
	}
	for(int i = 1;i <= tot;i ++) {
		num[getf(f[i])] ++;
	}
	for(int i = 1;i <= cnt;i ++) S[getf(i)] ++;
	Pow[0] = 1ll;
	for(int i = 1;i <= n * 2;i ++) Pow[i] = Pow[i - 1] * 2ll % mod;
	ans = 1ll;
	for(int i = 1;i <= cnt;i ++) if(getf(i) == i) {
		if(S[i] - 1 == num[i]) {
			ans = ans * (Pow[S[i]] - 1) % mod;
			if(ans < 0) ans += mod;
		}
		else {
			ans = ans * (Pow[S[i]]) % mod;
		}
	}
	cout<<ans;
}