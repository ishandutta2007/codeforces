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

int n,m,next[N],cost[N],used[N],was[N],rev[N],V[N],b[N],res,bad;
bool first;

void findnext(int x, int e,int &nx,int &nc){
	if (!used[x]){
		res++;
		used[x]=1;
	}
	if (x==bad)next[x]=-1;
	if (next[x]==-1){
		nx=x;
		nc=0;
		return;
	}
	if ((first)&&(rev[x]!=-1)){
		first=0;
		bad=rev[x];
	}
	if (e>=cost[x]){
		int ux,uc;
		findnext(next[x],e-cost[x],ux,uc);
		next[x]=ux;
		cost[x]+=uc;
		nx=next[x];
		nc=cost[x];
		return;
	}
	nx=x;
	nc=0;
}

int main(){
//	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%d",&next[i]);
		--next[i];
	}
	for (int i=0;i<m;i++)scanf("%d",&V[i]);
	for (int i=0;i<m;i++)scanf("%d",&b[i]);
	for (int i=0;i<n;i++)cost[i]=1;
	memset(used,0,sizeof(used));
	memset(was,0,sizeof(was));
	memset(rev,-1,sizeof(rev));
	for (int i=0;i<n;i++)
		if (!was[i]){
			int x=i;
			was[x]=i+1;
			while (was[next[x]]==0){
				x=next[x];
				was[x]=i+1;
			}
			if (was[next[x]]!=i+1)continue;
			int px=x,y=x;
			x=next[x];
			while (x!=y){
				rev[x]=px;
				int nx=next[x];
				px=x;x=nx;
			}
			rev[x]=px;
		}
	for (int i=0;i<m;i++){
		int a=(V[i]+res-1)%n;
		res=0;
		first=1;
		bad=-1;
		int ux,uc;
		findnext(a,b[i]-1,ux,uc);
		printf("%d\n",res);
	}
}