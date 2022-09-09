#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
const int N=1000050;
char word[N];
int Trie[N][26],clock,root;
void Set(int &c, int pos, int sz)
{
	if(!c) c=++clock;
	if(pos>=sz) return;
	Set(Trie[c][word[pos]-'a'],pos+1,sz);
}
int Find(int c, int pos, int sz)
{
	if(!c) return 0;
	if(pos>=sz) return c;
	return Find(Trie[c][word[pos]-'a'],pos+1,sz);
}
vector<int> Tree[N];
void DFS(int c, int depth)
{
	if(depth>1)
	{
		int tmp=Find(root,1,depth);
		if(tmp)
		{
			Tree[tmp].push_back(c);
			Tree[c].push_back(tmp);
		}
	}
	int i;
	for(i=0;i<26;i++)
	{
		if(Trie[c][i])
		{
			word[depth]='a'+i;
			DFS(Trie[c][i],depth+1);
		}
	}
}
bool vis[N];
int sol[2];
int Sum[N];
int Best[N];
int max(int a, int b){ return a>b?a:b;}
void Solve(int cur, int prev, int depth)
{
	vis[cur]=true;
	sol[depth]++;
	Best[cur]=1;
	Sum[cur]=0;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			Solve(v,cur,depth^1);
			Best[cur]+=Sum[v];
			Sum[cur]+=Best[v];
		}
	}
	Best[cur]=max(Best[cur],Sum[cur]);
}
int ans;
int main()
{
	int t,n,i,j;
	scanf("%i",&t);
	while(t--)
	{
		scanf("%i",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",&word);
			Set(root,0,(unsigned) strlen(word));
		}
		DFS(root,0);
		for(i=2;i<=clock;i++)
		{
			if(!vis[i])
			{
				sol[0]=0;
				sol[1]=0;
				Solve(i,0,0);
				//ans+=max(sol[0],sol[1]);
				ans+=max(Best[i],Sum[i]);
			}
		}
		printf("%i\n",ans);
		for(i=0;i<=clock;i++) for(j=0;j<26;j++) Trie[i][j]=0;
		for(i=0;i<=clock;i++) Tree[i].clear();
		for(i=0;i<=clock;i++) vis[i]=false;
		root=clock=ans=0;
	}
	return 0;
}