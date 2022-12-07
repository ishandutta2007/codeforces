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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=200005;
vector<char> v[N];
vector<int> id[N];
vector<int> e[N];
vector<pii> opt[N];
int n,m,nd;
int dfn[N],ed[N];
int ind[N];
void add(int x,int y){
	e[x].PB(y);
	ind[y]=1;
}
void dfs(int x){
	dfn[x]=++*dfn;
	for (auto i:e[x]) dfs(i);
	ed[x]=*dfn;
}
void insert(int x,int y){
	if (dfn[x]>dfn[y]) swap(x,y);
	//cout<<x<<' '<<y<<' '<<dfn[x]<<' '<<dfn[y]<<endl;
	opt[dfn[x]].PB(pii(y,1));
	opt[ed[x]+1].PB(pii(y,-1));
}

int cov[N*8],t[N*8];
void push(int k,int l,int r){
	t[k]=(cov[k]?r-l+1:t[k*2]+t[k*2+1]);
}
void change(int k,int l,int r,int x,int y,int v){
	//if (l==1&&r==n*m) cout<<x<<' '<<y<<' '<<v<<endl;
	if (x<=l&&r<=y){
		cov[k]+=v;
		return push(k,l,r);
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	push(k,l,r);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,0,n+1) v[i].resize(m+2);
	For(i,0,n+1) id[i].resize(m+2);
	For(i,1,n){
		static char s[N];
		scanf("%s",s+1);
		For(j,1,m) v[i][j]=s[j];
	}
	For(i,1,n) For(j,1,m)
		id[i][j]=++nd;
	For(i,1,n) For(j,1,m)
		if (v[i][j]=='U'){
			if (i-1>=1&&i+1<=n) add(id[i-1][j],id[i+1][j]);
			if (i  >=1&&i+2<=n) add(id[i+2][j],id[i  ][j]);
		}
	For(i,1,n) For(j,1,m)
		if (v[i][j]=='L'){
			if (j-1>=1&&j+1<=m) add(id[i][j-1],id[i][j+1]);
			if (j  >=1&&j+2<=m) add(id[i][j+2],id[i][j  ]);
		}
	For(i,1,n) For(j,1,m)
		if ((i+j)%2==0&&!ind[id[i][j]])
			dfs(id[i][j]);
	For(i,1,n) For(j,1,m)
		if ((i+j)%2==1&&!ind[id[i][j]])
			dfs(id[i][j]);
	For(i,1,n) For(j,1,m){
		if (v[i][j]=='U') insert(id[i][j],id[i+1][j]);
		if (v[i][j]=='L') insert(id[i][j],id[i][j+1]);
	}
	ll ans=0;
	For(i,1,n*m/2){	
		for (auto j:opt[i])
			change(1,1,n*m,dfn[j.fi],ed[j.fi],j.se);
		ans+=t[1];
	}
	cout<<ans<<endl;
}