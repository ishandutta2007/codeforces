#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn (1<<23)
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[30];
vi vld[30];
int match[30][30];
bool ok[maxn+5];

int main()
{
	memset(match,-1,sizeof match);
	int n; scanf("%d",&n);
	rep(i,0,n-1) scanf("%d",&a[i]);
	rep(i,0,n-1) rep(j,0,i-1) rep(k,0,j) if(a[i]==a[j]+a[k]) 
	{
		vld[i].pb((1<<j) | (1<<k));
		match[i][j]=k;
		match[i][k]=j;
	}
	int N=1<<n;
	ok[1]=1;
	rep(s,2,N-1)
	{
		int i=31-__builtin_clz(s);
		int f=0;
		for(auto x: vld[i]) if((s&x)==x) f=1;
		int ss=s^(1<<i);
		if(f && ss&(1<<i-1)) ok[s] |= ok[ss];
		rep(j,0,i-1) if(((1<<j)&s)==0)
		{
			if(f || (match[i][j]!=-1 && ((ss>>match[i][j])&1 || match[i][j]==j))) 
			{
				//if(s==17) printf("%d: %d\n",j,ok[ok[ss^(1<<j)]]);
				if((ss^(1<<j))&(1<<i-1)) ok[s] |= ok[ss^(1<<j)];
			}
		}
	}
	int ans=inf;
	per(s,0,N-1) 
	{
		if(s&(1<<n-1))
		{
			if(ok[s]) ans=min(ans,__builtin_popcount(s));
		}
		else break;
	}
	//rep(i,0,N-1) printf("%d: %d\n",i,ok[i]);
	if(ans==inf) puts("-1");
	else printf("%d\n",ans);
	return 0;
}