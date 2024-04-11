#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int t,n,a[N],s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		s=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				s+=(__gcd(a[i],a[j]*2)>1||__gcd(a[i]*2,a[j])>1);
		printf("%d\n",s);
	}
	return 0;
}