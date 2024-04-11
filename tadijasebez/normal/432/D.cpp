#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=100050;
const int M=3*N;
int len[M],link[M],root,tsz,sz[M],go[M][26];
char *s[M];
struct State{ int atnode,atlen,atedge;State(int a, int b, int c){ atnode=a,atlen=b,atedge=c;}};
int AddNode(char *t, int _len){ tsz++;s[tsz]=t;len[tsz]=_len;link[tsz]=root;return tsz;}
void AddRoot(){ root=AddNode(NULL,0);link[root]=root;}
void DFS(int u)
{
	int i;
	for(i=0;i<26;i++)
	{
		if(go[u][i]) DFS(go[u][i]),sz[u]+=sz[go[u][i]];
	}
}
void BuildSuffixTree(char *t, int n)
{
	AddRoot();
	int atnode=root,atlen=0,atedge=0,pleaf=0,pnode=0,i;
	for(i=0;i<=n;i++)
	{
		while(1)
		{
			int tonode=atedge==n?0:go[atnode][t[atedge]-'a'];
			if(tonode && atlen>=len[tonode])
			{
				atlen-=len[tonode];
				atedge+=len[tonode];
				atnode=tonode;
				continue;
			}
			if(!tonode)
			{
				if(i!=n)
				{
					int leaf=AddNode(t+i,n-i);
					sz[leaf]++;
					go[atnode][t[i]-'a']=leaf;
					if(pleaf) link[pleaf]=leaf;pleaf=leaf;
				}
				else
				{
					sz[atnode]++;
					if(pleaf) link[pleaf]=atnode;pleaf=0;
				}
				if(pnode) link[pnode]=atnode;pnode=0;
			}
			else if(i==n || t[i]!=s[tonode][atlen])
			{
				int node=AddNode(s[tonode],atlen);
				len[tonode]-=atlen;s[tonode]+=atlen;
				go[node][s[tonode][0]-'a']=tonode;
				go[atnode][s[node][0]-'a']=node;
				if(i!=n)
				{
					int leaf=AddNode(t+i,n-i);
					sz[leaf]++;
					go[node][s[leaf][0]-'a']=leaf;
					if(pleaf) link[pleaf]=leaf;pleaf=leaf;
				}
				else
				{
					sz[node]++;
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
	DFS(root);
}
State Next(State cur, char c)
{
	if(cur.atlen==-1) return cur;
	if(cur.atlen==0)
	{
		int tonode=go[cur.atnode][c-'a'];
		if(!tonode) return State(cur.atnode,-1,-1);
		if(len[tonode]==1) return State(tonode,0,-1);
		else return State(cur.atnode,1,c-'a');
	}
	else
	{
		int tonode=go[cur.atnode][cur.atedge];
		if(c!=s[tonode][cur.atlen]) return State(cur.atnode,-1,-1);
		cur.atlen++;
		if(cur.atlen==len[tonode]) return State(tonode,0,-1);
		else return cur;
	}
}
char t[N];
#define ll long long
const ll mod=123546785144697;
ll lh[N],rh[N],po[N];
vector<pair<int,int> > sol;
int main()
{
	int n,i;
	scanf("%s",t+1);
	n=strlen(t+1);
	for(i=1;i<=n;i++) t[i]-='A',t[i]+='a';
	BuildSuffixTree(t+1,n);
	State cur=State(root,0,-1);
	po[0]=1;for(i=1;i<N;i++) po[i]=po[i-1]*26%mod;
	for(i=1;i<=n;i++)
	{
		lh[i]=lh[i-1]+po[i-1]*(t[i]-'a'+1)%mod;
		if(lh[i]>=mod) lh[i]-=mod;
	}
	for(i=n;i>=1;i--)
	{
		rh[i]=rh[i+1]*26%mod+(t[i]-'a'+1);
		if(rh[i]>=mod) rh[i]-=mod;
	}
	for(i=1;i<=n;i++)
	{
		cur=Next(cur,t[i]);
		if(lh[i]==rh[n-i+1])
		{
			if(!cur.atlen) sol.pb(mp(i,sz[cur.atnode]));
			else sol.pb(mp(i,sz[go[cur.atnode][cur.atedge]]));
		}
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}