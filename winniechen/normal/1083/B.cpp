#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 500005
#define ll long long
char s[N],t[N];
ll ans;
int n,k,now,tmp;
int main()
{
	scanf("%d%d%s%s",&n,&k,s+1,t+1);s[n+1]='#';
	if(k==1)return printf("%d\n",n),0;
	for(now=1;s[now]==t[now];now++);
	if(now>n)return printf("%d\n",n),0;ans=now+1;
	for(int i=now+1;i<=n;i++)
	{
		tmp=tmp<<1;
		if(s[i]=='a')tmp++;
		if(t[i]=='b')tmp++;
		tmp=min(k-2,tmp);
		ans+=tmp+2;
	}
	printf("%lld\n",ans);
}//