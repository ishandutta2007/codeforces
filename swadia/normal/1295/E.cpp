#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 3210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define LS (pos<<1)
#define RS ((pos<<1)+1)
#define MID (l+r)/2

#define _ 0
using namespace std;

LL tag[MAXN];
LL mi[MAXN];

void pushup(int pos)
{
	mi[pos]=min(mi[LS],mi[RS]);
}

void pushdown(int pos)
{
	tag[LS]+=tag[pos];
	tag[RS]+=tag[pos];
	mi[LS]+=tag[pos];
	mi[RS]+=tag[pos];
	tag[pos]=0;
}

void modify(int pos,int x,int l,int r,int L,int R)
{
	if (r<L || l>R)
		return; 
	if (l>=L && r<=R)
	{
		tag[pos]+=x;
		mi[pos]+=x;
		return;
	}
	pushdown(pos);
	modify(LS,x,l,MID,L,R);
	modify(RS,x,MID+1,r,L,R);
	pushup(pos);
}

int n;
int a[MAXN];
int val[MAXN];
int main()
{
	LL ans=LLINF;
	cin>>n;
	
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&val[a[i]]);
		modify(1,val[a[i]],0,n,a[i],n);
	}
	for (int i=1;i<n;i++)
	{
		modify(1,-val[a[i]],0,n,a[i],n);
		modify(1,val[a[i]],0,n,0,a[i]-1);
		ans=min(ans,mi[1]);
	}
	cout<<ans;
	return ~~(0^_^0);
}