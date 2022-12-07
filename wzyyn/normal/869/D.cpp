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
const int mo=1000000007;
const int N=1005;
vector<int> e[N];
int vis[N],sz[N];
int n,m,ans,nd;
int x[10],y[10];
map<int,int> mp;
int getid(int x){
	return mp[x]?mp[x]:mp[x]=++nd;
}
int F(int x){
	int l=x,r=x,ans=0;
	for (;l<=n;l=l*2,r=r*2+1)
		ans+=min(r,n)-l+1;
	return ans;
}
void init(int x,int fa){
	for (auto i:e[x])
		if (i!=fa){
			sz[x]-=sz[i];
			init(i,x);
			//sz[x]-=sz[i];
		}
}
int FF(int x){
	int ans=sz[x];
	vis[x]=1;
	for (auto i:e[x])
		if (!vis[i])
			ans=(ans+FF(i))%mo;
	vis[x]=0;
	return ans;
}
void add(int x,int y){
	e[x].PB(y);
	e[y].PB(x);
}
int main(){
	scanf("%d%d",&n,&m);
	getid(1);
	For(i,1,m){
		scanf("%d%d",&x[i],&y[i]);
		for (int p=x[i];p;getid(p),p/=2);
		for (int p=y[i];p;getid(p),p/=2);
	}
	for (auto i:mp){
		if (i.fi>1) add(i.se,getid(i.fi/2));
		sz[i.se]=F(i.fi);
		//cout<<i.se<<' '<<i.fi<<' '<<sz[i.se]<<endl;
	}
	init(1,0);
	For(i,1,m) add(getid(x[i]),getid(y[i]));
	For(i,1,nd) ans=(ans+1ll*sz[i]*FF(i))%mo;
	printf("%d\n",ans);
}