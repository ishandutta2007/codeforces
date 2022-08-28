//CF 963A
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
typedef double DB;
const int mod = 1e9+9;
void add(int& x,int y){
	x+=y;
	if(x>=mod)
		x-=mod;
	if(x<0)
		x+=mod;
}
int mul(int x,int y){
	return (LL)x*y%mod;
}
int fpow(int x,int y=mod-2){
	if(!y)
		return 1;
	int z=fpow(x,y>>1);
	z=mul(z,z);
	if(y&1)
		z=mul(z,x);
	return z;
}
char ch[111111];
int main()
{
	int n,k,a,b,m,c,i,x,s=0;
	cin>>n>>a>>b>>k>>ch;
	n++,m=n/k;
	c=mul(b,fpow(a));
	x=fpow(a,k-1);
	for(i=0;i<k;i=i+1){
		if(ch[i]=='+')
			add(s,x);
		else
			add(s,-x);
		x=mul(x,c);
	}
	s=mul(s,fpow(a,n-k));
	x=fpow(c,k);
	if(x==1)
		x=m;
	else
		x=mul(fpow(x,m)-1+mod,fpow((x-1+mod)%mod));
	cout<<mul(s,x);
	return 0;
}