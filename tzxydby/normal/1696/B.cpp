#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],s;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=n+1,r=0;
	for(int i=1;i<=n;i++)
		if(a[i])
			l=min(l,i),r=max(r,i);
	if(!r)
		puts("0");
	else
	{
		for(int i=l;i<=r;i++)
		{
			if(!a[i])
			{
				puts("2");
				return;
			}
		}
		puts("1");
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}