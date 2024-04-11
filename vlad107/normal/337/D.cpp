#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define mp make_pair
#define pb push_back
#define INF 1000000000
#define N 500500

using namespace std;

vector<int>g[N];
int f[N],p[N],n,m,d,x,y,ans;

void dfs1(int x,int px){
	f[x]=-1;
	if (p[x])f[x]=0;
	for (int i=0;i<g[x].size();i++)
		if (g[x][i]!=px){
			dfs1(g[x][i],x);
			if (f[g[x][i]]!=-1)f[x]=max(f[x],f[g[x][i]]+1);
		}
}

void dfs2(int x,int px,int mf){
	if (p[x])mf=max(mf,0);
	if ((f[x]<=d)&&(mf<=d))ans++;
	int max1=-1,max2=-1;
	int nom1=-1,nom2=-1;
	for (int i=0;i<g[x].size();i++)
		if (g[x][i]!=px){
			if ((f[g[x][i]]!=-1)&&(f[g[x][i]]+1>=max1)){
				max2=max1;
				nom2=nom1;
				max1=f[g[x][i]]+1;
				nom1=g[x][i];
			}else
			if ((f[g[x][i]]!=-1)&&(f[g[x][i]]+1>max2)){
				max2=f[g[x][i]]+1;
				nom2=g[x][i];
			}
		}
	for (int i=0;i<g[x].size();i++)
		if (g[x][i]!=px){
			int nf=mf;
			if (nom1==g[x][i])
				nf=max(nf,max2);
			else nf=max(nf,max1);
			dfs2(g[x][i],x,nf+((nf==-1)?0:1));
		}
}

int main(){
	scanf("%d%d%d",&n,&m,&d);
	for (int i=0;i<m;i++){
		scanf("%d",&x);--x;
		p[x]=1;
	}
	for (int i=0;i<n-1;i++){
		scanf("%d%d",&x,&y);
		--x;--y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs1(0,-1);
	dfs2(0,-1,-1);
	printf("%d\n",ans);
}