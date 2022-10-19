#include<bits/stdc++.h>
using namespace std;
const int N=105,M=10005;
bitset<M>a[N][N];
int main()
{
	a[1][1][0]=1;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			if(i+j!=2)
				a[i][j]=(a[i-1][j]<<j)|(a[i][j-1]<<i);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		puts(a[x][y][k]?"YES":"NO");
	}
	return 0;
}