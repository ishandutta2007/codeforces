//CF1610F
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
const int N = 1111111;
int n,e[N],w[111];
LL a[N],f[N],g[N],b[N],c[N],d[N],ans;
int pc(LL x){
	return __builtin_popcountll(x);
}
void solve(int l,int r){
	if(l==r){
		ans++;
		return;
	}
	int h=l+r>>1;
	solve(l,h);
	solve(h+1,r);
	int i,j,bb,cc;
	f[h]=a[h],g[h]=a[h];
	for(i=h-1;i>=l;i--){
		f[i]=min(f[i+1],a[i]);
		g[i]=max(g[i+1],a[i]);
	}
	f[h+1]=a[h+1],g[h+1]=a[h+1];
	for(i=h+2;i<=r;i++){
		f[i]=min(f[i-1],a[i]);
		g[i]=max(g[i-1],a[i]);
	}
	j=h;
	for(i=h;i>=l;i--){
		while(j<r&&f[i]<=f[j+1]){
			j++;
		}
		b[i]=j;
	}
	j=h;
	for(i=h;i>=l;i--){
		while(j<r&&g[i]>g[j+1]){
			j++;
		}
		c[i]=j;
	}
	j=h+1;
	for(i=h+1;i<=r;i++){
		while(j>l&&f[i]<f[j-1]){
			j--;
		}
		b[i]=j;
	}
	j=h+1;
	for(i=h+1;i<=r;i++){
		while(j>l&&g[i]>=g[j-1]){
			j--;
		}
		c[i]=j;
	}
	for(i=l;i<=h;i++)
		if(pc(f[i])==pc(g[i]))
			ans+=min(b[i],c[i])-h;
	for(i=h+1;i<=r;i++)
		if(pc(f[i])==pc(g[i]))
			ans+=h+1-max(b[i],c[i]);
	for(i=h+1;i<=r;i++)
		d[i]=pc(g[i]);
	memset(w,0,sizeof(w));
	for(i=h+1;i<=b[l];i++)
		w[d[i]]++;
	for(i=h+1;i<=c[l];i++)
		w[d[i]]--;
	bb=b[l],cc=c[l];
	for(i=l;i<=h;i++){
		while(bb>b[i]){
			w[d[bb]]--;
			bb--;
		}
		while(cc>c[i]){
			w[d[cc]]++;
			cc--;
		}
		if(c[i]<b[i])
			ans+=w[pc(f[i])];
	}
	for(i=h+1;i<=r;i++)
		d[i]=pc(f[i]);
	memset(w,0,sizeof(w));
	for(i=h+1;i<=b[l];i++)
		w[d[i]]--;
	for(i=h+1;i<=c[l];i++)
		w[d[i]]++;
	bb=b[l],cc=c[l];
	for(i=l;i<=h;i++){
		while(bb>b[i]){
			w[d[bb]]++;
			bb--;
		}
		while(cc>c[i]){
			w[d[cc]]--;
			cc--;
		}
		if(b[i]<c[i])
			ans+=w[pc(g[i])];
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",a+i);
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}