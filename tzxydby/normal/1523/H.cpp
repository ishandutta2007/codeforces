#include<bits/stdc++.h>
using namespace std;
const int N=20005,M=40;
int n,q,a[N],ql[N],qr[N],qk[N],ans[N],g[N][M];
vector<int>dp[16][M],sf;
struct rmq
{
	int n;
	vector<int>a,st[16],lg;
	void build(vector<int>&s)
	{
		a=s;
		n=a.size();
		lg.resize(n+1);
		for(int i=0;i<=15;i++)
			st[i].resize(n);
		lg[1]=0;
		for(int i=2;i<=n;i++)
			lg[i]=lg[i>>1]+1;
		for(int i=0;i<n;i++)
			st[0][i]=a[i];
		for(int j=1;j<=15;j++)
			for(int i=0;i+(1<<j)<=n;i++)
				st[j][i]=max(st[j-1][i],st[j-1][i+(1<<j-1)]);
	}
	int ask(int l,int r)
	{
		int x=lg[r-l+1];
		return max(st[x][l],st[x][r-(1<<x)+1]);
	}
}t[M],z;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<q;i++)
	{
		cin>>ql[i]>>qr[i]>>qk[i];
		ql[i]--,qr[i]--;
	}
	for(int i=0;i<n;i++)
		sf.push_back(min(a[i]+i,n-1));
	z.build(sf);
	for(int k=0;k<=30;k++)
		for(int i=0;i<n;i++)
			dp[0][k].push_back(min(a[i]+i+k,n-1));
	for(int i=1;i<=15;i++)
	{
		for(int k=0;k<=30;k++)
			t[k].build(dp[i-1][k]);
		for(int k=0;k<=30;k++)
		{
			dp[i][k].resize(n);
			for(int j=0;j<n;j++)
			{
				dp[i][k][j]=0;
				for(int kl=0;kl<=k;kl++)
				{
					int kr=k-kl;
					int pl=j,pr=dp[i-1][kl][j];
					int p=t[kr].ask(pl,pr);
					dp[i][k][j]=max(dp[i][k][j],p);
				}
			}
		}
	}
	for(int j=0;j<q;j++)
		for(int k=0;k<=qk[j];k++)
			g[j][k]=ql[j];
	for(int i=15;i>=0;i--)
	{
		for(int k=0;k<=30;k++)
			t[k].build(dp[i][k]);
		for(int j=0;j<q;j++)
		{
			int fl=1;
			for(int kl=0;kl<=qk[j];kl++)
			{
				int kr=qk[j]-kl;
				int pl=ql[j],pr=g[j][kl];
				int p=t[kr].ask(pl,pr);
				if(p>=qr[j])
					fl=0;
			}
			if(fl)
			{
				ans[j]+=(1<<i);
				for(int k=qk[j];k>=0;k--)
				{
					int mp=0;
					for(int kl=0;kl<=k;kl++)
					{
						int kr=k-kl;
						int pl=ql[j],pr=g[j][kl];
						int p=t[kr].ask(pl,pr);
						mp=max(mp,p);
					}
					g[j][k]=mp;
				}
			}
		}
	}
	for(int i=0;i<q;i++)
		cout<<ans[i]+(ql[i]!=qr[i])<<"\n";
	return 0;
}