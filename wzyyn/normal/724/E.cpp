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
const int N=10005;
int n,m,S[N],T[N];
ll f[N],g[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&S[i]);
	For(i,1,n) scanf("%d",&T[i]);
	memset(f,100,sizeof(f));
	f[0]=0;
	For(i,1,n){
		memset(g,100,sizeof(g));
		For(j,0,i-1){
			g[j+1]=min(g[j+1],f[j]+T[i]);//inS
			g[j]=min(g[j],f[j]+S[i]+1ll*j*m);//inT;
		}
		memcpy(f,g,sizeof(f));
	}
	ll ans=1ll<<60;
	For(i,0,n) ans=min(ans,f[i]);
	printf("%lld\n",ans);
}
/*
*/