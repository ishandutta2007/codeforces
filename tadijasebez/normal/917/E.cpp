#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=100050;
const int M=2*N;
const int H=2*M;
int acgo[M][26],aclid[M],acrid[M],acnode[M],aclink[M],actid,actsz,acroot;
void Insert(int &c, char *s, int lvl, int n, int id)
{
	if(!c) c=++actsz;
	if(lvl==n){ acnode[id]=c;return;}
	Insert(acgo[c][s[lvl]-'a'],s,lvl+1,n,id);
}
vector<int> A[M];
void DFSID(int u){ aclid[u]=++actid;for(int i=0;i<A[u].size();i++) DFSID(A[u][i]);acrid[u]=actid;}
void BuildAhoCorasick()
{
	aclink[acroot]=acroot;
	int i;
	queue<int> q;
	for(i=0;i<26;i++)
	{
		if(acgo[acroot][i])
		{
			aclink[acgo[acroot][i]]=acroot;
			q.push(acgo[acroot][i]);
		}
		else acgo[acroot][i]=acroot;
	}
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(i=0;i<26;i++)
		{
			int v=acgo[u][i];
			if(v)
			{
				aclink[v]=acgo[aclink[u]][i];
				q.push(v);
			}
			else acgo[u][i]=acgo[aclink[u]][i];
		}
	}
	for(i=acroot+1;i<=actsz;i++) A[aclink[i]].pb(i);
	DFSID(acroot);
}
int link[H],ssz[H],go[H][26],lid[H],rid[H],tid[H],root,tsz;
vector<int> ids[H],qsu[H],qsv[H];char *st[H];
struct State{ int atnode,atlen,atedge;State(int a, int b, int c){ atnode=a,atlen=b,atedge=c;}};
int AddNode(char *t, int len){ tsz++;st[tsz]=t;ssz[tsz]=len;link[tsz]=root;return tsz;}
void AddRoot(){ root=AddNode(NULL,0);link[root]=root;}
void Add(char *t, int n, int id)
{
	if(!root) AddRoot();
	int atnode=root,atedge=0,atlen=0,pleaf=0,pnode=0,i;
	for(i=0;i<=n;i++)
	{
		while(1)
		{
			int tonode=atedge==n?0:go[atnode][t[atedge]-'a'];
			if(tonode && atlen>=ssz[tonode])
			{
				atlen-=ssz[tonode];
				atedge+=ssz[tonode];
				atnode=tonode;
				continue;
			}
			if(!tonode)
			{
				if(i!=n)
				{
					int leaf=AddNode(t+i,n-i);
					go[atnode][t[i]-'a']=leaf;
					ids[leaf].pb(id);
					if(pleaf) link[pleaf]=leaf;pleaf=leaf;
				}
				else
				{
					ids[atnode].pb(id);
					if(pleaf) link[pleaf]=atnode;pleaf=0;
				}
				if(pnode) link[pnode]=atnode;pnode=0;
			}
			else if(i==n || st[tonode][atlen]!=t[i])
			{
				int node=AddNode(st[tonode],atlen);
				ssz[tonode]-=atlen;st[tonode]+=atlen;
				go[atnode][st[node][0]-'a']=node;
				go[node][st[tonode][0]-'a']=tonode;
				if(i!=n)
				{
					int leaf=AddNode(t+i,n-i);
					go[node][t[i]-'a']=leaf;
					ids[leaf].pb(id);
					if(pleaf) link[pleaf]=leaf;pleaf=leaf;
				}
				else
				{
					ids[node].pb(id);
					if(pleaf) link[pleaf]=node;pleaf=0;
				}
				if(pnode) link[pnode]=node;pnode=node;
			}
			else
			{
				if(pnode) link[pnode]=atnode;pnode=0;
				atlen++;
				break;
			}
			if(atnode==root)
			{
				atedge++;
				if(atlen) atlen--;
				else break;
			}
			else atnode=link[atnode];
		}
	}
}
State Move(State cur, char c)
{
	if(cur.atlen==-1) return cur;
	if(cur.atlen==0)
	{
		int tonode=go[cur.atnode][c-'a'];
		if(!tonode) return State(cur.atnode,-1,-1);
		if(ssz[tonode]==1) return State(tonode,0,-1);
		else return State(cur.atnode,1,c-'a');
	}
	else
	{
		int tonode=go[cur.atnode][cur.atedge];
		if(c!=st[tonode][cur.atlen]) return State(cur.atnode,-1,-1);
		cur.atlen++;
		if(cur.atlen==ssz[tonode]) return State(tonode,0,-1);
		else return cur;
	}
}
struct BIT
{
	vector<int> sum;
	BIT(){}
	void Init(int _sz){ sum.resize(_sz+5);}
	void Set(int i, int f){ for(;i<sum.size();i+=i&-i) sum[i]+=f;}
	void Set(int l, int r, int f){ Set(l,f);Set(r+1,-f);}
	int Get(int i){int ret=0;for(;i;i-=i&-i) ret+=sum[i];return ret;}
	int Get(int l, int r){ return Get(r)-Get(l-1);}
} Tree,FTree[N];
vector<pair<int,char> > E[N];
int fir[M],len[M];
char s[M];
struct Query{ int u,v,k;Query(int a=0, int b=0, int c=0){ u=a,v=b,k=c;}} Q[N];
int stu[N],stv[N],done[N],m,sol[N];
vector<int> Qa[N],Qb[N];
int sz[N],vis[N],mark[N];
void DFS(int u, int p, int &n)
{
	n++;sz[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && !vis[v]) DFS(v,u,n),sz[u]+=sz[v];
	}
}
int Find(int u, int p, int n)
{
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && !vis[v] && sz[v]>n/2) return Find(v,u,n);
	}
	return u;
}
int Find(int u){ int n=0;DFS(u,u,n);return Find(u,u,n);}
void Mark(int u, int p, int m)
{
	mark[u]=m;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && !vis[v]) Mark(v,u,m);
	}
}
void Solve(int u, int p, int ac, State st)
{
	Tree.Set(aclid[ac],1);
	int i;
	for(i=0;i<Qa[u].size();i++)
	{
		int id=Qa[u][i];
		int a=Q[id].u;
		int b=Q[id].v;
		int k=Q[id].k;
		if(mark[a] && mark[b] && mark[a]!=mark[b])
		{
			sol[id]+=Tree.Get(aclid[acnode[k+m]],acrid[acnode[k+m]]);
			stu[id]=st.atnode;
			done[id]++;
		}
	}
	for(i=0;i<Qb[u].size();i++)
	{
		int id=Qb[u][i];
		int a=Q[id].u;
		int b=Q[id].v;
		int k=Q[id].k;
		if(mark[a] && mark[b] && mark[a]!=mark[b])
		{
			sol[id]+=Tree.Get(aclid[acnode[k]],acrid[acnode[k]]);
			stv[id]=st.atnode;
			done[id]++;
		}
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		char w=E[u][i].second;
		if(v!=p && !vis[v]) Solve(v,u,acgo[ac][w-'a'],Move(st,w));
	}
	Tree.Set(aclid[ac],-1);
}
void Decompose(int u)
{
	u=Find(u);vis[u]=1;
	int i;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(!vis[v]) Mark(v,u,i+2);
	}
	mark[u]=1;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		char w=E[u][i].second;
		if(!vis[v])
		{
			Solve(v,u,acgo[acroot][w-'a'],Move(State(root,0,-1),w));
		}
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(!vis[v]) Mark(v,u,0);
	}
	mark[u]=0;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(!vis[v]) Decompose(v);
	}
}
//int qulid[N],qvlid[N],qurid[N],qvrid[N];
int nodeup[N];
vector<int> pnode[M];
void DFSST(int u, int dep)
{
	dep+=ssz[u];
	int i;
	for(i=0;i<ids[u].size();i++)
	{
		int id=ids[u][i];
		if(dep==len[id]) continue;
		if(id>m) lid[fir[id]+len[id]-dep]=++tid[id-m];
		else lid[fir[id]+len[id]-dep]=++tid[id];
		//pnode[id]=fir[id]+len[id]-dep;
		pnode[id].pb(fir[id]+len[id]-dep);
		/*if(id<=m)
		{
			printf("%i %i %i\n",u,dep,len[id]-dep);
		}*/
	}
	for(i=0;i<qsv[u].size();i++)
	{
		int id=qsv[u][i];
		int k=Q[id].k;
		if(pnode[k+m].size()) nodeup[id]=pnode[k+m].back();
	}
	/*for(i=0;i<qsu[u].size();i++)
	{
		int id=qsu[u][i];
		int k=Q[id].k;
		qulid[id]=++tid[k];
	}
	for(i=0;i<qsv[u].size();i++)
	{
		int id=qsv[u][i];
		int k=Q[id].k;
		if(qulid[id]==tid[k]) qvlid[id]=qulid[id];
		else qvlid[id]=++tid[k];
	}*/
	for(i=0;i<26;i++) if(go[u][i]) DFSST(go[u][i],dep);
	for(i=0;i<ids[u].size();i++)
	{
		int id=ids[u][i];
		if(dep==len[id]) continue;
		if(id>m) rid[fir[id]+len[id]-dep]=tid[id-m];
		else rid[fir[id]+len[id]-dep]=tid[id];
		pnode[id].pop_back();
	}
	/*for(i=0;i<qsu[u].size();i++)
	{
		int id=qsu[u][i];
		int k=Q[id].k;
		qurid[id]=tid[k];
	}
	for(i=0;i<qsv[u].size();i++)
	{
		int id=qsv[u][i];
		int k=Q[id].k;
		qvrid[id]=tid[k];
	}*/
}
void SolveST(int u, int dep)
{
	dep+=ssz[u];
	int i;
	for(i=0;i<ids[u].size();i++)
	{
		int id=ids[u][i];
		if(id<=m)
		{
			int node=fir[id+m]+dep;
			if(node<fir[id+m]+len[id+m]) FTree[id].Set(lid[node],rid[node],1);
		}
	}
	for(i=0;i<qsu[u].size();i++)
	{
		int id=qsu[u][i];
		int k=Q[id].k;
		if(nodeup[id]) sol[id]+=FTree[k].Get(lid[nodeup[id]]);
		//sol[id]+=FTree[k].Get(qvlid[id]);
	}
	for(i=0;i<26;i++) if(go[u][i]) SolveST(go[u][i],dep);
	for(i=0;i<ids[u].size();i++)
	{
		int id=ids[u][i];
		if(id<=m)
		{
			int node=fir[id+m]+dep;
			if(node<fir[id+m]+len[id+m]) FTree[id].Set(lid[node],rid[node],-1);
		}
	}
}
int main()
{
	int n,q,i,j,u,v;char w;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<n;i++) scanf("%i %i %c",&u,&v,&w),E[u].pb(mp(v,w)),E[v].pb(mp(u,w));
	for(i=1;i<=m;i++)
	{
		scanf("%s",s+fir[i]);
		len[i]=strlen(s+fir[i]);
		fir[i+1]=fir[i]+len[i];
	}
	for(i=m+1;i<=m*2;i++)
	{
		for(j=len[i-m]-1;j>=0;j--)
		{
			s[fir[i]+len[i-m]-1-j]=s[fir[i-m]+j];
		}
		len[i]=len[i-m];
		fir[i+1]=fir[i]+len[i];
	}
	for(i=1;i<=2*m;i++) Insert(acroot,s+fir[i],0,len[i],i);
	BuildAhoCorasick();Tree.Init(actid);
	for(i=1;i<=2*m;i++) Add(s+fir[i],len[i],i);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i %i",&Q[i].u,&Q[i].v,&Q[i].k);
		Qa[Q[i].u].pb(i);
		Qb[Q[i].v].pb(i);
	}
	Decompose(1);
	for(i=1;i<=q;i++)
	{
		if(done[i]==2 && stu[i]!=root && stv[i]!=root)
		{
			//printf("Query %i: %i %i\n",i,stu[i],stv[i]);
			qsv[stu[i]].pb(i);
			qsu[stv[i]].pb(i);
		}
	}
	ids[root].clear();
	DFSST(root,0);
	for(i=1;i<=m;i++) FTree[i].Init(tid[i]);
	SolveST(root,0);
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	/*printf("Suffix Tree:\n");
	for(i=1;i<=tsz;i++)
	{
		for(j=0;j<26;j++)
		{
			v=go[i][j];
			if(v)
			{
				printf("%i -> %i ",i,v);
				for(u=0;u<ssz[v];u++) printf("%c",st[v][u]);
				printf("\n");
			}
		}
	}*/
	return 0;
}