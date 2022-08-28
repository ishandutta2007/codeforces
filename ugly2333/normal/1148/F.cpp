//CF1148F
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
int n,w[N];
bool c[N];
LL a[N];
bool cnt(LL x){
	bool f=0;
	while(x){
		f^=c[x&65535];
		x>>=16;
	}
	return f;
}
LL cal(LL x,LL e){
	int i;
	LL o=0;
	for(i=1;i<=n;i=i+1){
		if(a[i]&(e-1))
			continue;
		if(cnt(a[i]&x))
			o-=w[i];
		else
			o+=w[i];
	}
	return o;
}
LL solve(LL x,LL e){
	if(e==1)
		return x;
	e>>=1;
	if(cal(x,e)<0)
		return solve(x,e);
	if(cal(x+e,e)<0)
		return solve(x+e,e);
	return solve(x,e);
}
int main()
{
	int i;
	LL o;
	for(i=1;i<(1<<16);i=i+1)
		c[i]=c[i^(i&-i)]^1;
	o=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%lld",w+i,a+i);
		o+=w[i];
	}
	if(o<0){
		for(i=1;i<=n;i=i+1)
			w[i]=-w[i];
	}
	cout<<solve(0,(LL)1<<62);
	return 0;
}