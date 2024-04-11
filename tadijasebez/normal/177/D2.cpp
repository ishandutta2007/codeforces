#include <stdio.h>
const int N=100050;
int BIT[N],mod;
void Set(int i, int f){ for(;i<N;i+=i&-i) BIT[i]=(BIT[i]+f+mod)%mod;}
void Set(int l, int r, int f){ Set(l,f);Set(r+1,-f);}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret=(ret+BIT[i]+mod)%mod;return ret;}
int a[N],b[N];
int main()
{
	int n,m,i,len;
	scanf("%i %i %i",&n,&m,&mod);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Set(i,i,a[i]);
	len=n-m+1;
	for(i=1;i<=m;i++) scanf("%i",&b[i]),Set(i,i+len-1,b[i]);
	for(i=1;i<=n;i++) printf("%i ",Get(i));
	printf("\n");
	return 0;
}