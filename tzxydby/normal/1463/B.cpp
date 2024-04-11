#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long s[2];
		s[0]=s[1]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s[i&1]+=a[i];
		}
		int x=(s[0]>s[1]);
		for(int i=1;i<=n;i++)
			printf("%d ",((i&1)==x)?1:a[i]);
		puts("");
	}
	return 0;
}