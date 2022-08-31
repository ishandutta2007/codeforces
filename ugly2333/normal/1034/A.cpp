//CF 1034A
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
const int N = 333333;
const int W = 15000000;
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int n,a[N],m,pr[N],b[W+55];
bool c[W+55];
int main()
{
	int i,j,f,x=0;
	for(i=2;i<10000;i=i+1){
		f=1;
		for(j=2;f&&j*j<=i;j=j+1)
			if(i%j==0)
				f=0;
		if(f)
			pr[++m]=i;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),x=gcd(x,a[i]);
	for(i=1;i<=n;i=i+1){
		a[i]/=x;
		if(a[i]>1)
			b[a[i]]++;
	}
	x=0;
	for(i=2;i<=W;i=i+1){
		if(c[i])
			continue;
		f=0;
		for(j=i;j<=W;j=j+i)
			f+=b[j],c[j]=1;
		if(x<f)
			x=f;
	}
	if(x==0)
		x=-1;
	else
		x=n-x;
	cout<<x;
	return 0;
}