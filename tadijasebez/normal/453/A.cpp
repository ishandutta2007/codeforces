#include <bits/stdc++.h>
using namespace std;
#define ldb long double
const int N=100050;
ldb p[N];
ldb pow(ldb x, int k)
{
	ldb ans=1;
	for(;k;k>>=1,x=x*x) if(k&1) ans=ans*x;
	return ans;
}
int main()
{
	int n,m,i;ldb ans=0;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) p[i]=pow((ldb)i/n,m);
	for(i=n;i>=1;i--) p[i]-=p[i-1],ans+=p[i]*i;
	cout<<fixed<<setprecision(12)<<ans<<"\n";
	return 0;
}