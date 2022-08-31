//CF1553H
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
const int inf = 1e9;
int k,m,n,a[N],s[N],h[N],f[N];
int mx(int l,int r,int x){
	if(s[r]==s[l])
		return -inf;
	if(r-l==1)
		return l^x;
	int h=l+r>>1;
	if(x&(h-l)){
		if(s[h]==s[l])
			return mx(h,r,x);
		return mx(l,h,x);
	}
	else{
		if(s[h]==s[r])
			return mx(l,h,x);
		return mx(h,r,x);
	}
}
int mn(int l,int r,int x){
	if(s[r]==s[l])
		return inf;
	if(r-l==1)
		return l^x;
	int h=l+r>>1;
	if(x&(h-l)){
		if(s[h]==s[r])
			return mn(l,h,x);
		return mn(h,r,x);
	}
	else{
		if(s[h]==s[l])
			return mn(h,r,x);
		return mn(l,h,x);
	}
}
int main()
{
	int i,j,l,x;
	scanf("%d%d",&n,&k);
	m=1<<k;
	for(i=1;i<=n;i++)
		scanf("%d",&x),a[x]=1;
	for(i=m;i>=0;i--)
		s[i]=s[i+1]+a[i];
	for(i=0;i<m;i++)
		f[i]=inf;
	for(j=k-1;j>=0;j--){
		for(i=0;i<(2<<j);i++)
			h[i]=inf;
		for(l=0;l<m;l=l+(2<<j)){
			for(i=0;i<(1<<j);i++)
				h[i]=min(h[i],mn(l+(1<<j),l+(2<<j),i)-mx(l,l+(1<<j),i));
			for(i=(1<<j);i<(2<<j);i++)
				h[i]=min(h[i],mn(l,l+(1<<j),i)-mx(l+(1<<j),l+(2<<j),i));
		}
		for(i=0;i<m;i++)
			f[i]=min(f[i],h[i&((2<<j)-1)]);
	}
	for(i=0;i<m;i++)
		printf("%d ",f[i]);
	return 0;
}