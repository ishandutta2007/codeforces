#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n;
struct stu
{
	int a,b;
	bool operator < (const stu &tmp) const
	{
		return b-a<tmp.b-tmp.a;
	}
}S[Maxn];
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&S[i].a,&S[i].b);
	sort(S+1,S+1+n);
	for(int i=1;i<=n;i++)
		ans+=S[i].a*(long long)(i-1)+S[i].b*(long long)(n-i);
	printf("%lld",ans);
	return 0;
}