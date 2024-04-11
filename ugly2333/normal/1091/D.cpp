//CF1091D
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
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,ans;
int main()
{
	int i,t,x;
	cin>>n;
	t=1;
	for(i=1;i<=n;i=i+1)
		t=mul(t,i);
	ans=t;
	x=1;
	for(i=1;i<n;i=i+1){
		x=mul(x,n-i+1);
		ad(ans,(t-x+MO)%MO);
	}
	cout<<ans;
	return 0;
}