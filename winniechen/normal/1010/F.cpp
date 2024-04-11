#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
#define mod 998244353
inline int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
#define inv(x) q_pow(x,mod-2)
int n,ans;ll X;
void NTT(int *a,int len,int flag)
{
	int i,j,k,t,w,x,tmp;
	for(i=k=0;i<len;i++)
	{
		if(i>k)swap(a[i],a[k]);
		for(int j=len>>1;(k^=j)<j;j>>=1);
	}
	for(k=2;k<=len;k<<=1)
	{
		x=q_pow(3,(mod-1)/k);if(flag==-1)x=inv(x);t=k>>1;
		for(i=0;i<len;i+=k)
			for(j=i,w=1;j<i+t;j++,w=(ll)w*x%mod)
				tmp=(ll)w*a[j+t]%mod,a[j+t]=(a[j]-tmp)%mod,a[j]=(a[j]+tmp)%mod;
	}if(flag==-1)for(i=0,t=inv(len);i<len;i++)a[i]=(ll)a[i]*t%mod;
}
int A[N<<2],B[N<<2];
struct poly
{
	vector<int >a;int len;
	poly(){a.clear();len=0;}
	poly(int x,int y){poly(),a.push_back(x),len=1;if(y)a.push_back(y),len++;}
	void resize(int x){a.resize(x);for(int i=len;i<x;i++)a[i]=0;len=x;}
	poly operator + (const poly &b) const
	{
		poly c = poly();c.resize(max(len,b.len));
		for(int i=0;i<len;i++)c.a[i]=a[i];
		for(int i=0;i<b.len;i++)(c.a[i]+=b.a[i])%=mod;
		return c;
	}
	poly operator - (const poly &b) const
	{
		poly c = poly();c.resize(max(len,b.len));
		for(int i=0;i<len;i++)c.a[i]=a[i];
		for(int i=0;i<b.len;i++)(c.a[i]-=b.a[i])%=mod;
		return c;
	}
	poly operator * (const poly &b) const
	{
		poly c = poly();c.resize(len+b.len-1);
		if(c.len<=500)
		{
			for(int i=0;i<len;i++)
				for(int j=0;j<b.len;j++)
					c.a[i+j]=(c.a[i+j]+(ll)a[i]*b.a[j])%mod;
			return c;
		}
		int n=1;while(n<c.len)n<<=1;
		for(int i=0;i<len;i++)A[i]=a[i];for(int i=len;i<n;i++)A[i]=0;
		for(int i=0;i<b.len;i++)B[i]=b.a[i];for(int i=b.len;i<n;i++)B[i]=0;
		NTT(A,n,1),NTT(B,n,1);for(int i=0;i<n;i++)A[i]=(ll)A[i]*B[i]%mod;NTT(A,n,-1);
		for(int i=0;i<c.len;i++)c.a[i]=A[i];return c;
	}
};
int head[N],cnt;
struct node{int to,next;}e[N<<1];
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
int siz[N],ch[N][2];
void dfs(int x,int from)
{
	int now=0;siz[x]=1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)ch[x][now++]=to1,dfs(to1,x),siz[x]+=siz[to1];
	}
	if(siz[ch[x][0]]<siz[ch[x][1]])swap(ch[x][0],ch[x][1]);
}
vector<poly>v[N];
pair<poly ,poly > solve(int pos,int l,int r)
{
	if(l==r)return make_pair(v[pos][l]+poly(1,0),v[pos][l]);
	int m=(l+r)>>1;pair<poly ,poly >L=solve(pos,l,m),R=solve(pos,m+1,r);
	return make_pair((L.first - poly(1,0))*R.second+R.first,L.second*R.second);
}
poly solve(int x,int top)
{
	if(ch[x][0])solve(ch[x][0],top);
	if(ch[x][1])v[top].push_back(solve(ch[x][1],ch[x][1])*poly(0,1));
	else v[top].push_back(poly(0,1));
	if(x==top)return solve(top,0,v[top].size()-1).first;
	return poly();
}
int main()
{
	scanf("%d%lld",&n,&X);memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);dfs(1,0);
	poly ret=solve(1,1);X%=mod;int C=1;
	for(int i=1;i<=n&&i<ret.len;i++)
		// printf("%d %d\n",C,ret.a[i]);
		ans=(ans+(ll)C*ret.a[i])%mod,C=(ll)C*inv(i)%mod*(X+i)%mod;
	printf("%d\n",(ans+mod)%mod);
}