#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
char s[100005];
ll ans;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	  if(!((s[i]-'0')&1))
	    ans+=i;
	printf("%I64d\n",ans);
	return 0;
}