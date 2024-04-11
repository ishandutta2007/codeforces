#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,l[100005],r[100005],ans;
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%I64d%I64d",&l[i],&r[i]);
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++)
	  ans+=max(l[i],r[i])+1;
	printf("%I64d\n",ans);
	return 0;
}