//CF 899B
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
int a[60]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int t[66];
int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i=i+1)
		cin>>t[i];
	for(j=0;j<60;j=j+1){
		for(i=0;i<n;i=i+1)
			if(t[i]!=a[i+j])
				break;
		if(i==n){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}