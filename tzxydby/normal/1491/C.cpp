#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],b[N];
long long s;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)	
		b[i]=0;
	s=0;
	for(int i=1;i<=n;i++)
	{
		s+=max(a[i]-b[i]-1,0);
		for(int j=i+2;j<=n&&j<=i+a[i];j++)
			b[j]++;
		b[i+1]+=max(b[i]+1-a[i],0);
	}
	printf("%lld\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}