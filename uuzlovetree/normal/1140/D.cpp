#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	ll ans=0;
	for(int i=2;i<n;++i)
	{
		ans+=1ll*i*(i+1);
	}
	printf("%I64d\n",ans);
	return 0;
}