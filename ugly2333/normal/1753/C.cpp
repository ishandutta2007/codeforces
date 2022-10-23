//CF1753C
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
const int N = 222222;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
int n,a[N];
int main()
{
	int T,i,x,y,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		x=0;
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			x+=a[i]==0;
		}
		y=0;
		for(i=1;i<=x;i++)
			y+=a[i];
		s=0;
		while(y){
			ad(s,mul(fpow(y),fpow(y)));
			y--;
		}
		s=mul(s,(LL)n*(n-1)/2%MO);
		printf("%d\n",s);
	}
	return 0;
}