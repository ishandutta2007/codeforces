//CF1131G
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
const int N = 1e7+17;
const int M = 255555;
const LL inf = 1e18;
void cmin(LL&x,LL y){
	if(x>y)
		x=y;
}
int n,m,a[N],l[N],r[N];
LL b[N],f[N],g[N];
vector<int> A[M],B[M];
int main()
{
	int i,j,o,e,x,y;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i=i+1){
		scanf("%d",&o);
		for(j=1;j<=o;j=j+1){
			scanf("%d",&x);
			A[i].push_back(x-1);
		}
		for(j=1;j<=o;j=j+1){
			scanf("%d",&x);
			B[i].push_back(x);
		}
	}
	e=0;
	scanf("%d",&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		o=A[x].size();
		for(j=0;j<o;j=j+1)
			e++,a[e]=A[x][j],b[e]=(LL)y*B[x][j];
	}
	for(i=1;i<=n;i=i+1){
		l[i]=i;
		while(l[i]>1&&i-a[i]<l[i]){
			l[i]=l[l[i]-1];
		}
	}
	for(i=n;i;i=i-1){
		r[i]=i;
		while(r[i]<n&&i+a[i]>r[i]){
			r[i]=r[r[i]+1];
		}
	}
	f[0]=-inf;
	for(i=1;i<=n;i=i+1){
		cmin(f[r[i]],f[i-1]+b[i]);
		cmin(g[r[i]],f[i-1]+b[i]);
		cmin(f[i],f[l[i]-1]+b[i]);
		l[i]=i;
		while(l[i]>1&&i-a[i]<l[i]){
			cmin(g[i],g[l[i]-1]);
			l[i]=l[l[i]-1];
		}
		cmin(f[i],g[i]+b[i]);
	}
	cout<<f[n]+inf;
	return 0;
}