#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int a[30][30],mn[10000005],ans[10000005],cnt[10000005],qwq[10000005],si[10000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		for(auto t:s) ++a[i][t-'a'];
	}
	for(int i=1;i<(1<<n);i++)
	{
		ans[i]=1,cnt[i]=cnt[i^i&-i]+1;
		if(cnt[i]&1) ans[i]=-1;
	}
	for(int i=0;i<=25;i++)
	{
		mn[0]=1e9;
		for(int j=1;j<(1<<n);j++)
		{
			for(int k=0;k<n;k++)
			{
				if(j&(1<<k))
				{
					mn[j]=min(mn[j^j&-j],a[k][i]),si[j]=si[j^j&-j]+(k+1);
					break;
				}
			}
			qwq[j]=ans[j]=ans[j]*(mn[j]+1)%mod;
		}
	}
	for(int j=0;j<n;j++)
	for(int i=1;i<(1<<n);i++)
		if(i&(1<<j)) qwq[i]=(qwq[i]+qwq[i^(1<<j)])%mod;
	int ANS=0;
	for(int i=1;i<(1<<n);i++)
	{
		qwq[i]=(qwq[i]%mod+mod)%mod;
		si[i]*=cnt[i];
		qwq[i]=(mod-qwq[i])%mod;
		ANS^=qwq[i]*si[i];
	}
	cout << ANS;
	return 0;
}