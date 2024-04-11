//CF 888E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int n,m,a[44];
int b[1<<19],c[1<<19];
int main()
{
	int i,j,nn,x,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		a[i]%=m;
	}
	nn=n/2;
	for(j=0;j<(1<<nn);j=j+1){
		b[j]=0;
		for(i=0;i<nn;i=i+1)
			if(j&(1<<i))
				b[j]=(b[j]+a[i+1])%m;
	}
	for(j=0;j<(1<<(n-nn));j=j+1){
		c[j]=0;
		for(i=0;i<n-nn;i=i+1)
			if(j&(1<<i))
				c[j]=(c[j]+a[i+1+nn])%m;
	}
	x=1<<(n-nn);
	sort(c,c+x);
	ans=0;
	for(j=0;j<(1<<nn);j=j+1){
		i=upper_bound(c,c+x,(m-1-b[j]))-c;
		ans=max((c[i-1]+b[j])%m,ans);
		ans=max((c[x-1]+b[j])%m,ans);
	}
	cout<<ans<<endl;
	return 0;
}
/*
3 9
4 4 1
*/