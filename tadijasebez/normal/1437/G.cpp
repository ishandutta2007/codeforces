#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=300050;
int go[N][26],link[N],root,tsz;
vector<int> E[N];
int Add(int&c,char*s,int len){
	if(!c)c=++tsz;
	if(!len)return c;
	return Add(go[c][s[0]-'a'],s+1,len-1);
}
int sz[N],dep[N],lid[N],rid[N],tid,head[N],par[N];
void DFS(int u){
	sz[u]=1;
	for(int v:E[u]){
		dep[v]=dep[u]+1;
		par[v]=u;
		DFS(v);
		sz[u]+=sz[v];
	}
}
void HLD(int u){
	if(!head[u])head[u]=u;
	lid[u]=++tid;
	int hc=0;
	for(int v:E[u])if(sz[v]>sz[hc])hc=v;
	if(hc){
		head[hc]=head[u];
		HLD(hc);
	}
	for(int v:E[u])if(v!=hc)HLD(v);
	rid[u]=tid;
}
void Build(){
	link[root]=root;
	queue<int> q;
	for(int i=0;i<26;i++){
		if(go[root][i]){
			q.push(go[root][i]);
			link[go[root][i]]=root;
		}else go[root][i]=root;
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(go[u][i]){
				link[go[u][i]]=go[link[u]][i];
				q.push(go[u][i]);
			}else go[u][i]=go[link[u]][i];
		}
	}
	for(int i=2;i<=tsz;i++)E[link[i]].pb(i);
	DFS(root);
	HLD(root);
}
namespace SegmentTree{
	const int M=2*N;
	int ls[M],rs[M],tsz,root,mx[M];
	void init(){
		for(int i=0;i<M;i++)mx[i]=-1;
	}
	void Set(int&c,int ss,int se,int qi,int x){
		if(!c)c=++tsz;
		if(ss==se){
			mx[c]=x;
			return;
		}
		int mid=ss+se>>1;
		if(qi<=mid)Set(ls[c],ss,mid,qi,x);
		else Set(rs[c],mid+1,se,qi,x);
		mx[c]=max(mx[ls[c]],mx[rs[c]]);
	}
	void Set(int qi,int x){Set(root,1,tid,qi,x);}
	int Get(int c,int ss,int se,int qs,int qe){
		if(qs>qe||qs>se||ss>qe)return -1;
		if(qs<=ss&&qe>=se)return mx[c];
		int mid=ss+se>>1;
		return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
	}
	int Get(int qs,int qe){return Get(root,1,tid,qs,qe);}
}
multiset<int> vals[N];
void Set(int u){
	SegmentTree::Set(lid[u],*vals[u].rbegin());
}
int Get(int u){
	int ans=-1;
	while(u){
		ans=max(ans,SegmentTree::Get(lid[head[u]],lid[u]));
		u=par[head[u]];
	}
	return ans;
}
int node[N],val[N];
char s[N];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		node[i]=Add(root,s,strlen(s));
	}
	Build();
	SegmentTree::init();
	for(int i=1;i<=n;i++)vals[node[i]].insert(0),Set(node[i]);
	while(m--){
		int t;
		scanf("%i",&t);
		if(t==1){
			int i,x;
			scanf("%i %i",&i,&x);
			vals[node[i]].erase(vals[node[i]].find(val[i]));
			val[i]=x;
			vals[node[i]].insert(val[i]);
			Set(node[i]);
		}else{
			scanf("%s",s);
			int len=strlen(s);
			int atnode=root,ans=-1;
			for(int i=0;i<len;i++){
				atnode=go[atnode][s[i]-'a'];
				ans=max(ans,Get(atnode));
			}
			printf("%i\n",ans);
		}
	}
	return 0;
}