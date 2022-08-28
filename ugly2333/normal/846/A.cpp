// CF 846A
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
int a[111];
int main()
{
	int n,i,s;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	for(i=1;i<=n;i=i+1)
		a[i]+=a[i-1];
	s=0;
	for(i=0;i<=n;i=i+1)
		s=max(s,i-a[i]+a[n]-a[i]);
	cout<<s<<endl;
	return 0;
}