#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int n;
ll a[200005];
map<ll,ll> mp;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	mp.insert(pll(a[1],0));
	For(i,1,n-1){
		auto j=mp.upper_bound(a[i+1]);
		for (;j!=mp.end();){
			ll &f0=mp[a[i+1]];
			f0=max(f0,j->se+(j->fi/a[i+1]-1)*a[i+1]*i);
			if (j->fi%(a[i+1])){
				ll &f1=mp[j->fi%a[i+1]];
				f1=max(f1,j->se+j->fi/a[i+1]*a[i+1]*i);
			}
			mp.erase(j++);
		}
	}
	ll ans=0;
	for (auto i:mp)
		ans=max(ans,n*i.fi+i.se-n);
	printf("%lld\n",ans);
}