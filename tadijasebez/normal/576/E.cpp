#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
const int N=500050;
const int K=51;

struct DSU{
	int p[N],c[N],d[N];
	int bad=0;
	stack<int,vector<int>> stk;

	void init(){for(int i=0;i<N;i++)p[i]=i,c[i]=1,d[i]=0;}
	DSU(){init();}

	int Find(int x){return p[x]==x?x:Find(p[x]);}
	int Dep(int x){return p[x]==x?0:d[x]+Dep(p[x]);}

	void Union(int x,int y){
		int dx=Dep(x),dy=Dep(y);
		x=Find(x);y=Find(y);
		if(x==y){
			if((dx+dy+1)%2!=0)bad++,stk.push(-1);
			else stk.push(0);
			return;
		}
		if(c[x]>c[y])swap(x,y),swap(dx,dy);
		c[y]+=c[x];
		p[x]=y;
		d[x]=dx-dy+1;
		stk.push(x);
	}
	void Undo(){
		int x=stk.top();
		stk.pop();
		if(x>0){
			d[x]=0;
			c[p[x]]-=c[x];
			p[x]=x;
		}else bad+=x;
	}
	void Clear(){
		while(stk.size())Undo();
	}
}DS[K];

int u[N],v[N],col[N];
int qe[N],qc[N],q;
int nxt[N],las[N];

const int M=4*N;
vector<pii> ec[M];
void AddEdge(int c,int ss,int se,int qs,int qe,pii e){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){ec[c].pb(e);return;}
	int mid=ss+se>>1;
	AddEdge(c<<1,ss,mid,qs,qe,e);
	AddEdge(c<<1|1,mid+1,se,qs,qe,e);
}
void DFS(int c,int ss,int se){
	for(auto e:ec[c]){
		DS[e.first].Union(u[e.second],v[e.second]);
	}
	if(ss==se){
		DS[qc[ss]].Union(u[qe[ss]],v[qe[ss]]);
		if(DS[qc[ss]].bad==0)col[qe[ss]]=qc[ss],printf("YES\n");
		else printf("NO\n");
		AddEdge(1,1,q,ss+1,nxt[ss]-1,{col[qe[ss]],qe[ss]});
		DS[qc[ss]].Undo();
	}else{
		int mid=ss+se>>1;
		DFS(c<<1,ss,mid);
		DFS(c<<1|1,mid+1,se);
	}
	for(auto e:ec[c]){
		DS[e.first].Undo();
	}
}
int main(){
	int n,m,k;
	scanf("%i %i %i %i",&n,&m,&k,&q);
	for(int i=1;i<=m;i++)scanf("%i %i",&u[i],&v[i]);
	for(int i=1;i<=q;i++)scanf("%i %i",&qe[i],&qc[i]);
	for(int i=1;i<=m;i++)las[i]=q+1;
	for(int i=q;i>=1;i--){
		nxt[i]=las[qe[i]];
		las[qe[i]]=i;
	}
	DFS(1,1,q);
	return 0;
}