#include <bits/stdc++.h>
#define Maxn 1007
#define modp 1000000007
using namespace std;
int n,m;
int ans=1;
map<string,int> mp;
char s[Maxn][Maxn];
int combination[Maxn][Maxn],bell[Maxn];
void pre()
{
	combination[0][0]=1;
	bell[0]=1,bell[1]=1;
	for (int i=1;i<=m;i++)
	{
		combination[i][0]=1;
		for (int j=1;j<=i;j++)
			combination[i][j]=(combination[i-1][j]+combination[i-1][j-1])%modp;
		for (int j=0;j<=i;j++)
			bell[i+1]=(bell[i+1]+1LL*bell[j]*combination[i][j])%modp;
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	pre();
	mp.clear();
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i<=m;i++)
	{
		string now;
		now.clear();
		for (int j=1;j<=n;j++)
			now+=s[j][i];
		++mp[now];
	}
	for (map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
		ans=(1LL*ans*bell[(*it).second])%modp;
	printf("%d\n",ans);
	return 0;
}