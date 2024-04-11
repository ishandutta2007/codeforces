//CF 779A
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

int a[100],b[100];
int sa[10],sb[10];
int ab(int x)
{
	if(x>=0)
		return x;
	return -x;
}
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>a[i];
		sa[a[i]]=sa[a[i]]+1;
	}
	for(i=1;i<=n;i=i+1){
		cin>>b[i];
		sb[b[i]]=sb[b[i]]+1;
	}
	for(i=1;i<=5;i=i+1)
		if((sa[i]+sb[i])%2!=0){
			cout<<"-1"<<endl;
			return 0;
		}
	int ans;
	ans=0;
	for(i=1;i<=5;i=i+1){
		ans=ans+ab(sa[i]-sb[i])/2;
	}
	cout<<ans/2<<endl;
	return 0;
}