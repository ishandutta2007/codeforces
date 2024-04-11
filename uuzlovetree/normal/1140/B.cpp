#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
#define maxn 105
int T,n;
char s[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=n-1;
		for(int i=1;i<=n;++i)if(s[i]=='>')ans=min(ans,i-1);
		for(int i=n;i>=1;--i)if(s[i]=='<')ans=min(ans,n-i);
		printf("%d\n",ans);
	}
	return 0;
}