#include <bits/stdc++.h>
#define mod 31607
using namespace std;
int a[25][25],b[25][25],inv[35000],p[25][2097154],qwq[2100000],P[25];
int main(int argc, char** argv) {
	int n;
	for(int i=0;i<21;i++) qwq[1<<i]=i+1;
	cin >> n;
	inv[1]=1;
	for(int i=2;i<mod;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)
	{
		P[i]=1;
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
	//		a[i][j]=rand()%10000;
			a[i][j]=a[i][j]*inv[10000]%mod;
			P[i]=P[i]*a[i][j]%mod;
		}
	}
	for(int j=1;j<=n;j++)
	{
		p[j][0]=1;
		for(int i=1;i<(1<<n);i++)
			p[j][i]=p[j][i^i&-i]*a[qwq[i&-i]][j]%mod;
	}
	int ans=0;
	for(int s=0;s<(1<<n);s++)
	{
		int now=1,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s&(1<<i-1))
				++cnt,now=now*P[i]%mod;
		}
		for(int j=1;j<=n;j++)
			now=(now-now*p[j][s^(1<<n)-1])%mod;
		if(cnt&1) ans+=now;
		else ans-=now;
		ans%=mod;
	}
	for(int s=0;s<(1<<n);s++)
	{
		int now=1,cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(s&(1<<i-1))
			{
				++cnt,now=now*P[i]%mod;
			}
			else now=now*a[i][i]%mod;
		}
		for(int j=1;j<=n;j++)
		{
			int qwq=s^(1<<n)-1;
			if(qwq&(1<<j-1)) qwq^=(1<<j-1);
			now=(now-now*p[j][qwq])%mod;
		}
		if(cnt&1) ans+=now;
		else ans-=now;
		ans%=mod;
	}
	for(int s=0;s<(1<<n);s++)
	{
		int now=1,cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(s&(1<<i-1))
			{
				++cnt,now=now*P[i]%mod;
			}
			else now=now*a[i][n-i+1]%mod;
		}
		for(int j=1;j<=n;j++)
		{
			int qwq=s^(1<<n)-1;
			if(qwq&(1<<n-j)) qwq^=(1<<n-j);
			now=(now-now*p[j][qwq])%mod;
		}
		if(cnt&1) ans+=now;
		else ans-=now;
		ans%=mod;
	}
	for(int s=0;s<(1<<n);s++)
	{
		int now=1,cnt=2;
		for(int i=1;i<=n;i++)
		{
			if(s&(1<<i-1))
			{
				++cnt,now=now*P[i]%mod;
			}
			else
			{
				if(n-i+1!=i) now=now*a[i][n-i+1]%mod*a[i][i]%mod;
				else now=now*a[i][i]%mod;
			}
		}
		for(int j=1;j<=n;j++)
		{
			int qwq=s^(1<<n)-1;
			if(qwq&(1<<n-j)) qwq^=(1<<n-j);
			if(qwq&(1<<j-1)) qwq^=(1<<j-1);
			now=(now-now*p[j][qwq])%mod;
		}
		if(cnt&1) ans+=now;
		else ans-=now;
		ans%=mod;
	}
	++ans;
	cout << (ans%mod+mod)%mod;
	return 0;
}