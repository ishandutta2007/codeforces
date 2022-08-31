//CF1097D
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
const int N = 11111;
const int MO = 1e9+7;
int ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
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
LL n,ans=1;
int k;
int e[66],f[66][66];
int main()
{
	int i,j,l,x;
	LL t;
	cin>>n>>k;
	for(i=1;i<=65;i=i+1)
		e[i]=fpow(i);
	for(i=1;i<=64;i=i+1){
		f[i][i]=1;
		for(j=1;j<=k;j=j+1){
			for(l=0;l<=i;l=l+1)
				f[i][l]=mul(f[i][l],e[l+1]);
			for(l=i;l>=0;l=l-1)
				ad(f[i][l],f[i][l+1]);
		}
	}
	for(t=2;t*t<=n;t=t+1){
		if(n%t==0){
			i=0;
			while(n%t==0){
				i++;
				n/=t;
			}
			l=1;
			x=0;
			for(j=0;j<=i;j=j+1){
				ad(x,mul(l,f[i][j]));
				l=mul(l,t%MO);
			}
			ans=mul(ans,x);
		}
	}
	if(n>1){
		t=n;
		i=1;
		l=1;
		x=0;
		for(j=0;j<=i;j=j+1){
			ad(x,mul(l,f[i][j]));
			l=mul(l,t%MO);
		}
		ans=mul(ans,x);
	}
	cout<<ans;
	return 0;
}