// CF 814A
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
int a[1111];
int main()
{
	int n,k,i;
	cin>>n>>k;
	if(k>1){
		cout<<"YES"<<endl;
		return 0;
	}
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	cin>>k;
	for(i=1;i<=n;i=i+1){
		if(a[i]==0)
			a[i]=k;
		if(i!=1&&a[i]<a[i-1]){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}