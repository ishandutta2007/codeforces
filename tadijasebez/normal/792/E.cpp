#include <stdio.h> 
const int N=100050; 
#define ll long long 
const ll inf=1e15; 
int a[N],b[4]; 
ll min(ll a, ll b){ return a>b?b:a;} 
ll sol=inf; 
int main() {
 	int n,i,j,k;
 	scanf("%d",&n);
 	for(i=1;i<=n;i++) scanf("%d",&a[i]);
 	for(j=1;j*j<=a[1];j++) 	{
 		b[0]=j;
 		b[1]=j+1;
 		b[2]=a[1]/j;
 		b[3]=a[1]/j+1;
 		for(k=0;k<4;k++)
 		{
 			bool ok=1;
 			ll sum=0;
 			for(i=1;i<=n;i++)
 			{
 				ll tmp=(a[i]+b[k]-1)/b[k];
 				ll r=a[i]%b[k];
 				if(r && b[k]-r>tmp) ok=0;
 				sum+=tmp;
 			}
 			if(ok) sol=min(sol,sum);
 		}
 	}
 	if(sol==inf) printf("-1\n");
 	else printf("%lld\n",sol);
 	return 0; 
}