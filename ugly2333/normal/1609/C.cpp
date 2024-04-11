//CF1609C
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
const int N = 1111111;
int n,k,a[N],npr[N],f[N],g[N];
LL x,y,s;
int main()
{
	int T,i,j;
	n=1e6;
	for(i=2;i<=n;i++){
		if(!npr[i]){
			for(j=i*2;j<=n;j+=i)
				npr[j]=1;
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		s=0;
		for(i=0;i<n;i++){
			if(i>=k)
				f[i]=f[i-k]+1;
			else
				f[i]=1;
			if(a[i]!=1)
				f[i]=0;
		}
		for(i=n-1;i>=0;i--){
			if(i+k<n)
				g[i]=g[i+k]+1;
			else
				g[i]=1;
			if(a[i]!=1)
				g[i]=0;
		}
		s=0;
		for(i=0;i<n;i++){
			if(i>=k)
				x=f[i-k];
			else
				x=0;
			if(i+k<n)
				y=g[i+k];
			else
				y=0;
			if(a[i]!=1&&!npr[a[i]])
				s+=x*y+x+y;
		}
		printf("%lld\n",s);
	}
	return 0;
}