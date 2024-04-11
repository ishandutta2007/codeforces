#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const ll inf=2e18;
const int N=8;
const int H=1e9;
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
struct Matrix
{
	ll a[1<<N][1<<N];
	Matrix(){ for(int i=0;i<256;i++) for(int j=0;j<256;j++) a[i][j]=inf;}
	void id(){ for(int i=0;i<256;i++) a[i][i]=0;}
	Matrix operator * (Matrix b)
	{
		Matrix c;
		for(int i=0;i<256;i++) for(int j=0;j<256;j++) for(int k=0;k<256;k++) c.a[i][j]=min(c.a[i][j],a[i][k]+b.a[k][j]);
		return c;
	}
} base,mul[30];
int count(int x){ int ret=0;for(int i=0;i<8;i++) ret+=(x>>i)&1;return ret;}
int c[N+5];ll dp[1<<N],tmp[1<<N];
void Build(int k, int x)
{
	int i,j;
	for(i=0;i<1<<k;i++) if(count(i)==x)
	{
		if(i&1)
		{
			int mask=i>>1;
			for(j=0;j<k;j++)
			{
				if(!((mask>>j)&1))
				{
					base.a[i][mask|(1<<j)]=c[j+1];
				}
			}
		}
		else
		{
			base.a[i][i>>1]=0;
		}
	}
	mul[0]=base;
	for(i=1;i<30;i++) mul[i]=mul[i-1]*mul[i-1];
}
map<int,int> w;
void MoveDP(int k, int x, int fir)
{
	int i,j;
	for(i=0;i<1<<k;i++) tmp[i]=inf;
	for(i=0;i<1<<k;i++) if(count(i)==x)
	{
		if(i&1)
		{
			int mask=i>>1;
			for(j=0;j<k;j++)
			{
				if(!((mask>>j)&1))
				{
					tmp[mask|(1<<j)]=min(tmp[mask|(1<<j)],dp[i]+c[j+1]+w[fir+j+1]);
				}
			}
		}
		else
		{
			tmp[i>>1]=min(tmp[i>>1],dp[i]);
		}
	}
	for(i=0;i<1<<k;i++) dp[i]=tmp[i];
}
void MoveMatrix(int k, int x, int len)
{
	for(int l=0;l<30;l++)
	{
		if(!((len>>l)&1)) continue;
		int i,j;
		for(i=0;i<1<<k;i++) tmp[i]=inf;
		for(i=0;i<1<<k;i++)
		{
			for(j=0;j<1<<k;j++)
			{
				tmp[j]=min(tmp[j],dp[i]+mul[l].a[i][j]);
			}
		}
		for(i=0;i<1<<k;i++) dp[i]=tmp[i];
	}
}
vector<pair<int,int> > Qs;
bool Check(int pos)
{
	int j=upper_bound(Qs.begin(),Qs.end(),mp(pos,H))-Qs.begin();
	if(j)
	{
		j--;
		if(Qs[j].second<pos) return 1;
		return 0;
	}
	return 1;
}
int Get(int pos, int n, int x)
{
	int j=upper_bound(Qs.begin(),Qs.end(),mp(pos,H))-Qs.begin();
	if(j<Qs.size()) return Qs[j].first-pos;
	return n-pos-x+1;
}
int main()
{
	int x,k,n,q,i;
	scanf("%i %i %i %i",&x,&k,&n,&q);
	for(i=1;i<=k;i++) scanf("%i",&c[i]);
	int p,val;
	while(q--) scanf("%i %i",&p,&val),w[p]=val,Qs.pb(mp(p-k,p));
	sort(Qs.begin(),Qs.end());
	int cur=1;
	for(i=0;i<1<<N;i++) dp[i]=inf;
	dp[(1<<x)-1]=0;
	Build(k,x);
	for(i=1;i<=n-x;i++)
	{
		if(Check(i))
		{
			int len=Get(i,n,x);
			MoveMatrix(k,x,len);
			i+=len-1;
		}
		else MoveDP(k,x,i);
	}
	printf("%lld\n",dp[(1<<x)-1]);
	return 0;
}