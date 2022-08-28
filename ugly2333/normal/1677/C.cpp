//CF1677C
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
int n,a[N],b[N],f[N],g[N],s[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int main()
{
	int T,i,x;
	LL o;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		for(i=1;i<=n;i++)
			f[i]=i,g[i]=0,s[i]=0;
		for(i=1;i<=n;i++)
			f[fnd(a[i])]=fnd(b[i]);
		for(i=1;i<=n;i++)
			g[fnd(i)]++;
		for(i=1;i<=n;i++)
			if(g[i])
				s[g[i]]++;
		x=0;
		for(i=1;i<=n;i++)
			x+=s[i]*(i/2);
		o=(LL)x*(x+1)/2;
		o=(LL)x*(n+1)-o*2;
		printf("%lld\n",o*2);
	}
	return 0;
}