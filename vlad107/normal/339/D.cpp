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

#define N 200500

using namespace std;

int a[18][N],n,m,b[N];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=(1<<n);i++)scanf("%d",&a[0][i]);
	b[0]=(1<<n);
	for (int i=1;i<=n;i++){
		b[i]=b[i-1]>>1;
		for (int j=1;j<=b[i];j++)
			if (i%2==1)
				a[i][j]=a[i-1][2*j-1]|a[i-1][2*j];
			else a[i][j]=a[i-1][2*j-1]^a[i-1][2*j];
	}
	for (int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[0][x]=y;
		for (int j=1;j<=n;j++){
			x=(x+1)/2;
			if (j%2==1)
				a[j][x]=a[j-1][2*x-1]|a[j-1][2*x];
			else a[j][x]=a[j-1][2*x-1]^a[j-1][2*x];
		}
		printf("%d\n",a[n][1]);
	}
}