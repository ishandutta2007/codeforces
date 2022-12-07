#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=100005;
int n;
ll t[N],x[N];
void solve(){
	int n;
	scanf("%d",&n);
	For(i,1,n) scanf("%lld%lld",&t[i],&x[i]);
	t[n+1]=1ll<<35;
	ll loc=0,aim=0,ans=0;
	For(i,1,n)
		if (loc==aim){
			aim=x[i];
			ll tt=min(abs(loc-aim),t[i+1]-t[i]);
			if (aim<loc) loc-=tt;
			else loc+=tt;
			if (aim==loc) ++ans;
		}
		else{
			ll tt=min(abs(loc-aim),t[i+1]-t[i]);
			ll nt=(aim<loc?loc-tt:loc+tt);
			if (min(loc,nt)<=x[i]&&x[i]<=max(loc,nt)) ++ans;
			loc=nt;
		}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}