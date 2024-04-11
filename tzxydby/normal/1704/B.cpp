#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,x,a[N],s,mn,mx;
void sol()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s=0;
	mn=mx=a[1];
	for(int i=2;i<=n;i++)
	{
		int vmn=mn,vmx=mx;
		vmn=min(vmn,a[i]),vmx=max(vmx,a[i]);
		if(vmx-vmn<=x*2)
			mn=vmn,mx=vmx;
		else
		{
			s++;
			mn=mx=a[i];
		}
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