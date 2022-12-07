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
ll C[25][25],cnt[25],q[25];
void init(){
	For(i,0,20) C[i][0]=1;
	For(i,1,20) For(j,1,i) C[i][j]=C[i-1][j]+C[i-1][j-1];
}
ll F(ll x){
	if (cnt[x]||cnt[x+1]) return 0;
	ll rem=0,ans=1;
	Rep(i,x-1,0){
		rem++;
		ans*=C[rem][cnt[i]];
		rem-=cnt[i];
	}
	return ans;
}
void solve(){
	memset(cnt,0,sizeof(cnt));
	ll x;
	scanf("%lld",&x);
	int tp=0;
	for (;x;){
		++tp;
		++cnt[x%tp];
		x/=tp;
	}
	//For(i,0,tp) printf("%d ",cnt[i]); puts("");
	ll ans=F(tp)-1;
	//printf("%lld\n",ans);
	if (cnt[0]) --cnt[0],ans-=F(tp-1);
	printf("%lld\n",ans);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
3
1
11
123456
*/