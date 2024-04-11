#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,a[N],b[N];
char s[N];
void sol()
{
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	a[n+1]=0;
	m=min(m,n);
	while(m--)
	{
		for(int i=1;i<=n;i++)
			b[i]=(((a[i-1]==1)+(a[i+1]==1))==1||a[i]==1);
		for(int i=1;i<=n;i++)
			a[i]=b[i];
	}
	for(int i=1;i<=n;i++)
		printf("%d",a[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}