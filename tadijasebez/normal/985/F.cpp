#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
//const ll mod=1589784587945647;
const int mod=998244353;
const int N=200050;
const int M=26*2*N;
ll po[N];
char s[N];
//int ls[M],rs[M],tsz,root[26];
ll hs[N][26];
/*void Build(int &c, int ss, int se, char ch)
{
	c=++tsz;
	if(ss==se)
	{
		if(s[ss]==ch) hs[c]=1;
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid,ch);
	Build(rs[c],mid+1,se,ch);
	hs[c]=hs[ls[c]]+hs[rs[c]]*po[mid-ss+1]%mod;
	if(hs[c]>=mod) hs[c]-=mod;
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return hs[c]*po[ss-qs]%mod;
	int mid=ss+se>>1;
	ll ret=Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
	if(ret>=mod) ret-=mod;
	return ret;
}*/
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int inv(int x){ return pow(x,mod-2);}
void Build(int n, int k, char ch)
{
	int i;
	for(i=1;i<=n;i++)
	{
		hs[i][k]=hs[i-1][k]*2%mod+(s[i]==ch);
		if(hs[i][k]>=mod) hs[i][k]-=mod;
	}
}
int Get(int k, int l, int r)
{
	int ret=hs[r][k]-(ll)hs[l-1][k]*po[r-l+1]%mod;
	if(ret<0) ret+=mod;
	//if(l>1) ret*=inv(po[l-2]);
	return ret;
}
int main()
{
	int i;
	po[0]=1;for(i=1;i<N;i++) po[i]=po[i-1]*2%mod;
	int n,q,x,y,len;
	scanf("%i %i",&n,&q);
	scanf("%s",s+1);
	for(i=0;i<26;i++) Build(n,i,'a'+i);//Build(root[i],1,n,'a'+i);
	vector<int> a,b;
	while(q--)
	{
		scanf("%i %i %i",&x,&y,&len);
		a.clear();b.clear();
		for(i=0;i<26;i++) a.pb(Get(i,x,x+len-1));
		for(i=0;i<26;i++) b.pb(Get(i,y,y+len-1));
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		bool ok=1;
		for(i=0;i<a.size();i++) if(a[i]!=b[i]) ok=0;
		//for(i=0;i<a.size();i++) printf("%lld %lld\n",a[i],b[i]);
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}