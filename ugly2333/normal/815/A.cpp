// CF 815A
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
int a[111][111],r[111],c[111];
int main()
{
	int n,m,i,j,f,s;
	cin>>n>>m;
	f=0;
	if(n>m)
		f=1;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1){
			if(f)
				cin>>a[j][i];
			else
				cin>>a[i][j];
		}
	if(f)
		swap(n,m);
	s=0;
	for(i=1;i<=n;i=i+1){
		r[i]=1<<30;
		for(j=1;j<=m;j=j+1)
			r[i]=min(r[i],a[i][j]);
		s+=r[i];
		for(j=1;j<=m;j=j+1)
			a[i][j]-=r[i];
	}
	for(j=1;j<=m;j=j+1){
		c[j]=1<<30;
		for(i=1;i<=n;i=i+1)
			c[j]=min(c[j],a[i][j]);
		s+=c[j];
		for(i=1;i<=n;i=i+1)
			a[i][j]-=c[j];
	}
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			if(a[i][j]!=0){
				cout<<"-1\n";
				return 0;
			}
	if(f){
		swap(n,m);
		for(i=1;i<=max(n,m);i=i+1)
			swap(r[i],c[i]);
	}
	cout<<s<<endl;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=r[i];j=j+1)
			cout<<"row "<<i<<endl;
	for(j=1;j<=m;j=j+1)
		for(i=1;i<=c[j];i=i+1)
			cout<<"col "<<j<<endl;
	return 0;
}