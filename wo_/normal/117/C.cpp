#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

vector<int> G[5050],rG[5050];

int vs[5050];

int cmp[5050];//[v_id]=scc_id
int cnt[5050];

bool used[5050];

int c=0;
void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i];
		if(used[u]) continue;
		dfs(u);
	}
	vs[c]=v;
	c++;
}

void rdfs(int v,int k)
{
	cmp[v]=k;
	used[v]=true;
	cnt[k]++;
	for(int i=0;i<rG[v].size();i++)
	{
		int u=rG[v][i];
		if(used[u]) continue;
		rdfs(u,k);
	}
}

int nxt[5055];
int search_loop(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i];
		if(cmp[v]!=cmp[u]) continue;
		nxt[v]=u;
		if(used[u]) return u;
		return search_loop(u);
	}
}

vector<int> loop;

char ch[5050];

bool con[5050][5050];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",ch);
		for(int j=0;j<N;j++)
		{
			if(i==j) continue;
			if(ch[j]=='0')
			{
				rG[i].push_back(j);
				con[i][j]=false;
			}
			else
			{
				G[i].push_back(j);
				con[i][j]=true;
			}
		}
	}
	memset(used,false,sizeof(used));
	for(int i=0;i<N;i++)
	{
		if(used[i]==false) dfs(i);
	}
	int k=0;
	memset(used,false,sizeof(used));
	for(int i=N-1;i>=0;i--)
	{
		if(used[vs[i]]==false) rdfs(vs[i],k++);
	}
	memset(used,false,sizeof(used));
	for(int i=0;i<N;i++)
	{
		int rank=cmp[i];
		if(cnt[rank]<3) continue;
		int u=search_loop(i);
		int st=u;
		do{
			loop.push_back(u);
			u=nxt[u];
		}while(u!=st);
		for(int j=2;j<loop.size();j++)
		{
			if(con[u][loop[j]]==false)
			{
				int v1=u,v2=loop[j-1],v3=loop[j];
				printf("%d %d %d\n",v1+1,v2+1,v3+1);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}