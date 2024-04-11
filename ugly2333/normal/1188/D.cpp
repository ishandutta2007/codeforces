//CF1188D
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
const int N = 111111;
const int inf = 1e9;
int n,b[N],c[N],f[N],g[N];
LL m,a[N];
bool cmp(int x,int y){
	if((a[x]&m)!=(a[y]&m))
		return (a[x]&m)<(a[y]&m);
	return x<y;
}
void go(LL x,int w){
	int l=0,r=n,h;
	while(l<r){
		h=(l+r+1)>>1;
		if((a[c[h]]&m)<=x)
			l=h;
		else
			r=h-1;
	}//cout<<l<<w<<x<<endl;
	if(g[l]>w)
		g[l]=w;
}
int main()
{
	int i,o,r0,r1,c0,c1;
	LL x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%lld",a+i);
	for(i=1;i<=n;i=i+1)
		b[i]=i,c[i]=i;
	m=1;
	sort(c+1,c+n+1,cmp);
	x=1;
	for(o=0;o<60;o=o+1){
		for(i=0;i<=n;i=i+1)
			g[i]=inf;
		r0=0,r1=0;
		for(i=1;i<=n;i=i+1){
			if(a[i]&x)
				r1++;
			else
				r0++;
		}
		c0=0,c1=0;
		for(i=0;i<=n;i=i+1){
			if(i){
				if(a[b[i]]&x)
					c1++;
				else
					c0++;
			}
			if(i<n&&(a[b[i]]&(m>>1))==(a[b[i+1]]&(m>>1)))
				continue;
			y=a[b[i]]&(m>>1);
			go(y,f[i]+c1+r0-c0);
			go(y^x,f[i]+c0+r1-c1);
		}
		for(i=0;i<=n;i=i+1)
			b[i]=c[i],f[i]=g[i];
		m=m<<1|1;
		x<<=1;
		sort(c+1,c+n+1,cmp);
	}
	cout<<f[n];
	return 0;
}