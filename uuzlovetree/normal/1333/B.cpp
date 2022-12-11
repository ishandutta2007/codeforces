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
		int pl=0,mi=0;
		bool yes=1;
		for(int i=1;i<=n;++i)
		{
			if(a[i]<b[i]&&!pl)yes=0;
			if(a[i]>b[i]&&!mi)yes=0;
			if(a[i]==1)pl=1;
			if(a[i]==-1)mi=1;
		}
		if(yes)puts("YES");
		else puts("NO");
	}
}