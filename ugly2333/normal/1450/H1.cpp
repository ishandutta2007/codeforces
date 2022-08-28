//CF1450H1
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
const int N = 1<<20;
const int MO = 998244353;
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	if(!y)
		return 1;
	int z=fpow(x,y>>1);
	z=mul(z,z);
	if(y&1)
		return mul(z,x);
	return z;
}
int n,q,b0,b1,k0,k1,ans;
int fac[N],ifac[N];
char s[N];
int cal(int x){
	if(x<0)
		x=-x;
	if(x&1)
		return 0;
	return x/2;
}
int main()
{
	int i;
	scanf("%d%d%s",&n,&q,s+1);
	fac[0]=1;
	for(i=1;i<=n;i=i+1)
		fac[i]=mul(fac[i-1],i);
	ifac[n]=fpow(fac[n]);
	for(i=n;i>=1;i=i-1)
		ifac[i-1]=mul(ifac[i],i);
	for(i=1;i<=n;i=i+1){
		if(s[i]=='b'){
			if(i&1)
				b1++;
			else
				b0++;
		}
		if(s[i]=='?'){
			if(i&1)
				k1++;
			else
				k0++;
		}
	}
	for(i=0;i<=k0+k1;i=i+1)
		ans=(ans+mul(mul(fac[k0+k1],mul(ifac[i],ifac[k0+k1-i])),cal(i+b1-b0-k0)))%MO;
	cout<<mul(ans,fpow(fpow(2,max(0,k0+k1-1))));
	return 0;
}