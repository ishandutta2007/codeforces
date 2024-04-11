// CF 822A
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
	LL x,a,b,i;
	cin>>a>>b;
	a=min(a,b);
	x=1;
	for(i=1;i<=a;i=i+1)
		x*=(LL)i;
	cout<<x<<endl;
	return 0;
}