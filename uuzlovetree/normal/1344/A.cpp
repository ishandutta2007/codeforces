#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int T,n;
int a[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		for(int i=0;i<n;++i)a[i]=((a[i]+i)%n+n)%n;
		sort(a,a+n);
		bool fl=0;
		for(int i=1;i<n;++i)if(a[i]==a[i-1])fl=1;
		if(fl)puts("NO");
		else puts("YES");
	}
}