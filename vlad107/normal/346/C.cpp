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

#define N 1111111

using namespace std;

int n,a[N],l,r,m,f[N],g[N];
vector<int>u[N];
multiset<int>s;

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	scanf("%d%d",&r,&l);
	if (l==r){
		puts("0");
		return 0;
	}
	sort(a,a+n);
	int m=1;
	for (int i=1;i<n;i++)
		if (a[i]!=a[m-1]){
			a[m]=a[i];
			m++;
		}
	n=m;
	for (int i=l;i<=r;i++)f[i-l]=2;
	for (int i=0;i<n;i++){
		int x=a[i];
		int ll=l/x;
		if (x*ll<l)ll++;
		for (int j=x*ll;j<=r;j+=x)f[j-l]=max(f[j-l],x);
	}
	int k=r-l;
	for (int i=0;i<=k;i++)
		if (i+f[i]<=k)u[i+f[i]].pb(i);
	g[0]=0;
	s.insert(g[0]);
	for (int i=1;i<=k;i++){
		for (int j=0;j<u[i].size();j++)
			s.erase(s.find(g[u[i][j]]));
		g[i]=(*s.begin())+1;
		s.insert(g[i]);
	}
	printf("%d\n",g[k]);
}