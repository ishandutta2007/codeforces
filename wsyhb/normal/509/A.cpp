#include<bits/stdc++.h>
using namespace std;
int a[12][12];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++) a[i][1]=a[1][i]=1;
	for(i=2;i<=n;i++)
		for(j=2;j<=n;j++)
			a[i][j]=a[i][j-1]+a[i-1][j];
	cout<<a[n][n];
	return 0;
}