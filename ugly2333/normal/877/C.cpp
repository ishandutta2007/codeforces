//CF 877C
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
int main()
{
	int n,i;
	cin>>n;
	cout<<n+n/2<<endl;
	for(i=2;i<=n;i=i+2)
		cout<<i<<' ';
	for(i=1;i<=n;i=i+2)
		cout<<i<<' ';
	for(i=2;i<=n;i=i+2)
		cout<<i<<' ';
	return 0;
}