#include <bits/stdc++.h>
using namespace std;
int a,b,c;
long long ans;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	ans=c*2LL;
	ans+=min(a,b)*2LL;
	int tmp=min(a,b);
	a-=tmp;
	b-=tmp;
	if(a) ans++;
	if(b) ans++;
	printf("%lld",ans);
	return 0;
}