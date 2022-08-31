//
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
const int N = 333333;
int n,m,k,a[N],f[N],c[N*3],t[N];
LL b[N];
vector<int> v[N],h[N],g[N*3];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void adg(int x,int y){
	g[x].push_back(y);
	c[y]++;
}
void dfs(int u,int fa,int hh){
	int i,x;
	b[u]=a[u];
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		if(x!=fa){
			dfs(x,u,h[u][i]);
			b[u]+=b[x];
		}
	}
	if(fa){
		if(b[u]>0){
			adg(n+u,n*2+hh);
			adg(n*2+hh,fa);
		}
		else{
			if(b[u]<-k){
				adg(n+fa,n*2+hh);
				adg(n*2+hh,u);
			}
			else{
				adg(fa,n*2+hh);
				adg(n*2+hh,n+fa);
				adg(u,n*2+hh);
				adg(n*2+hh,n+u);
			}
		}
	}
}
queue<int> q;
int main()
{
	int i,j,x,y;
	LL s;
	scanf("%d%d%d",&n,&m,&k);
	s=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		if(i!=1)
			a[i]-=k;
		s+=a[i];
		f[i]=i;
	}
	if(s<0){
		printf("NO\n");
		return 0;
	}
	if(s>0)
		a[1]-=s;
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		if(fnd(x)!=fnd(y)){
			v[x].push_back(y);
			h[x].push_back(i);
			v[y].push_back(x);
			h[y].push_back(i);
			f[fnd(x)]=fnd(y);
			t[i]=1;
		}
	}
	dfs(1,0,0);
	for(i=1;i<=n;i=i+1)
		adg(i,n+i);
	for(i=1;i<=n*2+m;i=i+1)
		if(!c[i])
			q.push(i);
	printf("YES\n");
	for(i=1;i<=n*2+m;i=i+1){
		x=q.front();
		q.pop();
		if(x>n*2&&t[x-n*2]){
			printf("%d\n",x-n*2);
		}
		for(j=0;j<g[x].size();j=j+1){
			y=g[x][j];
			c[y]--;
			if(!c[y])
				q.push(y);
		}
	}
	return 0;
}