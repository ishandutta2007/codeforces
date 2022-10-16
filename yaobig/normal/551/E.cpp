#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll off[755];
int st[755],ed[755];
pair<ll,int> a[maxn+5];

void add(int bid,int l,int r,int x)
{
	rep(i,st[bid],ed[bid]) a[i].FI+=off[bid];
	off[bid]=0;
	rep(i,st[bid],ed[bid]) if(a[i].SE>=l && a[i].SE<=r) a[i].FI+=x;
	sort(a+st[bid],a+ed[bid]+1);
}

int main()
{
	int n,Q; scanf("%d%d",&n,&Q);
	rep(i,0,n-1) scanf("%lld",&a[i].FI),a[i].SE=i;
	int sq=sqrt(n)+0.5;
	rep(i,0,n-1) ed[i/sq]=i;
	per(i,0,n-1) st[i/sq]=i;
	rep(i,0,(n-1)/sq) sort(a+st[i],a+ed[i]+1);

	while(Q--)
	{
		int op; scanf("%d",&op);
		if(op==1)
		{
			int l,r,x; scanf("%d%d%d",&l,&r,&x); l--; r--;
			if(l/sq==r/sq) add(l/sq,l,r,x);
			else
			{
				add(l/sq,l,ed[l/sq],x);
				rep(i,l/sq+1,r/sq-1) off[i]+=x;
				add(r/sq,st[r/sq],r,x);
			}
		}
		else
		{
			ll y; scanf("%lld",&y);
			int mx=-1,mn=inf;
			rep(i,0,(n-1)/sq) 
			{
				int i1=lower_bound(a+st[i],a+ed[i]+1,mp(y-off[i],-inf))-a;
				int i2=lower_bound(a+st[i],a+ed[i]+1,mp(y-off[i],inf))-a-1;
				if(i1<=ed[i] && a[i1].FI==y-off[i])
				{
					mn=min(mn,a[i1].SE);
					mx=max(mx,a[i2].SE);
				}
			}
			if(mx==-1) puts("-1");
			else printf("%d\n",mx-mn);
		}
	}
	return 0;
}