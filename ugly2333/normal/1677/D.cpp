//CF1677D
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
const int N = 2e6+26;
const int MO = 998244353;
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,k,a[N];
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		x=1;
		for(i=n-k+1;i<=n;i++)
			if(a[i]>=1)
				x=0;
		for(i=1;i<=k;i++)
			x=mul(x,i);
		for(i=1;i<=n-k;i++){
			if(a[i]==-1)
				x=mul(x,i+k);
			if(a[i]==0)
				x=mul(x,k+1);
		}
		printf("%d\n",x);
	}
	return 0;
}