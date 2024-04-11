#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int T,n;
int a[maxn],b[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)scanf("%d",&b[i]);
		for(int i=1;i<=n;++i)a[i]-=b[i];
		bool yes=1;
		for(int i=1;i<=n;++i)if(a[i]>0)yes=0;
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i]!=0&&a[i-1]==0)cnt++;
			if(a[i]!=0&&a[i-1]!=0&&a[i]!=a[i-1])yes=0;
		}
		if(yes&&cnt<=1)puts("YES");
		else puts("NO");
	}
}