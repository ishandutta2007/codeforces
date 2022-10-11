#include <cstdio>
#include <utility>
#include <set>

typedef std::pair<int,int> ii;
typedef std::pair<ii,ii> iv;

int n,m,q;

int mat[5050][5050];
ii query[5050][2];

std::set<int>::iterator it;

int main()
{
	scanf("%i %i %i",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		int t1,t2,t3;
		scanf("%i %i %i",&t1,&t2,&t3);
		query[t2-1][t1-1]=ii(-i,t3);
	}
	std::set<int> cols, rows;
	for(int i=0;i<n;i++)
		rows.insert(i);
	for(int i=0;i<m;i++)
		cols.insert(i);
	std::set<iv> qs;
	for(int i=0;i<5050;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(query[i][j].first!=0)
			{
				qs.insert(iv(query[i][j],ii(i,j)));
			}
		}
	}
	while(!qs.empty())
	{
		iv now=*(qs.begin());
		qs.erase(now);
		if(now.second.second==0)
		{
			rows.erase(now.second.first);
			it=cols.begin();
			while(it!=cols.end())
			{
				mat[now.second.first][*it]=now.first.second;
				it++;
			}
		}
		else
		{
			cols.erase(now.second.first);
			it=rows.begin();
			while(it!=rows.end())
			{
				mat[*it][now.second.first]=now.first.second;
				it++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%i",mat[i][0]);
		for(int j=1;j<m;j++)
			printf(" %i",mat[i][j]);
		printf("\n");
	}
}