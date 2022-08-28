//CF 850A
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
int a[1111][11];
int f[1111][1111][5];
int ans[1111];
int cal(int x,int y,int z){
	int s,i;
	s=0;
	for(i=1;i<=5;i=i+1)
		s+=f[x][y][i]*f[x][z][i];
	return s;
}
int main()
{
	int n,i,j,k,s;
	cin>>n;
	if(n>=100){
		cout<<0<<endl;
		return 0;
	}
	for(i=1;i<=n;i=i+1)
		for(k=1;k<=5;k=k+1)
			cin>>a[i][k];
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			for(k=1;k<=5;k=k+1)
				f[i][j][k]=a[j][k]-a[i][k];
	s=0;
	for(i=1;i<=n;i=i+1){
		ans[i]=1;
		for(j=1;j<=n&&ans[i];j=j+1){
			if(i==j)
				continue;
			for(k=1;k<=n&&ans[i];k=k+1)
				if(i!=k&&j!=k&&cal(i,j,k)>0)
					ans[i]=0;
		}
		if(ans[i])
			s++;
	}
	cout<<s<<endl;
	for(i=1;i<=n;i=i+1)
		if(ans[i])
			cout<<i<<endl;
	return 0;
}