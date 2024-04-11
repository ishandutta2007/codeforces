#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
#define mp make_pair
const int N=100050;
int go[N][26],sz[N],id[N],root,tsz;
void Add(int &c ,int lvl, int n, char *s)
{
	if(!c) c=++tsz;
	//printf("%i\n",c);
	sz[c]++;
	if(lvl==n){ id[c]=1;return;}
	Add(go[c][s[lvl]-'a'],lvl+1,n,s);
}
int max(int a, int b){ return a>b?a:b;}
int lid[N],rid[N],tid;
pair<int,int> max(pair<int,int> a, pair<int,int> b){ return a>b?a:b;}
struct SegmentTree
{
	pair<int,int> rmq[1<<20];
	SegmentTree(){ for(int i=0;i<(1<<20);i++) rmq[i]=mp(0,0);}
	void Set(int x, pair<int,int> val)
	{
		x+=1<<19;rmq[x]=val;
		for(x>>=1;x;x>>=1) rmq[x]=max(rmq[x<<1],rmq[x<<1|1]);
	}
	pair<int,int> Get(int l, int r)
	{
		pair<int,int> ret=mp(0,0);
		for(l+=1<<19,r+=1<<19;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ret=max(ret,rmq[l++]);
			if(r%2==0) ret=max(ret,rmq[r--]);
		}
		return ret;
	}
} Tree;
void DFSID(int c, int dep, int p)
{
	lid[c]=++tid;
	for(int i=0;i<26;i++) if(go[c][i]) DFSID(go[c][i],dep+1,c);
	if(id[c]) Tree.Set(lid[c],mp(dep,c));
	rid[c]=tid;
}
int sol,done[N],st[N],ssz;
multiset<int> Set[N];
multiset<int>::iterator it;
void DFS(int c, int dep)
{
	int i;
	for(i=0;i<26;i++) if(go[c][i])
	{
		DFS(go[c][i],dep+1);
		if(Set[st[go[c][i]]].size()>Set[st[c]].size()) st[c]=st[go[c][i]];
	}
	for(i=0;i<26;i++) if(go[c][i])
	{
		if(st[go[c][i]]!=st[c])
		{
			int v=st[go[c][i]];
			int u=st[c];
			for(it=Set[v].begin();it!=Set[v].end();it++) Set[u].insert(*it);
		}
	}
	if(st[c]==0) st[c]=++ssz,Set[st[c]].insert(dep);
	else
	{
		if(!id[c]) Set[st[c]].erase(--Set[st[c]].end());
		Set[st[c]].insert(dep);
	}
}
/*void DFS(int c, int dep)
{
	if(id[c] && !done[c])
	{
		sol+=dep;
	}
	else
	{
		pair<int,int> tmp=Tree.Get(lid[c],rid[c]);
		if(!done[tmp.second])
		{
			//printf("%i %i\n",c,tmp.second);
			sol+=dep;
			done[tmp.second]=1;
			tmp.first=0;
			Tree.Set(lid[tmp.second],tmp);
		}
	}
	for(int i=0;i<26;i++) if(go[c][i]) DFS(go[c][i],dep+1);
}*/
char s[N];
int main()
{
	int n,i,m;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		m=strlen(s+1);
		Add(root,0,m,s+1);
	}
	if(n==1) return printf("1\n"),0;
	//DFSID(root,1,0);
	int ret=0;
	for(i=0;i<26;i++) if(go[root][i])
	{
		DFS(go[root][i],1);
		int u=st[go[root][i]];
		for(it=Set[u].begin();it!=Set[u].end();it++) ret+=*it;//,printf("%i ",*it);
	}
	printf("%i\n",ret);
	return 0;
}