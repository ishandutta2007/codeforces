//CF1654G
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
int n,a[N],d[N],f[N],s[N];
vector<int> v[N],g[N];
int he,ta,q[N*2];
int main()
{
	int i,x,y,o;
	scanf("%d",&n);
	he=0,ta=0;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i])
			q[ta++]=i,d[i]=1;
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	while(he<ta){
		x=q[he++];
		for(i=0;i<v[x].size();i++){
			y=v[x][i];
			if(!d[y]){
				d[y]=d[x]+1;
				q[ta++]=y;
			}
		}
	}
	for(x=1;x<=n;x++){
		o=0;
		for(i=0;i<v[x].size();i++){
			y=v[x][i];
			if(d[x]==d[y])
				o=1;
		}
		if(o)
			g[d[x]].push_back(x);
	}
	for(i=1;i<=n;i++)
		s[i]=-1;
	for(o=0;o<=n;o++){
		if(!g[o].size())
			continue;
		he=N,ta=N;
		for(i=1;i<=n;i++)
			f[i]=N;
		for(i=0;i<g[o].size();i++)
			f[g[o][i]]=1+o,q[ta++]=g[o][i];//cout<<o<<endl;
		while(he<ta){
			x=q[he++];//cout<<x<<' '<<f[x]-d[x]<<endl;
			for(i=0;i<v[x].size();i++){
				y=v[x][i];
				if(d[y]==d[x]||(d[y]>d[x]&&f[x]==d[x])){
					if(f[y]>f[x]+1){
						f[y]=f[x]+1;
						q[ta++]=y;
					}
				}
				if(d[y]>d[x]&&f[x]>d[x]){
					if(f[y]>f[x]){
						f[y]=f[x];
						q[--he]=y;
					}
				}
			}
		}
		for(i=1;i<=n;i++)
			if(f[i]==d[i]&&s[i]==-1)
				s[i]=o;
	}
	for(i=1;i<=n;i++){
		if(s[i]==-1)
			printf("%d ",d[i]-1);
		else
			printf("%d ",(d[i]-1)*2-(s[i]-1));
	}
	return 0;
}