#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
#define maxn 100005
ll ans=0; 
int n;
char s[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		if(!((s[i]-'0')&1))ans+=1ll*i;
	}
	printf("%I64d\n",ans);
	return 0;
}