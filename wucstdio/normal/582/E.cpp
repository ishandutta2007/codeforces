#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
char s[505];
int n,m,st[505],top,match[505],num;
int x[1<<4];
int limit=1<<16,l=16,r[1<<16];
ll f[205][1<<16],tmp[1<<16];
int calc(int s)
{
	int ans=0;
	while(s)
	{
		if(s&1)ans++;
		s>>=1;
	}
	return ans;
}
void FWT_or(ll*A,int type)
{
	for(int mid=1;mid<limit;mid<<=1)
	  for(int R=mid<<1,j=0;j<limit;j+=R)
		for(int k=0;k<mid;k++)
		  if(type==1)A[j+mid+k]+=A[j+k];
		  else A[j+mid+k]-=A[j+k];
	for(int i=0;i<limit;i++)
	{
		A[i]%=MOD;
		if(A[i]<0)A[i]+=MOD;
	}
}
void FWT_and(ll*A,int type)
{
	for(int mid=1;mid<limit;mid<<=1)
	  for(int R=mid<<1,j=0;j<limit;j+=R)
		for(int k=0;k<mid;k++)
		  if(type==1)A[j+k]+=A[j+mid+k];
		  else A[j+k]-=A[j+mid+k];
	for(int i=0;i<limit;i++)
	{
		A[i]%=MOD;
		if(A[i]<0)A[i]+=MOD;
	}
}
ll*calc(int l,int r)
{
	num++;
	int now=num;
	if(l==r)
	{
		for(int k=0;k<4;k++)
		{
			if(s[l]-'A'==k||s[l]=='?')
			{
				int ss=0;
				for(int s=0;s<(1<<4);s++)
				  if((1<<k)&s)ss|=1<<s;
				f[now][ss]=1;
			}
			if(s[l]-'a'==k||s[l]=='?')
			{
				int ss=0;
				for(int s=0;s<(1<<4);s++)
				  if(!((1<<k)&s))ss|=1<<s;
				f[now][ss]=1;
			}
		}
		return f[now];
	}
	ll*fl=calc(l+1,match[l]-1);
	ll*fr=calc(match[r]+1,r-1);
	int m=match[l]+1;
	if(s[m]!='&')
	{
		FWT_or(fl,1);
		FWT_or(fr,1);
		for(int i=0;i<limit;i++)tmp[i]=fl[i]*fr[i]%MOD;
		FWT_or(tmp,-1);
		FWT_or(fl,-1);
		FWT_or(fr,-1);
		for(int i=0;i<limit;i++)f[now][i]+=tmp[i];
	}
	if(s[m]!='|')
	{
		FWT_and(fl,1);
		FWT_and(fr,1);
		for(int i=0;i<limit;i++)tmp[i]=fl[i]*fr[i]%MOD;
		FWT_and(tmp,-1);
		FWT_and(fl,-1);
		FWT_and(fr,-1);
		for(int i=0;i<limit;i++)f[now][i]+=tmp[i];
	}
	return f[now];
}
int main()
{
	for(int i=0;i<(1<<16);i++)
	  r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')st[++top]=i;
		if(s[i]==')')
		{
			match[st[top]]=i;
			match[i]=st[top];
			top--;
		}
	}
	ll*f=calc(1,n);
	ll ans=0;
	memset(x,-1,sizeof(x));
	scanf("%d",&m);
	while(m--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		scanf("%d",&x[a|b<<1|c<<2|d<<3]);
	}
	for(int s=0;s<(1<<16);s++)
	{
		bool flag=1;
		for(int i=0;i<16;i++)
		{
			if(x[i]==1&&!((1<<i)&s))flag=0;
			if(x[i]==0&&((1<<i)&s))flag=0;
		}
		if(flag)ans+=f[s];
	}
	printf("%lld\n",ans%MOD);
	return 0;
}