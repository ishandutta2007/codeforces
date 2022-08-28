//CF 832A
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
	LL n,k;
	cin>>n>>k;
	n/=k;
	n%=2;
	if(n)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}