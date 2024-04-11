#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>

#define INF 1000000000000000000LL
#define N 4000

long long f[N][N];
std::pair<int,int>a[N];
int n;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	std::sort(a,a+n);
	for (int i=0;i<=n;i++)for (int j=0;j<=n;j++)
		f[i][j]=INF;
	f[0][0]=a[0].second;
	for (int i=0;i<n-1;i++)
		for (int j=0;j<n;j++)
			if (f[i][j]!=INF){
				f[i+1][j]=std::min(f[i+1][j],f[i][j]+a[i+1].first-a[j].first);
				f[i+1][i+1]=std::min(f[i+1][i+1],f[i][j]+a[i+1].second);
			}
	long long res=INF;
	for (int i=0;i<n;i++)
		res=std::min(res,f[n-1][i]);
	printf("%I64d\n",res);
	return 0;
}