//CF 852F
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
const int N = 1111111;
int fpow(int p,int x,int mod){
	if(x==0)
		return 1;
	if(x==1)
		return p;
	int r;
	r=fpow(p,x/2,mod);
	r=(LL)r*r%mod;
	if(x&1)
		r=(LL)r*p%mod;
	return r;
}
int s[N];
int main()
{
	int n,m,a,q,i,k;
	LL x,c;
	cin>>n>>m>>a>>q;
	x=a;
	i=1;
	while(x%q>1){
		x=(LL)x*a%q;
		i++;
	}
	x=i;
	c=1;
	s[0]=1;
	for(i=1;i<=m;i=i+1){
		c=(LL)c*(m+1-i)%x;
		c=(LL)c*fpow(i,x-2,x)%x;
		s[i]=(LL)(s[i-1]+c)%x;
	}
	for(i=1;i<=n;i=i+1){
		k=min(m,n-i);
		cout<<fpow(a,s[k],q)<<' ';
	}
	return 0;
}