#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=2e6+5;
const int M=1e6+5;
const int SZ=450;
const int mod=998244353;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,m,k,cnt=2;
long long ans;
int a[N],b[N],c[N],la[N],nxt[N],d[N],e[N];
int ansa[N],ansb[N];
void DOIT()
{
	rd(n);rd(k);
	//cout<<"n*k="<<n*k<<endl;
	for (int i=1;i<=n*k;i++) rd(a[i]);
	for (int i=1;i<=n*k;i++)
	{
		nxt[la[a[i]]]=i;
		la[a[i]]=i;
	}
	//for (int i=1;i<=n*k;i++) printf("nxt[%lld]=%lld\n",i,nxt[i]);
	for (int t=1;t<=(n+k-2)/(k-1);t++)
	{
		// t   
		// [l,r] 
		m=0;
		int l=(t-1)*(k-1)+1,r=min(n,t*(k-1));
		//printf("l=%lld,r=%lld\n",l,r);
		for (int i=l;i<=r;i++) d[i]=0;
		for (int i=1;i<=n*k;i++) if (l<=a[i] && a[i]<=r) b[++m]=i;
		//for (int i=1;i<=m;i++) cout<<b[i]<<" ";cout<<endl;
		int now=0;
		for (int i=1;i<=r-l+1;i++)
		{
			int mnn=n*k+1,id;
			for (int j=l;j<=r;j++) d[j]=0;
			for (int j=now+1;j<=m;j++)
			{
				if (!e[a[b[j]]] && !d[a[b[j]]]) 
				{
					d[a[b[j]]]=nxt[b[j]];
					//printf("d[%lld]=%lld\n",a[b[j]],d[a[b[j]]]);
				}
			}
			//for (int j=l;j<=r;j++) cout<<d[j]<<" ";cout<<endl;
			//cout<<"mnn="<<mnn<<endl;
			for (int j=l;j<=r;j++) if (!e[j])if (d[j]<mnn) mnn=d[j],id=j;
			e[id]=1;//cout<<"id="<<id<<endl;
			int pos;
			for (int j=now+1;j<=m;j++) if (a[b[j]]==id) {pos=b[j];break;}
			ansa[id]=pos;ansb[id]=mnn;
			bool flag=0;int TMP=0;
			for (int j=now+1;j<=m;j++) 
			{
				if (a[b[j]]==id && !flag) flag=1; else 
				if (a[b[j]]==id) {TMP=j;break;}
			}
			now=TMP;
			//cout<<"now="<<now<<endl;
		}
	}
	for (int i=1;i<=n;i++) cout<<ansa[i]<<" "<<ansb[i]<<endl;
}
signed main()
{
    //int JYZ;rd(JYZ);while (JYZ--)
	DOIT();
}
/*
*/