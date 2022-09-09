#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
const int N=200050;
struct DSU{
	int p[N],sz[N],w[N];
	bool has;
	vector<int> bck;
	DSU(){}
	void init(int n){for(int i=1;i<=n;i++)p[i]=i,sz[i]=1,w[i]=0;has=0;bck.clear();}
	int Find(int x){return p[x]==x?x:Find(p[x]);}
	int W(int x){return p[x]==x?0:W(p[x])^w[x];}
	void AddEdge(int x,int y){
		int X=Find(x),Y=Find(y);
		if(X==Y){
			if(W(x)==W(y)&&!has){
				has=1;
				bck.pb(-1);
			}else bck.pb(0);
		}else{
			if(sz[X]>sz[Y])swap(x,y),swap(X,Y);
			p[X]=Y;
			sz[Y]+=sz[X];
			w[X]=W(x)^W(y)^1;
			bck.pb(X);
		}
	}
	void DelEdge(){
		int X=bck.back();
		bck.pop_back();
		if(X==0)return;
		if(X<0){
			has=0;
		}else{
			sz[p[X]]-=sz[X];
			w[X]=0;
			p[X]=X;
		}
	}
}G;
pii edg[N];
void AddEdge(int i){G.AddEdge(edg[i].first,edg[i].second);}
void DelEdge(){G.DelEdge();}
int l[N],r[N],ans[N];
int mn[N];
void Solve(int l,int r,int L,int R){
	if(l>r)return;
	int mid=l+r>>1;
	for(int i=l;i<mid;i++)AddEdge(i);
	int taj=-1;
	for(int i=R;i>=max(mid,L);i--){
		if(G.has){taj=i;break;}
		AddEdge(i);
	}
	if(taj==-1)taj=mid-1;
	mn[mid]=taj;
	for(int i=R;i>taj;i--)DelEdge();
	AddEdge(mid);
	Solve(mid+1,r,taj,R);
	for(int i=l;i<=mid;i++)DelEdge();
	for(int i=R;i>taj;i--)AddEdge(i);
	Solve(l,mid-1,L,taj);
	for(int i=R;i>taj;i--)DelEdge();
}
int main(){
	int n,m,q;
	scanf("%i %i %i",&n,&m,&q);
	for(int i=1;i<=m;i++)scanf("%i %i",&edg[i].first,&edg[i].second);
	G.init(n);
	for(int i=1;i<=q;i++)scanf("%i %i",&l[i],&r[i]);
	Solve(1,m,1,m);
	for(int i=1;i<=q;i++)printf(r[i]<=mn[l[i]]?"YES\n":"NO\n");
	return 0;
}