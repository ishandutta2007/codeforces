#include<stdio.h>
#include<iostream>
#define inf 1000000000
using namespace std;
const int maxn=100005,maxk=505;
int n,m,k;
int f[maxk][maxk],c[maxn],l[maxn],r[maxn],bel[maxn],dsu[maxn];
int find(int x){
	return dsu[x]==x? x:dsu[x]=find(dsu[x]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]),l[i]=r[i-1]+1,r[i]=l[i]+c[i]-1;
		for(int j=l[i];j<=r[i];j++)
			bel[j]=i,dsu[j]=j;
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			f[i][j]=i==j? 0:inf;
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(z==0)
			dsu[find(x)]=find(y);
		if(bel[x]!=bel[y])
			f[bel[x]][bel[y]]=f[bel[y]][bel[x]]=min(f[bel[x]][bel[y]],z);
	}
	for(int i=1;i<=k;i++)
		for(int j=l[i];j<r[i];j++)
			if(find(j)!=find(j+1)){
				puts("No");
				return 0;
			}
	puts("Yes");
	for(int p=1;p<=k;p++)
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++)
				f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			printf("%d%c",f[i][j]==inf? -1:f[i][j],j==k? '\n':' ');
	return 0;
}