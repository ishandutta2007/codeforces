#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
long long a[N],v;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	v=0;
	for(int i=1;i<=n;i++)
	{
		a[i]+=v;
		if(a[i]<0)
		{
			puts("No");
			return;
		}
		if(a[i]==0)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j])
				{
					puts("No");
					return;
				}
			}
			puts("Yes");
			return;
		}
		v=a[i];
	}
	puts(v?"No":"Yes");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}