//CF 894B
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
const int mod = 1e9+7;
int fpow(int x,LL p){
	if(!p)
		return 1;
	LL res;
	res=fpow(x,p>>1);
	res=res*res%mod;
	if(p&1)
		res=res*x%mod;
	return res;
}
int main()
{
	LL n,m;
	int k;
	cin>>n>>m>>k;
	if((n+m)&1&&k==-1)
		cout<<0<<endl;
	else
		cout<<fpow(fpow(2,n-1),m-1)<<endl;
	return 0;
}