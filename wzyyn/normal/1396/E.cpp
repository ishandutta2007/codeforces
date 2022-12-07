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
const int N=100005;
int n,fa[N],id[N];
int f[N],sz[N],tab[N];
vector<int> e[N];
set<int> S[N];
ll k,lo,hi;
void dfs(int x){
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dfs(i);
			sz[x]+=sz[i];
			f[i]=min(sz[i],n-sz[i]);
			lo+=sz[i]&1; hi+=f[i];
		}
}
int q[N],q1[N],q2[N];
void merge(int &x,int &y){
	if (S[x].size()<S[y].size()) swap(x,y);
	for (auto i:S[y]) S[x].insert(i);
}
void dfs2(int x){
	for (auto i:e[x])
		if (i!=fa[x]) dfs2(i);
	q[0]=1; q[1]=x; int sz=1;
	id[x]=x; S[x].insert(x);
	for (auto i:e[x])
		if (i!=fa[x])
			q[++*q]=i,sz+=f[i];
	int ned=(sz-f[x])/2;
	int p1=1,p2=*q;
	For(j,1,ned){
		for (;!S[id[q[p1]]].size();++p1);
		q1[j]=*S[id[q[p1]]].begin();
		S[id[q[p1]]].erase(q1[j]);
		for (;!S[id[q[p2]]].size();--p2);
		q2[j]=*S[id[q[p2]]].begin();
		S[id[q[p2]]].erase(q2[j]);
	}
	for (auto i:e[x])
		if (i!=fa[x])
			merge(id[x],id[i]);
	For(j,1,ned)
		printf("%d %d\n",q1[j],q2[ned-j+1]);
}
int main(){
	scanf("%d%lld",&n,&k);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	if (k<lo||k>hi||(k+lo)%2)
		return puts("NO"),0;
	puts("YES");
	For(i,2,n) ++tab[f[i]];
	int p=n;
	for (;p>=2;--p)
		if (hi-2*tab[p]>=k){
			tab[p-2]+=tab[p];
			hi-=2*tab[p];
		}
		else break;
	For(i,2,n) f[i]=min(f[i],p-(p+f[i])%2);
	For(i,2,n) if (f[i]==p&&hi>k) hi-=2,f[i]-=2;
	//For(i,1,n) cout<<f[i]<<' '; cout<<endl;
	//cout<<p<<endl;
	dfs2(1);
}