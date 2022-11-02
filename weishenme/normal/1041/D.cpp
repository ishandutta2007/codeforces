#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int n,m,x[N],y[N],ans;
signed main()
{
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
	x[n+1]=(1e10)+5;
	int j=1,s=0,v=m;
	for (;j<=n;j++)
	 {
	 	if (v<=x[j+1]-y[j])
	 	 {
	 	 	ans=max(ans,s+v+y[j]-x[j]);
	 	 	break;
		 }
	 	v-=(x[j+1]-y[j]);
	 	s+=x[j+1]-x[j];
	 }
	for (int i=2;i<=n;i++)
	 {
	 	if (j<i)
	 	 {
	 	 	s=0;v=m;
	 	 	j=i;
		 }
	 	else
	 	 {
	 		s-=x[i]-x[i-1];
	 		v+=x[i]-y[i-1];
		 }
		for (;j<=n;j++)
	 	 {
	 		if (v<=x[j+1]-y[j])
	 	 	 {
	 	 		ans=max(ans,s+v+y[j]-x[j]);
	 	 		break;
		 	 }
	 		v-=(x[j+1]-y[j]);
	 		s+=x[j+1]-x[j];
	 	 }
	 }
	printf("%lld",ans); 
}