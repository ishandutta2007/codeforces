#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],b[N];
char s[N];
void sol(int l,int r,int d)
{
	if(d==1)
	{
		b[d]=a[l];
		return;
	}
	if(s[d-1]==s[d])
	{
		b[d]=a[l];
		sol(l+1,r,d-1);
	}
	else
	{
		b[d]=a[r];
		sol(l,r-1,d-1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%s",s+1);
	sort(a+1,a+n+1);
	if(s[n]=='L')
		for(int i=n;i>=1;i-=2)
			a[i]=-a[i];
	else
		for(int i=n-1;i>=1;i-=2)
			a[i]=-a[i];
	sol(1,n,n);
	for(int i=1;i<=n;i++)
	{
		if(b[i]>0)
			printf("%d R\n",b[i]);
		else
			printf("%d L\n",-b[i]);
	}
	return 0;
}