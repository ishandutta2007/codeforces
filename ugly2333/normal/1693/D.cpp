//CF1693D
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
int n,a[N],f[N],g[N],t[N];
int main()
{
	int n,i,j,x,y,o;
	LL s=0;
	scanf("%d",&n);
	for(i=2;i<=n+1;i++)
		scanf("%d",a+i);
	a[0]=n+1,a[1]=0;
	if(n==1){
		printf("%d\n",1);
		return 0;
	}
	for(i=0;i<=n;i++)
		f[i]=i,g[i]=i;
	x=1;
	o=0;
	for(i=2;i<=n;i++){
		if(!o){
			if(a[i]>a[i+1]){
				if(a[i-1]<a[i+1])
					f[i]=min(f[i],g[i-1]);
				for(j=i-1;j>=x-1;j--)
					if(a[j]>a[i+1])
						g[i]=min(g[i],f[j]);
				o=1;
				x=i;
			}
			else{
				if(a[i-1]<a[i+1])
					f[i]=min(f[i],g[i-1]);
				if(a[x-1]>a[i+1])
					g[i]=min(g[i],f[x-1]);
				o=0;
			}
			g[i]=min(g[i],x);
		}
		else{
			if(a[i]<a[i+1]){
				if(a[i-1]>a[i+1])
					g[i]=min(g[i],f[i-1]);
				for(j=i-1;j>=x-1;j--)
					if(a[j]<a[i+1])
						f[i]=min(f[i],g[j]);
				o=0;
				x=i;
			}
			else{
				if(a[i-1]>a[i+1])
					g[i]=min(g[i],f[i-1]);
				if(a[x-1]<a[i+1])
					f[i]=min(f[i],g[x-1]);
				o=1;
			}
			f[i]=min(f[i],x);
		}
		if(!o)
			s+=i+1-max(2,min(min(f[i],g[i]),min(f[x],f[x-1])));
		else
			s+=i+1-max(2,min(min(f[i],g[i]),min(g[x],g[x-1])));
	}
	printf("%lld\n",s+n);
	return 0;
}