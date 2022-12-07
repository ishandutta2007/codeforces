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
#define double long double
using namespace std;

const int N=1<<20|5;
int n,a[N],b[N];
int fa[N],p[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool check(int v){
	int m=(1<<v)-1;
	For(i,0,m) fa[i]=i,p[i]=0;
	For(i,1,n){
		int p1=a[i]&m,p2=b[i]&m;
		fa[get(p1)]=get(p2);
		++p[p1]; ++p[p2];
	}
	For(i,0,m) if (p[i]&1) return 0;
	int p=get(a[1]&m);
	For(i,1,n){
		if (get(a[i]&m)!=p) return 0;
		if (get(a[i]&m)!=p) return 0;
	}
	return 1;
}
vector<pii> e[N];
int ans[N],top,vis[N];
void dfs(int x){
	for (;e[x].size();){
		pii tmp=e[x].back();
		e[x].pop_back();
		if (!vis[tmp.se>>1]){
			vis[tmp.se>>1]=1;
			dfs(tmp.fi);
			ans[++top]=tmp.se^1;
			ans[++top]=tmp.se;
		}
	}
}
void construct(int v){
	cout<<v<<endl;
	int m=(1<<v)-1;
	For(i,1,n){
		a[i]&=m; b[i]&=m;
		e[a[i]].PB(pii(b[i],i*2-2));
		e[b[i]].PB(pii(a[i],i*2-1));
	}
	dfs(a[1]&m);
	For(i,1,top)
		cout<<ans[i]+1<<' ';
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&a[i],&b[i]);
	int l=1,r=20,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	construct(ans);
}