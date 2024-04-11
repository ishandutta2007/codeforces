using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define N 801
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define ll long long
#define mod 10000000
struct BIGN{
	ll a[31];
	int len;
	friend bool operator < (BIGN xx,BIGN yy)
	{
		if(xx.len!=yy.len) return xx.len<yy.len;
		for(int i=xx.len;i>=1;i--)
		{
			if(xx.a[i]!=yy.a[i]) return xx.a[i]<yy.a[i];
		}
		return 0;
	}
	void print()
	{
		cout<<a[len];
		ll cnt[12]={0};
		int tot=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=len-1;i>=1;i--)
		{
			ll hh=a[i];
			memset(cnt,0,sizeof(cnt));
			tot=0;
			while(hh)
			{
				cnt[++tot]=hh%10;
				hh/=10;
			}
			for(int j=7;j>=1;j--) cout<<cnt[j];
		}
	}
};
BIGN operator * (BIGN xx,int y)
{
	int len=xx.len;
	for(int i=1;i<=len;i++)xx.a[i]*=y;
	for(int i=1;i<=len;i++)
	{
		if(xx.a[i]>mod) {
			xx.a[i+1]+=xx.a[i]/mod,xx.a[i]%=mod;
			if(i==len) len++;
		}
	}
	xx.len=len;
	return xx;
}
BIGN operator *(BIGN xx,BIGN yy)
{
	BIGN kk;
	kk.len=xx.len+yy.len-1;
	memset(kk.a,0,sizeof(kk.a));
	int lx=xx.len,ly=yy.len;
	for(int i=1;i<=lx;i++)
	{
		for(int j=1;j<=ly;j++)
		{
			kk.a[i+j-1]+=xx.a[i]*yy.a[j];
		}
	}
	for(int i=1;i<=kk.len;i++)
	{
		if(kk.a[i]>mod)
		{
			kk.a[i+1]+=kk.a[i]/mod;
			kk.a[i]%=mod;
			if(i==kk.len) kk.len++;	
		}
	}
	return kk;
}
ll S[N];
BIGN fire[N][N],dancer[N],tmp[N],who[N];
ll n,m,k;
ll x,y,z,fir[N],ne[N*2],to[N*2],cnt;
vector<ll>son[N];
void add(int x,int y)
{
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;
}
bool cmp(int x,int y)
{
	return S[x]<S[y];
}
void dp(int x,int f)
{
	forw(i,x)
	{
		int V=to[i];
		if(V==f) continue;
		dp(V,x);
		son[x].push_back(V);
	}
	S[x]=1;
	int tot=son[x].size();
	tmp[1].a[1]=1;tmp[1].len=1;
	sort(son[x].begin(),son[x].end(),cmp);
	for(int i=0;i<tot;i++)
	{
		int V=son[x][i];
		for(int j=1;j<=S[x];j++) {
			for(int k=0;k<=S[V];k++) {
				who[j+k]=max(who[j+k],tmp[j]*fire[V][k]);
			}
		}
		S[x]+=S[V];
		for(int j=1;j<=S[x];j++) 
		{
			tmp[j]=who[j]; who[j].len=0;memset(who[j].a,0,sizeof(who[j].a));
		}
	}
	for(int i=1;i<=S[x];i++)
	{
		fire[x][i]=tmp[i];
		fire[x][0]=max(fire[x][0],tmp[i]*i);
	}
}
main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	dp(1,0);
	fire[1][0].print();
}