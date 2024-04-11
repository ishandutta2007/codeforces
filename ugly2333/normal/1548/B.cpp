//CF1548B
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
const int N = 1<<19;
LL gcd(LL x,LL y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int n;
LL a[N],b[N],f[N][22];
int main()
{
	int T,i,j,x,s;
	LL o;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%lld",a+i);
		for(i=1;i<n;i++)
			b[i]=abs(a[i+1]-a[i]);
		b[n]=1;
		for(i=1;i<=n;i++)
			f[i][0]=b[i];
		for(j=1;j<=18;j++)
			for(i=1;i<=n;i++)
				if(i+(1<<j)<=n)
					f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		s=0;
		for(i=1;i<n;i++){
			if(b[i]==1)
				continue;
			o=b[i];
			x=i+1;
			for(j=18;j>=0;j--)
				if((x+(1<<j)<=n)&&gcd(o,f[x][j])!=1)
					o=gcd(o,f[x][j]),x+=1<<j;
			s=max(s,x-i);
		}
		printf("%d\n",s+1);
	}
	return 0;
}