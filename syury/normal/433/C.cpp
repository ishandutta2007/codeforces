#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define y1 adjf
#define tm afhdhn

int n, m;
lint tot = 0ll;
lint ans = (lint)1e18;
vector<lint> wx;
vector<vector<int> > near;
vector<int> a;

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%d%d", &n, &m);
	if(n == 1){printf("0"); ret 0;}
	a.rs(m); wx.rs(n + 1); wx.asg(n + 1, 0); near.rs(n + 1);
	F(i, 0, m){
		scanf("%d", &a[i]);
		if(i == 0){cont;}
		if(a[i] != a[i - 1]){near[a[i - 1]].pb(a[i]); near[a[i]].pb(a[i - 1]);}
		tot += llabs(a[i] - a[i - 1]);
		wx[a[i - 1]] += llabs(a[i] - a[i - 1]);
		if(a[i] != a[i - 1]){wx[a[i]] += llabs(a[i] - a[i - 1]);}
	}
	ans = tot;
	F(i, 1, n + 1){
		if(near[i].empty()){cont;}
		sort(near[i].begin(), near[i].end());
		int fv = near[i][near[i].size()/2];
		int sv = near[i][min((int)near[i].size()/2 + 1, (int)near[i].size() - 1)];
		lint curr1 = 0ll, curr2 = 0ll;
		F(j, 0, (int)near[i].size()){
			curr1 += llabs(near[i][j] - fv); curr2 += llabs(near[i][j] - sv);
		}
		curr1 = min(curr1, curr2);
		ans = min(ans, tot - wx[i] + curr1);
	}
	printf("%lld", ans);
	ret 0;
}