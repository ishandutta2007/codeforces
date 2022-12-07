#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int MX=840;
ll sum,W;
bitset<MX*16+5> f;
int main(){
	scanf("%lld",&W);
	f[0]=1;
	int cnt=0;
	For(i,1,8){
		ll cnt,s=MX/i;
		scanf("%lld",&cnt);
		int rem=cnt%(MX/i)+(cnt/s?s:0);
		For(j,1,rem) f|=f<<i;
		sum+=(cnt-rem)/s;
	}
	ll ans=0;
	For(i,0,MX*16) if (f[i]){
		if (i>W) continue;
		ll tms=min(sum,(W-i)/MX);
		ans=max(ans,i+tms*MX);
	}
	printf("%lld\n",ans);
}