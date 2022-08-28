//CF 764B
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
int a[1000005];
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	for(i=1;i<=n/2;i=i+1){
		if(i%2==1)
			swap(a[i],a[n+1-i]);
	}
	for(i=1;i<=n;i=i+1)
		cout<<a[i]<<' ';
	return 0;
}