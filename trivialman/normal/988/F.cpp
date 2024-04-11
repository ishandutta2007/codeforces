#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 2005;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dat{
	int l, r;
}seg[N];

int a, n, m, x, p, r, k;
int um[N], dp[N][2]; 

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>a>>n>>m;
	rep(i,1,n) cin>>seg[i].l>>seg[i].r;
	sort(seg+1,seg+n+1,[](dat x,dat y){return x.l<y.l;});
	seg[n+1] = {INF, INF};
	//rep(i,1,n)cout<<seg[i].l<<" "<<seg[i].r<<endl;
	
	rep(i,0,a) um[i] = dp[i][0] = dp[i][1] = INF;
	rep(i,1,m){
		cin>>x>>p;
		um[x] = min(um[x], p);
	}
	
	r = 0, k = 1;
	rep(i,0,a){
		if(i>=seg[k].r) r = seg[k++].r;
		
		rep(j,0,i) if(um[j]<INF) dp[i][1] = min(dp[i][1], min(dp[j][0],dp[j][1]) + (i-j) * um[j]);
		if(i<=seg[k].l) dp[i][0] = (k==1 ? 0 : dp[r][1]);
		//cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	int ans = min(dp[a][0],dp[a][1]);
	cout<<(ans==INF?-1:ans);
	return 0;
}