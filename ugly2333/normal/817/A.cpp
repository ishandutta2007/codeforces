// CF 817A
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
	int a,b,c,d,x,y;
	cin>>a>>b>>c>>d>>x>>y;
	a-=c;
	c=a/x;
	b-=d;
	d=b/y;
	if(c*x==a&&d*y==b&&(c+2222222)%2==(d+2222222)%2)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}