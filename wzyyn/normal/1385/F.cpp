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
int n,k,ans,f[N];
vector<int> e[N];
void dfs(int x,int fa){
	int s1=0,s2=0;
	f[x]=0;
	for (auto i:e[x])
		if (i!=fa){
			dfs(i,x);
			f[i]?++s2:++s1;
		}
	ans+=s1/k; s1%=k;
	f[x]=s1|s2;
}
void solve(){
	ans=0;
	scanf("%d%d",&n,&k);
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	if (k==1){
		printf("%d\n",n-1);
		return;
	}
	int p=0;
	For(i,1,n)
		if (e[i].size()%k!=1)
			p=i;
	if (!p){
		For(i,1,n)
			if (e[i].size()!=1)
				p=i;
		dfs(p,0);
		printf("%d\n",ans);
		return;
	} 
	dfs(p,0);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}