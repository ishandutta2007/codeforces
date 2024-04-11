//CF 1037C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
string a,b;
int main()
{
	int n,i,s=0;
	cin>>n>>a>>b;
	for(i=1;i<n;i=i+1)
		if(a[i-1]!=b[i-1]&&a[i]!=b[i]&&a[i-1]!=a[i])
			s++,a[i-1]^=1,a[i]^=1;
	for(i=0;i<n;i=i+1)
		if(a[i]!=b[i])
			s++;
	cout<<s;
	return 0;
}