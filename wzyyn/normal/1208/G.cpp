#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
using namespace std;
int n,k,phi[1000005];
long long ans;
int main(){
	scanf("%d%d",&n,&k);
	if (k==1) return puts("3"),0;
	For(i,1,n) phi[i]=i;
	For(i,2,n) if (phi[i]==i)
		For(j,1,n/i) phi[i*j]-=phi[i*j]/i;
	sort(phi+1,phi+n+1);
	For(i,1,k+2) ans+=phi[i];
	printf("%lld\n",ans);
}