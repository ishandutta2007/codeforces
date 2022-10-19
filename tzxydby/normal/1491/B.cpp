#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],u,v;
void sol()
{
	scanf("%d%d%d",&n,&u,&v);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int fl=1;
	for(int i=1;i<n;i++)
		if(abs(a[i]-a[i+1])>1)
			fl=0;
	if(!fl)
	{
		puts("0");
		return;
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=a[1])
			fl=0;
	if(!fl)
		printf("%d\n",min(u,v));
	else
		printf("%d\n",v+min(u,v));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}