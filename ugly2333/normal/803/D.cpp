//CF 803D
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
int a[555555],k,n;
bool ok(int m)
{
	int i,j,t;
	i=0;
	for(t=1;t<=k&&i<=n;t=t+1){
		j=m;
		while(i<=n&&j>=a[i]){
			j-=a[i];
			i=i+1;
		}
	}
	if(i<=n)
		return 0;
	return 1;
}
int main()
{
	char c;
	int i,l,r,m;
	cin>>k;
	n=1;
	m=0;
	while(scanf("%c",&c)){
		if(65<=c&&c<=90||97<=c&&c<=122||c==' '||c=='-')
			a[n]++;
		if(c==' '||c=='-')
			n++;
		if(c=='\n')
			m++;
		if(m>=2)
			break;
	}
	//for(i=1;i<=n;i=i+1)
	//	cout<<a[i]<<endl;
	l=1;
	r=1111111;
	while(l<r){
		m=(l+r)/2;
		if(ok(m))
			r=m;
		else
			l=m+1;
	}
	cout<<l<<endl;
	return 0;
}