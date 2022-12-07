#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=200005;
const int mo=998244353;
int f[N],g[N],p[N],fP[N],iP[N];
int n,Q,ans,vis[N];
set<int> S;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int Func(int l,int r){
	int v1=1ll*(f[r]+mo-f[l-1])*iP[r]%mo;
	int v2=1ll*(g[r]+mo-g[l-1])*iP[r]%mo;
	return (v2+1ll*(r-l+1)+mo-1ll*v1*(l-1)%mo)%mo;
}
void insert(int x){
	set<int>::iterator pre,nxt;
	nxt=S.lower_bound(x); pre=nxt; pre--;
	ans=(ans+mo-Func(*pre,*nxt-1))%mo;
	ans=(ans+Func(*pre,x-1))%mo;
	ans=(ans+Func(x,*nxt-1))%mo;
	S.insert(x);
}
void erase(int x){
	S.erase(x);
	set<int>::iterator pre,nxt;
	nxt=S.lower_bound(x); pre=nxt; pre--;
	ans=(ans+Func(*pre,*nxt-1))%mo;
	ans=(ans+mo-Func(*pre,x-1))%mo;
	ans=(ans+mo-Func(x,*nxt-1))%mo;
}
int main(){
	scanf("%d%d",&n,&Q);
	S.insert(1); S.insert(n+1);
	vis[1]=vis[n+1]=fP[0]=1;
	int Inv=power(100,mo-2);
	For(i,1,n){
		scanf("%d",&p[i]);
		p[i]=1ll*p[i]*Inv%mo;
	}
	For(i,1,n) fP[i]=1ll*fP[i-1]*p[i]%mo;
	iP[n]=power(fP[n],mo-2);
	Rep(i,n,1) iP[i-1]=1ll*iP[i]*p[i]%mo;
	For(i,1,n) f[i]=(f[i-1]+1ll*fP[i-1]*(1+mo-p[i]))%mo;
	For(i,1,n) g[i]=(g[i-1]+1ll*fP[i-1]*(1+mo-p[i])%mo*i)%mo;
	ans=Func(1,n);
	//printf("%d\n",ans);
	while (Q--){
		int x;
		scanf("%d",&x);
		if (vis[x]) erase(x);
		else insert(x);
		vis[x]^=1;
		printf("%d\n",ans);
	}
}