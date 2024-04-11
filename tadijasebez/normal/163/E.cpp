#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=1000050;
struct AhoCorasick
{
	int link[N],go[N][26],my[N],lid[N],rid[N],root,tid,tsz,st;
	vector<int> E[N];
	AhoCorasick(){}
	void Add(int &c, int lvl, int n, char *s, int id)
	{
		if(!c) c=++tsz;
		if(lvl==n){ my[id]=c;return;}
		Add(go[c][s[0]-'a'],lvl+1,n,s+1,id);
	}
	void Add(int n, char *s, int id){ Add(root,0,n,s,id);}
	void DFS(int u){ lid[u]=++tid;for(int v:E[u]) DFS(v);rid[u]=tid;}
	void Build()
	{
		queue<int> q;link[root]=root;
		for(int i=0;i<26;i++){ if(go[root][i]) link[go[root][i]]=root,q.push(go[root][i]);else go[root][i]=root;}
		while(q.size())
		{
			int u=q.front();q.pop();
			for(int i=0;i<26;i++)
			{
				if(go[u][i]) link[go[u][i]]=go[link[u]][i],q.push(go[u][i]);
				else go[u][i]=go[link[u]][i];
			}
		}
		for(int i=2;i<=tsz;i++) E[link[i]].pb(i);
		DFS(root);
	}
	struct BIT
	{
		vector<int> used;
		int sum[N];
		BIT(){}
		void init(){ for(int i:used) sum[i]=0;used.clear();}
		void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f,used.pb(i);}
		void Set(int l, int r, int f){ Set(l,f);Set(r+1,-f);}
		int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=sum[i];return ret;}
	} BIT;
	void Ins(int id, int f){ BIT.Set(lid[my[id]],rid[my[id]],f);}
	void InitState(){ st=root;}
	int Move(char c){ st=go[st][c-'a'];return BIT.Get(lid[st]);}
} AC;
bool in[N];
char s[N];
int main()
{
	int n,i,q,x;char t;
	scanf("%i %i",&q,&n);
	for(i=1;i<=n;i++) scanf("%s",s),AC.Add(strlen(s),s,i);
	AC.Build();
	for(i=1;i<=n;i++) AC.Ins(i,1),in[i]=1;
	while(q--)
	{
		scanf("\n%c",&t);
		if(t=='+')
		{
			scanf("%i",&x);
			if(in[x]==0) AC.Ins(x,1);
			in[x]=1;
		}
		else if(t=='-')
		{
			scanf("%i",&x);
			if(in[x]==1) AC.Ins(x,-1);
			in[x]=0;
		}
		else
		{
			scanf("%s",s);
			int sz=strlen(s);
			ll ans=0;
			AC.InitState();
			for(i=0;i<sz;i++) ans+=AC.Move(s[i]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}