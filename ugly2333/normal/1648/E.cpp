//CF1648E
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
const int inf = 1e9+N;
int n,m,f[N],g[N],e[N];
vector<int> v[N],a[N],b[N],c[N],d[N];
pair<int,LL> p[N];
LL r[N];
int ex(int x,int y){
	return *lower_bound(v[x].begin(),v[x].end(),y)==y;
}
int ff(int x){
	if(f[x]==x)
		return x;
	return f[x]=ff(f[x]);
}
void chg(int x,int y,int z){
	g[x]=y;
	c[x].push_back(y);
	d[x].push_back(z);
}
int uni(int x,int y){
	int i,j;
	for(i=0;i<b[x].size();i++)
		for(j=0;j<b[y].size();j++)
			if(!ex(b[x][i],b[y][j]))
				return 1;
	return 0;
}
int mrg(int x,int y,int z){
	int i,o;
	if(b[x].size()<b[y].size())
		swap(x,y);
	for(i=0;i<b[y].size();i++){
		o=b[y][i];
		b[x].push_back(o);
		chg(o,x,z);
	}
	return x;
}
int main()
{
	int T,i,j,k,l,x,y,z,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			v[x].push_back(y);
			v[y].push_back(x);
			r[i]=(LL)x<<32|y;
			p[i]=make_pair(z,r[i]);
		}
		for(i=1;i<=n;i++){
			sort(v[i].begin(),v[i].end());
			v[i].push_back(N);
		}
		sort(p+1,p+m+1);
		for(i=1;i<=n;i++){
			f[i]=i;
			chg(i,i,-1);
			a[i].push_back(i);
			b[i].push_back(i);
		}
		for(i=1;i<=m+1;i++){
			x=p[i].second>>32;
			y=p[i].second&(((LL)1<<32)-1);
			z=p[i].first;
			x=ff(x);
			y=ff(y);
			if(x==y)
				continue;
			for(j=0;j<a[y].size();j++){
				o=a[y][j];
				l=-1;
				for(k=0;k<a[x].size();){
					if(uni(a[x][k],o)){
						if(l>=0){
							a[x][l]=mrg(a[x][l],a[x][k],z);
							swap(a[x][k],a[x][a[x].size()-1]);
							a[x].pop_back();
						}
						else
							l=k,k++;
					}
					else
						k++;
				}
			}
			for(j=0;j<a[y].size();j++){
				o=a[y][j];
				e[j]=-1;
				for(k=0;k<a[x].size();k++){
					if(uni(a[x][k],o))
						e[j]=k;
				}
				//cout<<j<<' '<<o<<' '<<e[j]<<endl;
			}
			for(j=0;j<a[y].size();j++){
				o=a[y][j];
				if(e[j]>=0)
					a[x][e[j]]=mrg(a[x][e[j]],o,z);
				else
					a[x].push_back(o);
			}
			f[y]=x;
			/*cout<<x<<' '<<y<<endl;
			for(j=1;j<=n;j++)
				cout<<j<<' '<<f[j]<<' '<<g[j]<<endl;*/
		}
		for(i=1;i<=n;i++)
			chg(i,0,inf);
		for(i=1;i<=m;i++){
			x=r[i]>>32;
			y=r[i]&(((LL)1<<32)-1);
			j=0,k=0;
			while(c[x][j]!=c[y][k]){
				z=min(d[x][j+1],d[y][k+1]);
				if(d[x][j+1]==z)
					j++;
				if(d[y][k+1]==z)
					k++;
			}
			printf("%d ",z);
		}
		printf("\n");
		for(i=1;i<=n;i++){
			v[i].clear();
			a[i].clear();
			b[i].clear();
			c[i].clear();
			d[i].clear();
			f[i]=0,g[i]=0;
		}
	}
	return 0;
}