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

#define N 500500
#define M 1500

using namespace std;

int ss[N],ff[N],a[M][M],dest[M][M],o[N],q[N],n,m,k,pred[N],b[M][M];
map<string,int>rev;
vector<pair<int,int> >g[N];

int findset(int x){
	if (pred[x]!=x)pred[x]=findset(pred[x]);
	return pred[x];
}

void dsuunion(int x,int y){
	x=findset(x);
	y=findset(y);
	if (rand()%2==0)swap(x,y);
	for (int e=0;e<m;e++)a[y][e]|=a[x][e];
	pred[x]=y;
}

void solve(){
	memset(dest,0,sizeof(dest));
	memset(o,0,sizeof(o));
	for (int i=0;i<n;i++)pred[i]=i;
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			if ((!o[j])&&((a[findset(ss[j])][j])||(a[findset(ff[j])][j]))){
				o[j]=1;
				dsuunion(ss[j],ff[j]);
			}
	for (int i=0;i<n;i++){
		dest[i][i]=1;
		int qb=0,qe=1;q[1]=i;
		while (qb<qe){
			qb++;
			int x=q[qb];
			for (int j=0;j<g[x].size();j++)
				if ((o[g[x][j].second])&&(!dest[i][g[x][j].first])){
					dest[i][g[x][j].first]=1;
					qe++;
					q[qe]=g[x][j].first;
				}
		}
	}	
}

int main(){
//	freopen("input.txt","r",stdin);
	scanf("%d%d%d\n",&n,&m,&k);
	memset(a,0,sizeof(a));
	for (int i=0;i<m;i++){
		scanf("%d%d\n",&ss[i],&ff[i]);
		--ss[i];--ff[i];
		g[ss[i]].pb(mp(ff[i],i));
		g[ff[i]].pb(mp(ss[i],i));
		o[i]=false;
	}
	for (int i=0;i<k;i++){
		char c;
		int w,ck;
		string s;
		s="";
		c=getchar();
		while (((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z'))){s+=c;c=getchar();}
		scanf("%d%d",&w,&ck);--w;
		rev[s]=w;
		for (int j=0;j<ck;j++){
			int t;
			scanf("%d",&t);--t;
			a[w][t]=1;
		}
		scanf("\n");
	}
	solve();
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)b[i][j]=a[findset(i)][j];
	memset(a,0,sizeof(a));
	for (int i=0;i<k;i++){
		char c;
		int w,ck;
		string s="";
		c=getchar();
		while (((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z'))){s+=c;c=getchar();}
		scanf("%d%d",&w,&ck);--w;
		if (!dest[rev[s]][w]){
			printf("NO\n");
			return 0;
		}
		for (int j=0;j<ck;j++){
			int t;
			scanf("%d",&t);--t;
			a[w][t]=1;
		}
		scanf("\n");
	}
	solve();
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (b[i][j]!=a[findset(i)][j]){
				printf("NO\n");
				return 0;
			}
	printf("YES\n");
}