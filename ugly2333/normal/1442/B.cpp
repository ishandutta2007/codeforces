//CF1442B
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
int n,m,a[N],b[N],c[N],f[N],g[N],h[N];
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i=i+1)
			c[i]=0;
		for(i=1;i<=n;i=i+1)
			scanf("%d",a+i);
		for(i=1;i<=m;i=i+1)
			scanf("%d",b+i),c[b[i]]=i;
		for(i=1;i<=n;i=i+1)
			a[i]=c[a[i]];
		a[0]=N,f[0]=0,g[0]=0,h[0]=1;
		for(i=1;i<=n;i=i+1){
			f[i]=0,g[i]=0,h[i]=0;
			if(a[i]){
				f[i]=h[i-1];
				ad(f[i],g[i-1]);
				if(a[i-1]>a[i])
					ad(f[i],f[i-1]);
				h[i]=g[i-1];
				if(a[i-1]<a[i])
					ad(h[i],h[i-1]);
			}
			else{
				ad(g[i],f[i-1]);
				ad(g[i],g[i-1]);
				ad(g[i],h[i-1]);
			}//cout<<a[i]<<' '<<f[i]<<' '<<g[i]<<' '<<h[i]<<endl;
		}
		ad(g[n],h[n]);
		printf("%d\n",g[n]);
	}
	return 0;
}