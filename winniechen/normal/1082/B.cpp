#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int f[100010][2];
char s[100010];
int cnt,n,ans;
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='G')f[i][0]=f[i-1][0]+1,f[i][1]=f[i-1][1]+1,cnt++;
		else f[i][0]=0,f[i][1]=f[i-1][0]+1;
	}
	if(cnt==0)return puts("0"),0;
	for(int i=1;i<=n;i++)ans=max(ans,f[i][0]);
	for(int i=1;i<=n;i++)
		if(f[i][1]!=cnt+1)ans=max(ans,f[i][1]);
		else if(f[i][1]==cnt+1)ans=max(ans,f[i][1]-1);
	printf("%d\n",ans);
}