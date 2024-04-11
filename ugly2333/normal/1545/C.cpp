//CF1545C
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
const int N = 1111;
const int MO = 998244353;
int n,a[N][N],b[N][N],c[N][N],d[N*2],e[N*2],f[N*2],p[N*2];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void uni(int x,int y){
	f[fnd(x)]=fnd(y);
}
int chk(int u){
	int i,j,k;
	vector<int> v;
	for(i=1;i<=n*2;i++)
		if(fnd(i)==fnd(u))
			v.push_back(i);
	for(i=0;i<v.size();i++){
		for(j=i+1;j<v.size();j++){
			for(k=1;k<=n;k++)
				if(a[v[i]][k]==a[v[j]][k])
					return 0;
		}
	}
	for(i=0;i<v.size();i++)
		e[v[i]]=1;
	for(i=n*2+1;i<=n*4;i++)
		if(fnd(i)==fnd(u))
			e[i-n*2]=-1;
	return 1;
}
int main()
{
	int T,i,j,k,x,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n*2;i++)
			for(j=1;j<=n;j++)
				scanf("%d",a[i]+j);
		while(1){
			memset(c,0,sizeof(c));
			for(i=1;i<=n*2;i++){
				if(e[i])
					continue;
				for(j=1;j<=n;j++)
					c[j][a[i][j]]++;
			}
			x=0;
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++)
					if(c[i][j]==1){
						x=1;
						break;
					}
				if(x)
					break;
			}
			if(!x)
				break;
			//cout<<i<<j<<endl;
			for(k=1;k<=n*2;k++)
				if(!e[k]&&a[k][i]==j)
					break;
			e[k]=1;
			for(i=1;i<=n*2;i++){
				if(e[i])
					continue;
				for(j=1;j<=n;j++)
					if(a[i][j]==a[k][j])
						e[i]=-1;
			}
		}
		for(i=1;i<=n*2;i++)
			if(!e[i])
				f[i]=i,f[n*2+i]=n*2+i;
		for(j=1;j<=n;j++){
			memset(d,0,sizeof(d));
			for(i=1;i<=n*2;i++){
				if(!e[i]){
					x=a[i][j];
					if(d[x])
						p[i]=d[x],p[d[x]]=i;
					else
						d[x]=i;
				}
			}
			for(i=1;i<=n*2;i++){
				if(!e[i]){//cout<<i<<' '<<p[i]<<endl;
					uni(i,n*2+p[i]);
					uni(n*2+i,p[i]);
				}
			}
		}
		ans=1;
		for(i=1;i<=n*2;i++){
			if(!e[i]){
				//cout<<i<<endl;
				x=chk(i)+chk(n*2+i);
				ans=ans*x%MO;
			}
		}
		printf("%d\n",ans);
		for(i=1;i<=n*2;i++)
			if(e[i]==1)
				printf("%d ",i);
		printf("\n");
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(p));
	}
	return 0;
}