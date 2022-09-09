#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=300050;
const int M=2*N;
struct DSU{
	int sz[M][2],p[M],cnt[M];
	ll sum;
	void init(){sum=0;for(int i=0;i<M;i++)p[i]=i,cnt[i]=1,sz[i][i>N]=1;}
	vector<int> bck;
	vector<ll> las;
	void del(int x){sum-=(ll)sz[x][0]*sz[x][1];}
	void add(int x){sum+=(ll)sz[x][0]*sz[x][1];}
	int Find(int x){return p[x]==x?x:Find(p[x]);}
	void Union(int x,int y){
		las.pb(sum);
		x=Find(x);y=Find(y);
		if(x==y){bck.pb(0);return;}
		if(cnt[x]>cnt[y])swap(x,y);
		del(x);del(y);
		p[x]=y;
		bck.pb(x);
		cnt[y]+=cnt[x];
		sz[y][0]+=sz[x][0];
		sz[y][1]+=sz[x][1];
		add(y);
	}
	void Undo(){
		sum=las.back();
		las.pop_back();
		int i=bck.back();
		bck.pop_back();
		if(i){
			cnt[p[i]]-=cnt[i];
			sz[p[i]][0]-=sz[i][0];
			sz[p[i]][1]-=sz[i][1];
			p[i]=i;
		}
	}
}DS;
vector<pair<int,int>> E[M];
int ls[M],rs[M],tsz,root;
void Set(int &c,int ss,int se,int qs,int qe,int x,int y){
	if(qs>qe || qs>se || ss>qe)return;
	if(!c)c=++tsz;
	if(qs<=ss && qe>=se){E[c].pb({x,y+N});return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,x,y);
	Set(rs[c],mid+1,se,qs,qe,x,y);
}
void Solve(int c,int ss,int se){
	for(auto p:E[c])DS.Union(p.first,p.second);
	if(ss==se){
		printf("%lld ",DS.sum);
	}else{
		int mid=ss+se>>1;
		Solve(ls[c],ss,mid);
		Solve(rs[c],mid+1,se);
	}
	for(auto p:E[c])DS.Undo();
}
int main(){
	DS.init();
	int q;
	scanf("%i",&q);
	map<pair<int,int>,int> tme;
	for(int i=1,x,y;i<=q;i++){
		scanf("%i %i",&x,&y);
		if(tme.count({x,y}))
			Set(root,1,q,tme[{x,y}],i-1,x,y),
			tme.erase({x,y});
		else
			tme[{x,y}]=i;
	}
	for(auto it:tme)Set(root,1,q,it.second,q,it.first.first,it.first.second);
	Solve(root,1,q);
	return 0;
}