//CF1610E
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
int n,a[N];
int lb(int x){
	return lower_bound(a+1,a+n+1,x)-a;
}
int solve(int i){
	int j=i,s=1,k;
	while(a[j+1]==a[i]){
		j++;
		s++;
	}
	if(j>=n){
		return s;
	}
	j++;
	s++;
	while(1){
		k=lb(a[j]*2-a[i]);
		if(k>n)
			return s;
		j=k;
		s++;
	}
}
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		a[n+1]=1e9+N;
		x=0;
		for(i=1;i<=n;i++)
			if(a[i]!=a[i-1])
				x=max(x,solve(i));
		printf("%d\n",n-x);
	}
	return 0;
}