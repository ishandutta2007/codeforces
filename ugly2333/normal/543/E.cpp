//CF543E
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
const int N = 2e5+25;
const int B = 800;
const int M = 255;
const int B2 = 1666;
int n,k,a[N],l[N],r[N],e[N],b[N],d[N];
int m,bl[M],br[M],s[M],t[M][B2],f[M][B2],g[M][B2];
int q,w,h[N],u[N];
vector<int> v[N];
void go(int x,int y,int z){
	if(l[x]<0){
		l[x]=y;
		e[x]=z;
	}
	else
		r[x]=y-1;
	u[b[x]]=1;
}
int main()
{
	int i,j,x,y,z,o,p;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		if(i%B==1)
			m++,bl[m]=i;
		b[i]=m,br[m]=i;
		h[i]=a[i];
	}
	sort(h+1,h+n+1);
	w=unique(h+1,h+n+1)-h-1;
	for(i=1;i<=n;i=i+1){
		a[i]=lower_bound(h+1,h+w+1,a[i])-h;
		v[a[i]].push_back(i);
		l[i]=-1,r[i]=w;
	}
	for(x=1;x<=w;x=x+1){
		d[x]=d[x-1];
		for(y=v[x].size();y--;){
			i=v[x][y];
			if(i>=k)
				go(i-k+1,x,1);
			else
				d[x]++;
			if(i<n)
				go(i+1,x,-1);
		}
		for(i=1;i<=m;i=i+1){
			if(u[i]){
				t[i][++s[i]]=x;
				o=0,p=0;
				for(j=bl[i];j<=br[i];j=j+1)
					if(l[j]<=x&&x<=r[j])
						o+=e[j],p=min(p,o);
				f[i][s[i]]=o,g[i][s[i]]=p;
				u[i]=0;
			}
		}
	}
	p=0;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&x,&y,&z);
		z^=p;
		z=lower_bound(h+1,h+w+1,z)-h-1;
		o=d[z];
		//cout<<z<<o<<endl;
		for(i=1;i<b[x];i=i+1){
			j=upper_bound(t[i]+1,t[i]+s[i]+1,z)-t[i]-1;
			o+=f[i][j];
		}
		i=b[x];
		for(j=bl[i];j<=x;j=j+1)
			if(l[j]<=z&&z<=r[j])
				o+=e[j];
		//cout<<l[1]<<r[1]<<e[1]<<endl;
		p=o;
		if(b[x]!=b[y]){
			for(j=x+1;j<=br[i];j=j+1)
				if(l[j]<=z&&z<=r[j])
					o+=e[j],p=min(p,o);
			for(i=b[x]+1;i<b[y];i=i+1){
				j=upper_bound(t[i]+1,t[i]+s[i]+1,z)-t[i]-1;
				p=min(p,o+g[i][j]);
				o+=f[i][j];
			}
			i=b[y];
			for(j=bl[i];j<=y;j=j+1)
				if(l[j]<=z&&z<=r[j])
					o+=e[j],p=min(p,o);
		}
		else{
			for(j=x+1;j<=y;j=j+1)
				if(l[j]<=z&&z<=r[j])
					o+=e[j],p=min(p,o);
		}
		printf("%d\n",p);
	}
	return 0;
}