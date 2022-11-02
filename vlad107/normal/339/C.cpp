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

#define N 1111

using namespace std;

int a[N],f[N][11][11],n,p1[N][11][11],p2[N][11][11];
string s;

int main(){
	cin>>s;
	scanf("%d",&n);
	f[0][0][0]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<=10;j++)
			for (int k=0;k<=10;k++)
				if (f[i][j][k])
					for (int t=j+1;t<=10;t++)
						if ((t!=k)&&(s[t-1]=='1')){
							f[i+1][t-j][t]=1;
							p1[i+1][t-j][t]=j;
							p2[i+1][t-j][t]=k;
						}
	int x=-1,y=-1;
	for (int i=1;i<=10;i++)
		for (int j=1;j<=10;j++)
			if (f[n][i][j]){
				x=i;y=j;
			}
	if (x<0){
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i=n;i>=1;i--){
		a[i]=y;
		int px=p1[i][x][y],py=p2[i][x][y];
		x=px;y=py;
	}
	for (int i=1;i<=n;i++)printf("%d ",a[i]);
	puts("");
}