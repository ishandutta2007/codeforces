#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,d[N][N],x,y;
void ask(int v)
{
	printf("? %d\n",v);
	fflush(stdout);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[v][i]);
}
int main()
{
	scanf("%d",&n);
	ask(1);
	for(int i=2;i<=n;i++)
		(d[1][i]&1?x:y)++;
	for(int i=2;i<=n;i++)
		if((d[1][i]&1)==(x<y))
			ask(i);
	puts("!");
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(d[i][j]==1||d[j][i]==1)
				printf("%d %d\n",i,j);
	fflush(stdout);
	return 0;
}