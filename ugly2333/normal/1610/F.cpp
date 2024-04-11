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
const int N = 333333;
int n,m,a[N],b[N],c[N],d1[N],d2[N],e[N],f1[N],f2[N];
vector<int> v1[N],h1[N],v2[N],h2[N],g[N];
void adg(int x,int y){
	g[x].push_back(y);
	g[y].push_back(x);//cout<<x<<' '<<y<<endl;
}
int dfs11(int u){
	e[u]=1;
	f1[u]=v1[u].size()%2;
	int i,x,o,r=0;
	for(i=0;i<v1[u].size();i++){
		x=v1[u][i];
		if(!e[x]){
			o=dfs11(x);
			f1[u]^=f1[x];
			if(f1[x]){
				if(r)
					adg(r,o),r=0;
				else
					r=o;
			}
		}
	}
	if(r){
		if(v1[u].size()%2)
			adg(r,u),r=0;
		return r;
	}
	return u;
}
int dfs21(int u){
	e[u]=1;
	f2[u]=v2[u].size()%2;
	int i,x,o,r=0;
	for(i=0;i<v2[u].size();i++){
		x=v2[u][i];
		if(!e[x]){
			o=dfs21(x);
			f2[u]^=f2[x];
			if(f2[x]){
				if(r)
					adg(r,o),r=0;
				else
					r=o;
			}
		}
	}
	if(r){
		if(v2[u].size()%2)
			adg(r,u),r=0;
		return r;
	}
	return u;
}
void dfsg(int u){
	e[u]=1;
	int i,x,r=0;
	for(i=0;i<g[u].size();i++){
		x=g[u][i];
		if(!e[x]){
			c[x]=c[u]^1;
			dfsg(x);
		}
	}
}
void dfs12(int u){
	int i,x;
	e[u]=1;
	if(v1[u].size()%2){
		if(c[u])
			d1[u]=1;
		else
			d1[u]=-1;
	}
	for(i=0;i<v1[u].size();i++){
		x=v1[u][i];
		if(!e[x]){
			dfs12(x);
			d1[u]+=d1[x];
			if(f1[x]){
				if(d1[x]>0){
					b[h1[u][i]/2]=h1[u][i]%2+1;
					a[u]--,a[x]++;
				}
				else{
					b[h1[u][i]/2]=((h1[u][i]%2)^1)+1;
					a[u]++,a[x]--;
				}
			}
		}
	}
}
void dfs22(int u){
	int i,x;
	e[u]=1;
	if(v2[u].size()%2){
		if(c[u])
			d2[u]=1;
		else
			d2[u]=-1;
	}
	for(i=0;i<v2[u].size();i++){
		x=v2[u][i];
		if(!e[x]){
			dfs22(x);
			d2[u]+=d2[x];
			if(f2[x]){
				if(d2[x]<0){
					b[h2[u][i]/2]=h2[u][i]%2+1;
					a[u]-=2,a[x]+=2;
				}
				else{
					b[h2[u][i]/2]=((h2[u][i]%2)^1)+1;
					a[u]+=2,a[x]-=2;
				}
			}
		}
	}
}
int sz[N];
void dfs13(int u){
	int i,x;
	for(i=sz[u]-1;i>=0;i=sz[u]-1){
		sz[u]=i;
		if(b[h1[u][i]/2])
			continue;
		x=v1[u][i];
		b[h1[u][i]/2]=h1[u][i]%2+1;
		//a[u]--,a[x]++;
		dfs13(x);
	}
}
void dfs23(int u){
	int i,x;
	for(i=sz[u]-1;i>=0;i=sz[u]-1){
		sz[u]=i;
		if(b[h2[u][i]/2])
			continue;
		x=v2[u][i];
		b[h2[u][i]/2]=h2[u][i]%2+1;
		//a[u]-=2,a[x]+=2;
		dfs23(x);
	}
}

int main()
{
	int i,x,y,z;
	scanf("%d%d",&n,&m);
	//n=30000,m=50000;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		//x=rand()%n+1,y=rand()%n+1,z=rand()%2+1;
		if(z==1){
			v1[x].push_back(y);
			v1[y].push_back(x);
			h1[x].push_back(i*2);
			h1[y].push_back(i*2+1);
		}
		else{
			v2[x].push_back(y);
			v2[y].push_back(x);
			h2[x].push_back(i*2);
			h2[y].push_back(i*2+1);
		}
	}
	memset(e,0,sizeof(e));
	for(i=1;i<=n;i++)
		if(!e[i])
			dfs11(i);//cout<<endl;
	memset(e,0,sizeof(e));
	for(i=1;i<=n;i++)
		if(!e[i])
			dfs21(i);
	memset(e,0,sizeof(e));
	for(i=1;i<=n;i++)
		if(!e[i])
			dfsg(i);
	memset(e,0,sizeof(e));
	for(i=1;i<=n;i++)
		if(!e[i])
			dfs12(i);
	memset(e,0,sizeof(e));
	for(i=1;i<=n;i++)
		if(!e[i])
			dfs22(i);
	for(i=1;i<=n;i++)
		sz[i]=v1[i].size();
	for(i=1;i<=n;i++)
		dfs13(i);
	for(i=1;i<=n;i++)
		sz[i]=v2[i].size();
	for(i=1;i<=n;i++)
		dfs23(i);
	x=0;
	for(i=1;i<=n;i++)
		if(v1[i].size()&1)
			x++;
	//printf("%d\n",x);
	//for(i=1;i<=n;i++)
	//	printf("%d %d %d %d\n",i,a[i],c[i],d1[i]);printf("\n");
	x=0;
	for(i=1;i<=n;i++)
		if(abs(a[i])==1)
			x++;
	printf("%d\n",x);
	for(i=1;i<=m;i++)
		printf("%d",b[i]);
	return 0;
}