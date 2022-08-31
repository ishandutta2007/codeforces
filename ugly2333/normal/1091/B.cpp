//CF1091B
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
int main()
{
	int n,i,x,y;
	LL a=0,b=0;
	cin>>n;
	for(i=1;i<=n+n;i=i+1)
		cin>>x>>y,a+=x,b+=y;
	cout<<a/n<<' '<<b/n;
	return 0;
}