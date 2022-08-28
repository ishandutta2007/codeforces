//CF 1028H
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
const int W = 5050000;
int m,pr[N],k,e[N],g[333],h[333];
int n,q,a[N],ans[W];
int b[W][8],c[22],d[W];
vector<pair<int,int> > v[N];
void modify(int x,int y){
	for(int i=0;i<8;i=i+1)
		if(c[k+i-d[x]]<b[x][i])
			c[k+i-d[x]]=b[x][i];
	if(b[x][k]<y)
		b[x][k]=y;
}
int query(int x){
	for(int i=0;i<22;i=i+1)
		if(c[i]>=x)
			return i;
	return -1;
}
int main()
{
	int i,j,x,y;
	m=0;
	for(i=2;i<=3000;i=i+1){
		x=1;
		for(j=2;j*j<=i;j=j+1)
			if(i%j==0)
				x=0;
		if(x)
			pr[++m]=i;
	}
	for(i=1;i<(1<<8);i=i+1)
		g[i]=g[i^(i&-i)]+2;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<=q;i=i+1){
		scanf("%d%d",&x,&y);
		v[y].push_back(make_pair(x,i));
	}
	for(i=1;i<=n;i=i+1){
		k=0;
		for(j=1;j<=m;j=j+1){
			x=0;
			while(a[i]%pr[j]==0){
				x++;
				a[i]/=pr[j];
			}
			if(x&1)
				e[k++]=pr[j];
		}
		if(a[i]>1)
			e[k++]=a[i];
		h[0]=1;
		for(j=0;j<k;j=j+1)
			h[1<<j]=e[j];
		for(j=1;j<(1<<k);j=j+1)
			h[j]=h[j^(j&-j)]*h[j&-j];
		for(j=0;j<(1<<k);j=j+1)
			d[h[j]]=g[j],modify(h[j],i);
		for(j=v[i].size();j--;)
			ans[v[i][j].second]=query(v[i][j].first);
	}
	for(i=1;i<=q;i=i+1)
		printf("%d\n",ans[i]);
	return 0;
}