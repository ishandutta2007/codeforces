//CF 837B
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
int a[111][111],f[11];
int main()
{
	char ch;
	int n,m,i,j,k,x,y;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1){
			cin>>ch;
			if(ch=='R')
				a[i][j]=1;
			if(ch=='G')
				a[i][j]=2;
			if(ch=='B')
				a[i][j]=3;
		}
	memset(f,0,sizeof(f));
	if(n%3==0){
		x=n/3;
		for(k=0;k<=2;k=k+1){
			y=a[k*x+1][1];
			f[y]++;
			for(i=k*x+1;i<=k*x+x;i=i+1){
				for(j=1;j<=m;j=j+1)
					if(a[i][j]!=y)
						f[0]++;
			}
		}
		if(!f[0]&&f[1]&&f[2]&&f[3]){
			cout<<"YES\n";
			return 0;
		}
	}
	for(i=1;i<=max(m,n);i=i+1)
		for(j=i+1;j<=max(m,n);j=j+1)
			swap(a[i][j],a[j][i]);
	swap(n,m);
	memset(f,0,sizeof(f));
	if(n%3==0){
		x=n/3;
		for(k=0;k<=2;k=k+1){
			y=a[k*x+1][1];
			f[y]++;
			for(i=k*x+1;i<=k*x+x;i=i+1){
				for(j=1;j<=m;j=j+1)
					if(a[i][j]!=y)
						f[0]++;
			}
		}
		if(!f[0]&&f[1]&&f[2]&&f[3]){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}