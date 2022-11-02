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

#define N 1000000

int res,sm,fs,n,f[N],a[N],sum[N];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&n);
	sum[0]=0;
	f[0]=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		f[i]=std::max(-sum[i],f[i-1]+a[i]);
	}
	res=f[n];
	fs=0;
	sm=0;
	for (int i=n;i;i--){
		sm+=a[i];
		if (res<f[i-1]-sm)
			res=f[i-1]-sm;
	}
	printf("%d\n",res);
	return 0;
}