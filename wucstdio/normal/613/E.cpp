#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7,base=233,invb=90128756;
char s[2][2005],t[2005];
int n,m;
ll val[2][2005],v1[2005],v2[2005],f[2005][2005][2],pwb[2005],pwi[2005],ans;
void solve()
{
	for(int i=1;i<=n;i++)
	{
		val[0][i]=(val[0][i-1]*base+s[0][i])%MOD;
		val[1][i]=(val[1][i-1]*base+s[1][i])%MOD;
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		for(int len=2;len<i&&2*len<=m;len++)
		{
			ll v11=(val[0][i-1]-val[0][i-len-1]*pwb[len]%MOD+MOD)%MOD;
			ll v12=(val[1][i-1]-val[1][i-len-1]*pwb[len]%MOD+MOD)%MOD;
			ll v21=(v1[2*len]-v1[len]*pwb[len]%MOD+MOD)%MOD;
			ll v22=(v2[1]-v2[len+1]*pwb[len]%MOD+MOD)%MOD;
			if(v11==v22&&v12==v21)f[i][2*len+1][1]++;
			if(v11==v21&&v12==v22)f[i][2*len+1][0]++;
		}
		for(int j=1;j<=m+1;j++)
		for(int d=0;d<2;d++)
		{
			f[i][1][d]++;
			if(j<=m&&t[j]!=s[d][i])
			{
				f[i][j][d]=0;
				continue;
			}
			f[i][j][d]%=MOD;
			if(j<m)f[i+1][j+1][d]+=f[i][j][d];
			if(j<m-1&&s[d^1][i]==t[j+1])f[i+1][j+2][d^1]+=f[i][j][d];
			if((m-j)%2==1)
			{
				int len=(m-j+1)/2;
				if(i+len-1>n)continue;
				ll val1=(val[d][i+len-1]-val[d][i-1]*pwb[len]%MOD+MOD)%MOD;
				ll val2=(val[d^1][i+len-1]-val[d^1][i-1]*pwb[len]%MOD+MOD)%MOD;
				if(val1==(v1[j+len-1]-v1[j-1]*pwb[len]%MOD+MOD)%MOD&&val2==v2[j+len])ans+=f[i][j][d];
			}
		}
		ans+=f[i][m][0]+f[i][m][1];
	}
}
int main()
{
	scanf("%s%s%s",s[0]+1,s[1]+1,t+1);
	n=(int)strlen(s[0]+1);
	m=(int)strlen(t+1);
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[0][i]==t[1])ans++;
			if(s[1][i]==t[1])ans++;
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=m;i++)
		v1[i]=(v1[i-1]*base+t[i])%MOD;
	for(int i=m;i>=1;i--)
		v2[i]=(v2[i+1]*base+t[i])%MOD;
	pwb[0]=pwi[0]=1;
	for(int i=1;i<=max(n,m);i++)
	{
		pwb[i]=pwb[i-1]*base%MOD;
		pwi[i]=pwi[i-1]*invb%MOD;
	}
	solve();
	for(int i=1;i*2<=n;i++)
	{
		swap(s[0][i],s[0][n-i+1]);
		swap(s[1][i],s[1][n-i+1]);
	}
	solve();
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[0][i]==t[1]&&s[1][i]==t[2])ans--;
			if(s[0][i]==t[2]&&s[1][i]==t[1])ans--;
		}
	}
	printf("%lld\n",ans%MOD);
	return 0;
}