#include<bits/stdc++.h>
#define int long long
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=1e5+5;
const int M=21;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,k,q;
int a[N];
int v[N],p[N],cnt;
vector<int> V[N];
int c[N];
int nxt[N][M];
void init(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!v[i]) {p[++cnt]=i;
		for (int j=i+i;j<=n;j+=i)v[j]=1;}
	}
	for (int i=1;i<=cnt;i++) for (int j=p[i];j<=n;j+=p[i]) V[j].push_back(i);
}
signed main()
{
	init(100000);
    rd(n);rd(q);for (int i=1;i<=n;i++) rd(a[i]);
	int k=0;
	for (int i=1;i<=n;i++)
	{
		if (i!=1) for (int j:V[a[i-1]]) c[j]--;
		while (k<=n)
		{
			k++;
			if (k==n+1) break;
			for (int j:V[a[k]]) c[j]++;
			bool flag=0;
			for (int j:V[a[k]]) if (c[j]==2) flag=1;
			if (flag){for (int j:V[a[k]]) c[j]--;break;}
		}
		nxt[i][0]=k;k--;
	}
	nxt[n+1][0]=n+1;
	for (int k=1;k<=20;k++)
	{
		nxt[n+1][k]=n+1;
		for (int i=1;i<=n;i++) nxt[i][k]=nxt[nxt[i][k-1]][k-1];
	}
	while (q--)
	{
		int l,r,ans=0;
		rd(l);rd(r);
		int x=l;
		for (int k=20;k>=0;k--)
		{
			if (nxt[x][k]<=r) ans+=(1<<k),x=nxt[x][k];
		}
		cout<<ans+1<<endl;
	}

}