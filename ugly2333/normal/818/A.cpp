// CF 818A
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
	LL n,k,s;
	cin>>n>>k;
	s=(n/2)/(k+1);
	cout<<s<<' '<<(LL)s*k<<' ';
	s*=(k+1);
	cout<<n-s<<endl;
	return 0;
}