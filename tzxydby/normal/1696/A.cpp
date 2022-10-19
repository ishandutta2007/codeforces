#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,z,a[N],s;
void sol()
{
	scanf("%d%d",&n,&z);
	s=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s=max(s,a[i]|z);
	}
	printf("%d\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}