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

#define N 100500
#define M 1111

using namespace std;

int was[N],a[M][M],n,m;

void rec(int x,int y){
	if (x==n){
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++)printf("%d ",a[i][j]);
			puts("");
		}
		exit(0);
	}
	int nx=x,ny=y+1;
	if (ny==m){++nx;ny=0;}
	for (int i=1;i<=n*m;i++)
		if (!was[i]){
			if ((x>0)&&(abs(a[x-1][y]-i)<2))continue;
			if ((y>0)&&(abs(a[x][y-1]-i)<2))continue;
			a[x][y]=i;
			was[i]=1;
			rec(nx,ny);
			a[x][y]=0;
			was[i]=0;
		}
}

int main(){
	scanf("%d%d",&n,&m);
	memset(was,0,sizeof(was));
	rec(0,0);
	puts("-1");
}