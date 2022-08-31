//CF1534C
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
const int N = 444444;
const int MO = 1e9+7;
int n,a[N],b[N],f[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		for(i=1;i<=n;i++)
			f[i]=i;
		for(i=1;i<=n;i++)
			f[fnd(a[i])]=fnd(b[i]);
		x=1;
		for(i=1;i<=n;i++)
			if(fnd(i)==i)
				x=x*2%MO;
		printf("%d\n",x);
	}
	return 0;
}