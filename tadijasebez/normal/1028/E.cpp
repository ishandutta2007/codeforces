#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
ll a[N],b[N];
int main()
{
	int n,i,j=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		if(b[j]<b[i]) j=i;
	}
	if(!j){ printf("YES\n");while(n--) printf("1 ");printf("\n");return 0;}
	b[0]=b[n];int k=j;
	for(i=1;i<=n;i++) if(b[i]>b[i-1] && b[i]==b[k]) j=i;
	a[j]=b[j];
	int mul=2;
	for(i=j-1;i>=1;i--) a[i]=b[i]+a[i+1]*mul,mul=1;
	a[n+1]=a[1];
	for(i=n;i>j;i--) a[i]=b[i]+a[i+1]*mul,mul=1;
	bool ok=1;
	for(i=1;i<=n;i++) if(a[i]%a[i+1]!=b[i]) ok=0;
	if(ok)
	{
		printf("YES\n");
		for(i=1;i<=n;i++) printf("%lld ",a[i]);
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}