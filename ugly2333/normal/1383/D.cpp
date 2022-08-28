//CF1383D
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
const int N = 255;
const int W = N*N;
int n,m,a[N][N],b[N],c[N],d[N][N],e[W],f[W];
vector<int> v[W];
queue<int> q;
set<int> S;
set<int>::iterator it;
int id(int x,int y){
	return x*N+y;
}
void adde(int x,int y,int z){
	if(z)
		swap(x,y);
	v[x].push_back(y);
	e[y]++;
}
int main()
{
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			scanf("%d",&a[i][j]),b[i]=max(b[i],a[i][j]),c[j]=max(c[j],a[i][j]);
	sort(b+1,b+n+1),sort(c+1,c+m+1);
	reverse(b+1,b+n+1),reverse(c+1,c+m+1);
	for(i=0,j=0;i<n||j<m;){
		if(b[i+1]==c[j+1]){
			i++,j++;
			d[i][j]=b[i];
		}
		else{
			if(b[i+1]>c[j+1])
				i++,d[i][j]=b[i];
			else
				j++,d[i][j]=c[j];
		}
	}
	for(i=1;i<=n*m;i=i+1)
		S.insert(i);
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			f[id(i,j)]=W;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			if(d[i][j])
				f[id(i,j)]=d[i][j];
	for(i=1;i<=n;i=i+1){
		x=0;
		for(j=1;j<m;j=j+1){
			if(d[i][j]&&d[i][j+1])
				continue;
			if(d[i][j])
				x=1;
			adde(id(i,j+1),id(i,j),x);
		}
	}
	for(j=1;j<=m;j=j+1){
		x=0;
		for(i=1;i<n;i=i+1){
			if(d[i][j]&&d[i+1][j])
				continue;
			if(d[i][j])
				x=1;
			adde(id(i+1,j),id(i,j),x);
		}
	}
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			if(!e[id(i,j)])
				q.push(id(i,j));
	while(!q.empty()){
		x=q.front();
		q.pop();
		it=S.upper_bound(f[x]);
		it--;
		f[x]=(*it);
		S.erase(it);
		for(i=v[x].size();i--;){
			y=v[x][i];
			f[y]=min(f[y],f[x]-1);
			e[y]--;
			if(!e[y])
				q.push(y);
		}
	}
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=m;j=j+1)
			printf("%d ",f[id(i,j)]);
		printf("\n");
	}
	return 0;
}