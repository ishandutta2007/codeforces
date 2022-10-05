#include <bits/stdc++.h>
using namespace std;
const int Maxn=105;
string str,tmp;
int n,las[Maxn];
long long k,ans,now,f[Maxn][Maxn];
int main()
{
	scanf("%d%lld",&n,&k); 
	str+='#';
	cin>>tmp;
	str+=tmp;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			if(!las[str[i]-'a'+1])
				f[i][j]=f[i-1][j]+max(f[i-1][j-1],1LL);
			else f[i][j]=f[i-1][j]+f[i-1][j-1]-f[las[str[i]-'a'+1]-1][j-1];
		las[str[i]-'a'+1]=i;
	}
	f[n][0]=1;
	for(int i=n;i>=0;i--)
	{
		if(f[n][i]+now>=k)
		{
			printf("%lld",ans+(k-now)*(n-i));
			return 0;
		}
		now+=f[n][i];
		ans+=f[n][i]*(n-i);
	}
	printf("-1");
	return 0;
}