#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=100050;
const int S=317;
const int inf=1e9+7;
int a[N],b[N],Min[N][S];
vector<int> pos[N];
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int s,e,n,m,i,j;
	scanf("%i %i %i %i",&n,&m,&s,&e);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=m;i++) scanf("%i",&b[i]),pos[b[i]].pb(i);
	for(i=1;i<S;i++) Min[0][i]=inf;
	int sol=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<S;j++)
		{
			Min[i][j]=Min[i-1][j];
			int id=upper_bound(pos[a[i]].begin(),pos[a[i]].end(),Min[i-1][j-1])-pos[a[i]].begin();
			if(id!=pos[a[i]].size())
			{
				Min[i][j]=min(Min[i][j],pos[a[i]][id]);
			}
			if(e*j+i+Min[i][j]<=s) sol=max(sol,j);
			//if(j<8) printf("%i ",Min[i][j]);
		}
		//printf("\n");
	}
	printf("%i\n",sol);
	return 0;
}