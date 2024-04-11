#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 5005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,x,y,t[N],cnt[N],mn[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n) mn[i] = 1e7, cnt[i] = 0;
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		cnt[x]++, mn[x] = min(mn[x], y>x ? y : y+n);
	}
	rep(i,1,n) t[i] = cnt[i] ? (cnt[i] - 1) * n + mn[i] - i : 0;
	//rep(i,1,n)cout<<t[i]<<" ";cout<<endl;
	rep(i,1,n){
		int ans = 0;
		rep(j,0,n-1){
			int x = (i+j-1) % n + 1;
			if(t[x]) ans = max(ans, t[x]+j);
			//cout<<i<<" "<<j<<" "<<x<<endl;
		}
		printf("%d ",ans);
	}
	return 0;
}