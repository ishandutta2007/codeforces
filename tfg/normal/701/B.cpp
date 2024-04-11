#include <cstdio>
#include <iostream>
#include <utility>

typedef std::pair<int, int> ii;
typedef std::pair<double, double> dd;

inline int readint()
{
	int temp;
	scanf("%i",&temp);
	return temp;
}

bool col[100100], row[100100];
int num_col=0, num_row=0;
long long int empty;

int main()
{
	int n=readint();
	int m=readint();
	empty=((long long int)n)*n;
	for(int i=0;i<m;i++)
	{
		int x=readint();
		int y=readint();

		if(!row[x])
		{
			empty-=n-num_col;
			num_row++;
		}
		if(!col[y])
		{
			empty-=n-num_row;
			num_col++;
		}
		row[x]=col[y]=true;
		printf("%lli\n", empty);
	}
	
}