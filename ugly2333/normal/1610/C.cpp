//CF1610C
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
const int N = 222222;
int n,a[N],b[N];
bool ok(int k){
	int i,x;
	x=1;
	for(i=1;i<=n;i++)
		if(a[i]>=k-x&&b[i]>=x-1)
			x++;
	return x>k;
}
int main()
{
	int T,i,l,r,h;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d %d",a+i,b+i);
		l=1,r=n;
		while(l<r){
			h=(l+r+1)>>1;
			if(ok(h))
				l=h;
			else
				r=h-1;
		}
		printf("%d\n",l);
	}
	return 0;
}