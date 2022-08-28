//CF 761A
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
const int inf = 1<<22;
char c[105][105];
int s[105][105],a[105][5],f[105][10];
//0 0-9
//1 a-z
//2 **
int main()
{
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1){
		cin>>c[i];
		for(j=0;j<m;j=j+1){
			if(c[i][j]>='0'&&c[i][j]<='9')
				s[i][j]=0;
			if(c[i][j]>='a'&&c[i][j]<='z')
				s[i][j]=1;
			if(c[i][j]=='#'||c[i][j]=='*'||c[i][j]=='&')
				s[i][j]=2;
		}
	}
	for(i=1;i<=n;i=i+1)
	{
		for(k=0;k<3;k=k+1){
			a[i][k]=inf;
			for(j=0;j<m;j=j+1){
				if(s[i][j]==k)
					a[i][k]=min(a[i][k],j);
			}
			for(j=m-1;j>0;j=j-1){
				if(s[i][j]==k)
					a[i][k]=min(a[i][k],m-j);
			}
			//cout<<a[i][k]<<' ';
		}
		//cout<<endl;
	}
	for(i=1;i<8;i=i+1)
		f[0][i]=inf;
	for(i=1;i<=n;i=i+1)
	{
		f[i][0]=0;
		for(j=0;j<8;j=j+1){
			f[i][j]=f[i-1][j];
			for(k=0;k<3;k=k+1)
				if(j&(1<<k))
					f[i][j]=min(f[i][j],f[i-1][j-(1<<k)]+a[i][k]);
			//cout<<f[i][j]<<' ';
		}
		//cout<<endl;
	}
	cout<<f[n][7]<<endl;
	return 0;
}