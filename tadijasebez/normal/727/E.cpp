#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=100050;
const int M=20*N;
struct AhoCorasick
{
    map<char,int> go[M];
    int tsz,root,link[M],id[M];
    AhoCorasick(){ root=tsz=1;}
    void Add(char *s, int n, int j)
    {
    	int at=root;
		for(int i=0;i<n;i++)
		{
			if(!go[at].count(s[i])) go[at][s[i]]=++tsz;
			at=go[at][s[i]];
		}
		id[at]=j;
    }
    void Build()
    {
    	queue<int> q;
		for(int i=0;i<26;i++)
		{
			if(go[root].count('a'+i))
			{
				link[go[root]['a'+i]]=root;
				q.push(go[root]['a'+i]);
			}
			else go[root]['a'+i]=root;
		}
		while(q.size())
		{
			int x=q.front();
			q.pop();
			for(auto p:go[x])
			{
				int tmp=link[x];
				while(!go[tmp].count(p.first)) tmp=link[tmp];
				link[p.second]=go[tmp][p.first];
				q.push(p.second);
			}
		}
    }
    int Move(int at, char c)
    {
    	while(!go[at].count(c)) at=link[at];
    	return go[at][c];
    }
} AC;
char s[M],t[N];
vector<int> hs[N];
int id[M];
int main()
{
	int n,k,m,i,j;
	scanf("%i %i",&n,&k);
	scanf("%s",s+1);
	for(i=1;i<k;i++) s[n*k+i]=s[i];
	int sz=n*k+k-1;
	scanf("%i",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%s",t+1);
		AC.Add(t+1,k,i);
	}
	AC.Build();
	int at=AC.root;
	for(i=1;i<k;i++) at=AC.Move(at,s[i]);
	for(i=k;i<=sz;i++)
	{
		int p=(i-1)%k+1;
		at=AC.Move(at,s[i]);
		if(AC.id[at])
		{
			hs[p].pb(AC.id[at]);
		}
	}
	for(i=1;i<=k;i++) if(hs[i].size()==n)
	{
		vector<int> tmp=hs[i];
		sort(tmp.begin(),tmp.end());
		int cnt=unique(tmp.begin(),tmp.end())-tmp.begin();
		if(cnt==n)
		{
			printf("YES\n");
			for(j=0;j<n;j++) printf("%i ",hs[i][j]);
			printf("\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}