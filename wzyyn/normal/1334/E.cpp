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
const int mo=998244353;
ll di[65],W;
int S[65];
int C[65][65];
void init(){
	For(i,0,60) C[i][0]=1;
	For(i,1,60) For(j,1,i)
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	scanf("%lld",&W);
	for (int i=2;1ll*i*i<=W;i++)
		if (W%i==0){
			di[++*di]=i;
			for (;W%i==0;W/=i);
		}
	if (W!=1)
		di[++*di]=W;
}
void solve(){
	ll x,y;
	scanf("%lld%lld",&x,&y);
	memset(S,0,sizeof(S));
	For(i,1,*di) for (;x%di[i]==0;x/=di[i]) ++S[i];
	For(i,1,*di) for (;y%di[i]==0;y/=di[i]) --S[i];
	int sum1=0,sum2=0,ans=1;
	For(i,1,*di)
		if (S[i]>=0){
			ans=1ll*ans*C[sum1+S[i]][S[i]]%mo;
			sum1+=S[i];
		}
		else{
			ans=1ll*ans*C[sum2-S[i]][-S[i]]%mo;
			sum2-=S[i];
		}
	printf("%d\n",ans);
}
int main(){
	init();
	int Q;
	scanf("%d",&Q);
	while (Q--) solve();
}