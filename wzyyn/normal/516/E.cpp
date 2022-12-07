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
vector<int> a[N],b[N];
int n,m,G,T[N];
map<int,ll> f,g;
ll ans; 
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void exgcd(int x,int y,int &a,int &b){
	if (!y){
		a=1; b=0;
		return;
	}
	exgcd(y,x%y,b,a);
	b-=(x/y)*a;
}
int getinv(int x,int y){
	int a,b;
	exgcd(x,y,a,b);
	return (a%y+y)%y;
}
void solve(vector<int> a,vector<int> b,int inv,int n,int m){
	f.clear(); g.clear();
	For(i,0,a.size()-1){
		int x=1ll*a[i]/G*inv%n;
		if (g.find(x)!=g.end())
			g[x]=min(g[x],a[i]+0ll); 
		else g[x]=a[i];
		f[x]=1;
	}
	For(i,0,b.size()-1){
		int x=1ll*b[i]/G*inv%n;
		if (g.find(x)!=g.end())
			g[x]=min(g[x],b[i]+0ll); 
		else g[x]=b[i];
	}
	map<int,ll>::iterator it;
	*T=0;
	for (it=g.begin();it!=g.end();++it)
		T[++*T]=it->fi;
	int px=1,py=0;
	For(i,1,2*(*T)){
		px=px%(*T)+1; py=py%(*T)+1;
		g[T[px]]=min(g[T[px]],g[T[py]]+1ll*(T[px]-T[py]+n)%n*m*G);
	}
	For(i,1,*T){
		int x=i%(*T)+1,t=(T[x]+n-1)%n;
		//printf("%d %d %d %d\n",i,x,*T,t);
		if (f.find(t)==f.end())
			ans=max(ans,g[T[i]]+1ll*(t-T[i]+n)%n*m*G);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	G=gcd(n,m); n/=G; m/=G;
	if (G>200000) return puts("-1"),0;
	int invn=getinv(n,m);
	int invm=getinv(m,n);
	int T,x;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&x);
		a[x%G].PB(x);
	}
	scanf("%d",&T);
	while (T--){
		scanf("%d",&x);
		b[x%G].PB(x);
	}
	For(i,0,G-1){
		if (!a[i].size()&&!b[i].size())
			return puts("-1"),0;
		solve(a[i],b[i],invm,n,m);
		solve(b[i],a[i],invn,m,n);
	}
	printf("%lld\n",ans);
}