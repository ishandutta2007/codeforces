#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=600050;
const int M=2*N;
const int H=50050*16*16;
const int L=21;
const int lim=50050;
struct Node
{
	char *s;int sz,link;
	vector<int> id;
	map<char,int> go;
	Node(){}
} node[M];
int stsz,root,par[M][L],dep[M];
map<int,int> my[lim];
int MakeNode(char *s, int sz){ stsz++;node[stsz].s=s;node[stsz].sz=sz;node[stsz].link=1;return stsz;}
void MakeRoot(){ root=MakeNode(NULL,0);}
void Add(char *s, int n, int id)
{
	if(!root) MakeRoot();
	int atnode=root,atlen=0,atedge=0,pnode=0,pleaf=0;
	for(int i=0;i<=n;i++)
	{
		while(1)
		{
			int tonode=atedge==n?0:node[atnode].go[s[atedge]];
			if(tonode && atlen>=node[tonode].sz)
			{
				atlen-=node[tonode].sz;
				atedge+=node[tonode].sz;
				atnode=tonode;
				continue;
			}
			if(!tonode)
			{
				if(i==n)
				{
					node[atnode].id.pb(id);
					if(pleaf) node[pleaf].link=atnode;pleaf=0;
				}
				else
				{
					int leaf=MakeNode(s+i,n-i);
					node[atnode].go[s[i]]=leaf;
					node[leaf].id.pb(id);
					if(pleaf) node[pleaf].link=leaf;pleaf=leaf;
				}
				if(pnode) node[pnode].link=atnode;pnode=0;
			}
			else if(i==n || node[tonode].s[atlen]!=s[i])
			{
				int inode=MakeNode(node[tonode].s,atlen);
				node[tonode].sz-=atlen;node[tonode].s+=atlen;
				node[atnode].go[node[inode].s[0]]=inode;
				node[inode].go[node[tonode].s[0]]=tonode;
				if(i==n)
				{
					node[inode].id.pb(id);
					if(pleaf) node[pleaf].link=inode;pleaf=0;
				}
				else
				{
					int leaf=MakeNode(s+i,n-i);
					node[inode].go[node[leaf].s[0]]=leaf;
					node[leaf].id.pb(id);
					if(pleaf) node[pleaf].link=leaf;pleaf=leaf;
				}
				if(pnode) node[pnode].link=inode;pnode=inode;
			}
			else
			{
				if(pnode) node[pnode].link=atnode;pnode=0;
				atlen++;
				break;
			}
			if(atnode==root)
			{
				atedge++;
				if(atlen) atlen--;
				else break;
			}
			else atnode=node[atnode].link;
		}
	}
}
void DFS(int u, int p, int d)
{
	d+=node[u].sz;
	par[u][0]=p;
	dep[u]=d;
	for(int i:node[u].id) my[i][d]=u;
	for(int i=1;i<L;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(auto f:node[u].go) if(f.second && f.second!=p) DFS(f.second,u,d);
}
struct Query{ int id,l,r;Query(int a=0, int b=0, int c=0){ id=a,l=b,r=c;}};
vector<Query> Qs[M];
pair<int,int> mx[H];
int ls[H],rs[H],tsz,rt[M],id[M],isz;
pair<int,int> best(pair<int,int> a, pair<int,int> b){ if(a.first==b.first) return a.second<b.second?a:b;return a.first>b.first?a:b;}
void Set(int &c, int ss, int se, int qi)
{
	if(qi==0) return;
	if(!c) c=++tsz;
	if(ss==se){ mx[c].first++;mx[c].second=qi;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
	mx[c]=best(mx[ls[c]],mx[rs[c]]);
}
pair<int,int> Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || ss>qe || qs>se) return mp(0,0);
	if(qs<=ss && qe>=se) return mx[c];
	int mid=ss+se>>1;
	return best(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
vector<int> all[M];
pair<int,int> ans[N];
void Solve(int u, int p)
{
	int HC=0;
	for(auto f:node[u].go) if(f.second && f.second!=p)
	{
		Solve(f.second,u);
		if(!HC || all[id[f.second]].size()>all[id[HC]].size()) HC=f.second;
	}
	if(!HC) rt[u]=0,id[u]=++isz;
	else rt[u]=rt[HC],id[u]=id[HC];
	for(int i:node[u].id) Set(rt[u],1,lim,i),all[id[u]].pb(i);
	for(auto f:node[u].go) if(f.second && f.second!=p && f.second!=HC)
	{
		for(int i:all[id[f.second]]) Set(rt[u],1,lim,i),all[id[u]].pb(i);
	}
	for(Query q:Qs[u]) ans[q.id]=Get(rt[u],1,lim,q.l,q.r);
}
char s[N];
int sz[lim],st[lim];
int bl[N],br[N];
int main()
{
	int n,m,q,i,j,l,r,pl,pr;
	scanf("%s",s);n=strlen(s);
	scanf("%i",&m);st[1]=n;
	for(i=1;i<=m;i++) scanf("%s",s+st[i]),sz[i]=strlen(s+st[i]),st[i+1]=st[i]+sz[i];
	Add(s,n,0);
	for(i=1;i<=m;i++) Add(s+st[i],sz[i],i);
	DFS(root,0,0);
	scanf("%i",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i %i %i",&l,&r,&pl,&pr);
		bl[i]=l;br[i]=r;
		int len=pr-pl+1,pos=n-pl+1;
		int nod=my[0][pos];
		for(j=L-1;~j;j--) if(dep[par[nod][j]]>=len) nod=par[nod][j];
		Qs[nod].pb(Query(i,l,r));
	}
	Solve(root,0);
	for(i=1;i<=q;i++)
	{
		if(ans[i].first==0) printf("%i %i\n",bl[i],0);
		else printf("%i %i\n",ans[i].second,ans[i].first);
	}
	return 0;
}