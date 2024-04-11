//CF 53E
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
const int N = 11;
const int M = 1111;
int n,m,k,a[N][N],dp[M][M];
int main()
{
	int i,j,l,r,x,y,ans;
	cin>>n>>m>>k;
	while(m--){
		cin>>x>>y;
		x--,y--;
		a[x][y]=1;
		a[y][x]=1;
	}
	ans=0;
	dp[0][0]=1;
	m=1<<n;
	for(i=1;i<m;i=i+1){
		r=0;
		for(l=0;l<n;l=l+1)
			if(i&(1<<l))
				r++;
		if(r<2)
			continue;
		if(r==2){
			x=0,y=0;
			for(l=0;l<n;l=l+1)
				if(i&(1<<l))
					y=x,x=l;
			if(a[x][y])
				dp[i][i]=1;
			continue;
		}
		for(j=i;j;j=(j-1)&i){
			r=0;
			for(x=0;x<n;x=x+1)
				if(j&(1<<x)){
					r++;
					for(y=0;y<n;y=y+1)
						if(((i^j)&(1<<y))&&a[x][y]){
							dp[i][j]+=dp[i^(1<<x)][j^(1<<x)];
							dp[i][j]+=dp[i^(1<<x)][j^(1<<x)^(1<<y)];
						}
				}
			dp[i][j]/=r;
			if(i==m-1&&r==k)
				ans+=dp[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}