#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[105];
int gcd(int a,int b)
{
	if(a==0)return b;
	return gcd(b%a,a);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int d=a[1];
	for(int i=2;i<=n;i++)
	  d=gcd(d,a[i]);
	for(int i=1;i<=n;i++)
	  a[i]/=d;
	if(a[n]-n&1)printf("Alice\n");
	else printf("Bob\n");
	return 0;
}