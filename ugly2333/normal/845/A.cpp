//CF 845A
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
	int n,i;
	cin>>n;
	for(i=1;i<=2*n;i=i+1)
		cin>>a[i];
	sort(a+1,a+n+n+1);
	if(a[n]!=a[n+1])
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}