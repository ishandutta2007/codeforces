//CF1148A
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
	LL a,b,c;
	cin>>a>>b>>c;
	if(a==b)
		cout<<a+b+c*2;
	else
		cout<<min(a,b)*2+1+c*2;
	return 0;
}