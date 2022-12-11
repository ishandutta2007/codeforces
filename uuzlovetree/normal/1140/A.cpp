#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
#define maxn 10005
int n;
int a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	int ans=0,last=0;
	for(int i=1;i<=n;++i)
	{
		last=max(a[i],last);
		if(i>=last)ans++;
	}
	printf("%d\n",ans);
	return 0;
}