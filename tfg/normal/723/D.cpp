#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;

char m_map[100][100];
int n,m,k;

std::vector<iii> isl;
bool visited[100][100];

int dfs(int i, int j)
{
	if(i<0 || j<0 || i>n-1 || j>m-1) return 3000;
	if(visited[i][j] || m_map[i][j]=='*') return 0;
	
	visited[i][j]=true;
	return 1+dfs(i+1,j)+dfs(i-1,j)+dfs(i,j+1)+dfs(i,j-1);
}

void rec(int i, int j)
{
	if(!visited[i][j] && m_map[i][j]=='.')
	{
		int ans=dfs(i,j);
		//printf("water on %i %i is %i\n",i,j,ans);
		if(ans<3000)
			isl.push_back(iii(ans,ii(i,j)));
	}
}

int destroy(int i, int j)
{
	if(m_map[i][j]=='*') return 0;
	m_map[i][j]='*';
	return 1+destroy(i+1,j)+destroy(i-1,j)+destroy(i,j+1)+destroy(i,j-1);
}

int main()
{
	scanf("%i %i %i", &n,&m,&k);
	for(int i=0;i<n;i++)
	{
		scanf(" %s", m_map[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			rec(i,j);
		}
	}
	std::sort(isl.begin(), isl.end());
	int ans=0;
	for(int i=0;isl.size()-i>k;i++)
	{
		ans+=destroy(isl[i].second.first, isl[i].second.second);
	}
	printf("%i\n",ans);
	for(int i=0;i<n;i++)
		printf("%s\n",m_map[i]);
}