// CF 821A
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
int a[55][55];
int main()
{
	int n,i,j,m,k,l,f;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			cin>>a[i][j];
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1){
			if(a[i][j]==1)
				continue;
			f=0;
			for(k=1;k<=n;k=k+1)
				for(l=1;l<=n;l=l+1)
					if(i!=k&&j!=l&&a[k][j]+a[i][l]==a[i][j])
						f=1;
			if(!f){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	cout<<"YES"<<endl;
	return 0;
}