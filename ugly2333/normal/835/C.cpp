//CF 835C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int s[111][111][11];
int main()
{
	int n,q,c,i,j,k,x,y,z,xx,yy,ans,p;
	scanf("%d%d%d",&n,&q,&c);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		s[x][y][z]++;
	}
	for(i=1;i<=100;i=i+1)
		for(j=1;j<=100;j=j+1)
			for(k=0;k<=c;k=k+1)
				s[i][j][k]+=s[i][j-1][k];
	for(i=1;i<=100;i=i+1)
		for(j=1;j<=100;j=j+1)
			for(k=0;k<=c;k=k+1)
				s[i][j][k]+=s[i-1][j][k];
	while(q--){
		scanf("%d%d%d%d%d",&z,&x,&y,&xx,&yy);
		ans=0;
		x--;
		y--;
		for(k=0;k<=c;k=k+1){
			p=s[xx][yy][k]+s[x][y][k];
			p-=(s[xx][y][k]+s[x][yy][k]);
			p*=(z+k)%(c+1);
			ans+=p;
		}
		printf("%d\n",ans);
	}
	return 0;
}