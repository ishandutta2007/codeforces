#include<cstdio>
#include<utility>
#include<cstring>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int prenum[55][55],lowest[55][55];
P parent[55][55];

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

bool field[55][55];

int timer=1;
bool visited[55][55];

void dfs(int vi,int vj,int pi,int pj)
{
	prenum[vi][vj]=timer,lowest[vi][vj]=timer;
	timer++;
	visited[vi][vj]=true;
	for(int i=0;i<4;i++)
	{
		int ni=vi+dx[i],nj=vj+dy[i];
		if(field[ni][nj]==false) continue;
		if(visited[ni][nj]==false)
		{
			parent[ni][nj]=P(vi,vj);
			dfs(ni,nj,vi,vj);
			lowest[vi][vj]=min(lowest[vi][vj],lowest[ni][nj]);
		}
		else if(ni!=pi||nj!=pj)
		{
			lowest[vi][vj]=min(lowest[vi][vj],prenum[ni][nj]);
		}
	}
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	memset(field,false,sizeof(field));
	int cnt=0;
	int ri,rj;
	for(int i=0;i<N;i++)
	{
		char ch[55];
		scanf("%s",ch);
		for(int j=0;j<M;j++)
		{
			if(ch[j]=='#')
			{
				field[i+1][j+1]=true;
				cnt++;
				ri=i+1,rj=j+1;
			}
		}
	}
	if(cnt<=2)
	{
		printf("-1\n");
		return 0;
	}
	memset(visited,false,sizeof(visited));
	dfs(ri,rj,-1,-1);
	bool exi=false;
	//root
	int c=0;
	for(int i=0;i<4;i++)
	{
		int ni=ri+dx[i],nj=rj+dy[i];
		if(parent[ni][nj]==P(ri,rj)) c++;
	}
	if(c>=2) exi=true;
	//others
	for(int i=0;i<=N+1;i++)
	{
		for(int j=0;j<=M+1;j++)
		{
			if(field[i][j]==false) continue;
			if(i==ri&&j==rj) continue;
			P p=parent[i][j];
			int pi=p.first,pj=p.second;
			if(pi==ri&&pj==rj) continue;
			if(prenum[pi][pj]<=lowest[i][j])
			{
				//printf("%d %d\n",pi,pj);
				exi=true;
			}
		}
	}
	if(exi==false) printf("2\n");
	else printf("1\n");
	return 0;
}