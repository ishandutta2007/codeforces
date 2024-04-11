#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
int n,m;
const int N=200+5;
int a[N],b[N];
bool check(int x)
{
	for(int i=1;i<=n;i++)
	{
		bool flag=false;
		for(int j=1;j<=m;j++)
			if(((a[i]&b[j])|x)==x)
			{
				flag=true;
				break;
			}
		if(!flag) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=m;i++) scanf("%d",b+i);
	int ans=(1<<9)-1;
	for(int i=8;i>=0;i--)
		if(check(ans^(1<<i))) ans^=1<<i;
	printf("%d",ans);
	return 0;
}