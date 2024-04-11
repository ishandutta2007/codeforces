#include <cstdio>
#include <queue>

#define fre(a,b) for(int b=adj[a];b!=-1;b=ant[b])

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;

//como manda rascunho?

int dist[1010][1010][4];
char str[4][1010][1010];
int n,m;

bool can_up(int k, int i, int j)
{
	if(i<0 || i>=n || j<0 || j>=m) return false;
	if(str[k][i][j]=='+' || str[k][i][j]=='^' || str[k][i][j]=='|' || str[k][i][j]=='L' || str[k][i][j]=='R' || str[k][i][j]=='D') return true;
	return false;
}

bool can_down(int k, int i, int j)
{
	if(i<0 || i>=n || j<0 || j>=m) return false;
	if(str[k][i][j]=='+' || str[k][i][j]=='v' || str[k][i][j]=='|' || str[k][i][j]=='L' || str[k][i][j]=='R' || str[k][i][j]=='U') return true;
	return false;
}

bool can_left(int k, int i, int j)
{
	if(i<0 || i>=n || j<0 || j>=m) return false;
	if(str[k][i][j]=='+' || str[k][i][j]=='<' || str[k][i][j]=='-' || str[k][i][j]=='U' || str[k][i][j]=='R' || str[k][i][j]=='D') return true;
	return false;
}

bool can_right(int k, int i, int j)
{
	if(i<0 || i>=n || j<0 || j>=m) return false;
	if(str[k][i][j]=='+' || str[k][i][j]=='>' || str[k][i][j]=='-' || str[k][i][j]=='L' || str[k][i][j]=='U' || str[k][i][j]=='D') return true;
	return false;
}

char rotate(char x)
{
	if(x=='|') return '-';
	else if(x=='-') return '|';
	else if(x=='L') return 'U';
	else if(x=='U') return 'R';
	else if(x=='R') return 'D';
	else if(x=='D') return 'L';
	else if(x=='<') return '^';
	else if(x=='^') return '>';
	else if(x=='>') return 'v';
	else if(x=='v') return '<';
	else if(x=='+') return '+';
	else return '*';
}


int t_row, t_col, m_row, m_col;

int bfs()
{
	if(t_row==m_row && t_col==m_col) return 0;
	std::queue<iii> que;
	que.push(iii(0,ii(t_row, t_col)));
	while(!que.empty())
	{
		for(int i=0;i<4;i++)
		{
			if(dist[m_row][m_col][i]!=0)
				return dist[m_row][m_col][i];
		}
		iii now = que.front();
		int n_row=now.second.first;
		int n_col=now.second.second;
		int n_k=now.first;
		que.pop();
		if(n_row == m_row && n_col == m_col && n_k == 0 && dist[n_row][n_col][n_k]!=0)
			continue;
		//printf("passando por %i, %i k=%i, dist=%i\n",n_row,n_col,n_k,dist[n_row][n_col][n_k]);
		if(can_right(n_k,n_row,n_col) && can_left(n_k,n_row,n_col+1) && dist[n_row][n_col+1][n_k]==0)
		{
			dist[n_row][n_col+1][n_k]=dist[n_row][n_col][n_k]+1;
			que.push(iii(n_k,ii(n_row,n_col+1)));
		}
		if(can_left(n_k,n_row,n_col) && can_right(n_k,n_row,n_col-1) && dist[n_row][n_col-1][n_k]==0)
		{
			dist[n_row][n_col-1][n_k]=dist[n_row][n_col][n_k]+1;
			que.push(iii(n_k,ii(n_row,n_col-1)));
		}
		if(can_up(n_k,n_row,n_col) && can_down(n_k,n_row-1,n_col) && dist[n_row-1][n_col][n_k]==0)
		{
			dist[n_row-1][n_col][n_k]=dist[n_row][n_col][n_k]+1;
			que.push(iii(n_k,ii(n_row-1,n_col)));
		}
		if(can_down(n_k,n_row,n_col) && can_up(n_k,n_row+1,n_col) && dist[n_row+1][n_col][n_k]==0)
		{
			dist[n_row+1][n_col][n_k]=dist[n_row][n_col][n_k]+1;
			que.push(iii(n_k,ii(n_row+1,n_col)));
		}
		if(dist[n_row][n_col][(n_k+1)%4]==0)
		{
			dist[n_row][n_col][(n_k+1)%4]=dist[n_row][n_col][n_k]+1;
			que.push(iii((n_k+1)%4,ii(n_row,n_col)));
		}




		if(n_row == m_row && n_col == m_col && n_k == 0)
			dist[n_row][n_col][n_k]=1;
	}
	return -1;
}

int main()
{
	
	scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf(" %s", str[0][i]);
	}
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				str[k+1][i][j]=rotate(str[k][i][j]);
			}
		}
	}
	/*for(int k=0;k<4;k++)
	{
		printf("--------------------\n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				printf("%c",str[k][i][j]);
			}
			printf("\n");
		}
		printf("--------------------\n");
	}*/
	scanf("%i %i %i %i",&t_row,&t_col,&m_row,&m_col);
	t_row--;t_col--;m_row--;m_col--;
	printf("%i\n",bfs());
}