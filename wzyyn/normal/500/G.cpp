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
const ll INF=1ll<<40;
const int N=200005;
vector<int> e[N];
int n,tot,dep[N],fa[N][20];
void dfs(int x){
	for (auto i:e[x])
		if (i!=fa[x][0]){
			fa[i][0]=x;
			dep[i]=dep[x]+1;
			dfs(i);
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	Rep(i,17,0) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,17,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
int Mx(int x,int y){
	return dep[x]>dep[y]?x:y;
}

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void exgcd(int x,int y,ll &a,ll &b){
	if (!y){
		a=1,b=0;
		return;
	}
	exgcd(y,x%y,b,a);
	b-=x/y*a;
}
 
ll SAME(int a,int b,int c,int d){
	c-=a; ll k,p;
	int G=gcd(b,d);
	exgcd(b,d,k,p);
	if (c%G) return INF;
	k*=c/G,p*=-(c/G);
	ll ad=d/G,ab=b/G;
	if (k<0){
		ll ti=max((-k-1)/ad+1,(-p-1)/ab+1);
		k+=ad*ti; p+=ab*ti;
	}
	ll ti=min(k/ad,p/ab);
	k-=ad*ti,p-=ab*ti;
	return b*k+a;
}
 
ll leiGCD(ll L,ll D,ll R,ll P){
	if (!L) return 0;
	if (!D) return INF;
	if (2*D>P) return leiGCD(P-R,P-D,P-L,P);
	if ((L-1)/D<R/D) return (L+D-1)/D;
	ll tmp=leiGCD(L%D,D-P%D,R%D,D);
	return tmp==INF?INF:(tmp*P+L+D-1)/D;
}
 
ll DIFF(ll t1,ll f1,ll t4,ll f2,ll d){
	if ((d+t1+t4)&1) return INF;
	int l=((t4-t1-d)%f2+f2)%f2;
	int r=((t4-t1+d)%f2+f2)%f2;
	ll tmp=0;
	if (f2!=2*d&&l<=r&&l)
		if ((l-1)/gcd(f1,f2)>=r/gcd(f1,f2)) tmp=INF;
		else tmp=leiGCD(l,f1%f2,r,f2);
	ll q=(tmp*f1+t1+d-t4)/f2;
	return (d+tmp*f1+q*f2+t1+t4)/2;
}


void solve(){
	int u,v,x,y;
	scanf("%d%d%d%d",&u,&v,&x,&y);
	int L1=Mx(LCA(u,x),LCA(u,y));
	int L2=Mx(LCA(v,x),LCA(v,y));
	int p=Mx(LCA(u,v),LCA(x,y));
	if (dep[L1]<dep[p]&&dep[L2]<dep[p])
		return puts("-1"),void(0);
	L1=Mx(L1,p); L2=Mx(L2,p);
	int t1=dis(L1,u),t2=dis(L2,u);
	int t3=dis(L1,x),t4=dis(L2,x);
	int f1=dis(u,v)*2,f2=dis(x,y)*2;
	int d=dis(L1,L2);
	t1>t2?t1=f1-t1:t2=f1-t2;
	t3>t4?t3=f2-t3:t4=f2-t4;
	ll ans=INF;
	ans=min(ans,SAME(t1,f1,t3,f2));
	ans=min(ans,SAME(t2,f1,t4,f2));
	ans=min(ans,DIFF(t1,f1,t4,f2,d));
	ans=min(ans,DIFF(t2,f1,t3,f2,d));
	printf("%lld\n",ans==INF?-1:ans);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	For(i,1,17) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	int Q;
	scanf("%d",&Q);
	while (Q--) solve();
}