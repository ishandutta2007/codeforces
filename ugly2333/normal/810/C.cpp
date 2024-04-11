//CF 810C
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
const int mod = 1000*1000*1000+7;
typedef long long LL;
int a[333333],p2[333333];
int solve(int l,int r)
{
	int m,i;
	LL ans,s;
	if(l==r)
		return 0;
	if(l==r-1)
		return a[r]-a[l];
	m=(l+r)/2;
	ans=solve(l,m)+solve(m+1,r);
	ans%=mod;
	for(i=l;i<=m;i=i+1){
		s=(LL)(a[m]-a[i])*p2[m-i];
		s%=mod;
		s=(LL)s*(p2[r-m]+mod-1);
		s%=mod;
		ans+=s;
	}
	ans%=mod;
	for(i=m+1;i<=r;i=i+1){
		s=(LL)(a[i]-a[m])*p2[i-m-1];
		s%=mod;
		s=(LL)s*(p2[m-l+1]+mod-1);
		s%=mod;
		ans+=s;
	}
	ans%=mod;
	return ans;
}
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	sort(a+1,a+n+1);
	p2[0]=1;
	for(i=1;i<=n;i=i+1)
		p2[i]=(p2[i-1]*2)%mod;
	cout<<solve(1,n)<<endl;
	return 0;
}