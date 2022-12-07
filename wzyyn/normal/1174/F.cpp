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
const int N=200005;
int fa[N],dep[N];
int sz[N],vis[N];
vector<int> e[N];
int n,dis,rt;
void dfs1(int x){
	for (auto i:e[x])
		if (i!=fa[x]){
			dep[i]=dep[x]+1;
			fa[i]=x;
			dfs1(i);
		}
}
void dfs(int x,int fa,int n){
	sz[x]=1;
	int mx=0;
	for (auto i:e[x])
		if (i!=fa&&!vis[i]){
			dfs(i,x,n);
			sz[x]+=sz[i];
			mx=max(mx,sz[i]);
		}
	if (mx*2<n&&sz[x]*2>=n)
		rt=x;
}
void divide(int x,int n){
	if (n==1){
		cout<<"! "<<x<<endl;
		exit(0);
	}
	dfs(x,0,n);
	vis[x=rt]=1;
	cout<<"d "<<x<<endl;
	int dd,sub;
	cin>>dd;
	if (!dd){
		cout<<"! "<<x<<endl;
		exit(0);
	}
	if (dd+dep[x]!=dis)
		sub=fa[x];
	else{
		cout<<"s "<<x<<endl;
		cin>>sub;
	}
	divide(sub,sz[sub]>sz[x]?n-sz[x]:sz[sub]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs1(1);
	cout<<"d "<<1<<endl;
	cin>>dis;
	divide(1,n);
}