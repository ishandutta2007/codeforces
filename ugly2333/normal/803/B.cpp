//CF 803B
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
int a[222222];
int main()
{
	int n,i,j,p;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		scanf("%d",&a[i]);
	j=1;
	while(a[j]){
		j++;
	}
	for(i=1;i<=j;i=i+1)
		cout<<j-i<<' ';
	p=j;
	for(j=j+1;j<=n;j=j+1){
		if(a[j]==0){
			for(i=p+1;i<=j;i=i+1)
				cout<<min(i-p,j-i)<<' ';
			p=j;
		}
	}
	for(i=p+1;i<=n;i=i+1)
		cout<<i-p<<' ';
	return 0;
}