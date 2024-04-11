#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 5100
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

struct range
{
	int l,r;
}p1[MAXN],p2[MAXN];
int cnt1,cnt2;
int n,m;
int f[MAXN];
bool cmp(range r1,range r2)
{
	return r1.l<r2.l || r1.l==r2.l && r1.r<r2.r;
}
int main()
{
	cin>>n>>m;
	int x,y,z;
	RPT(i,0,m)
	{
		cin>>x>>y>>z;
		if (x==1)
		{
			p1[cnt1].l=y;
			p1[cnt1++].r=z;
		}
		else
		{
			p2[cnt2].l=y;
			p2[cnt2++].r=z;
		}
	}
	RPT(i,0,n+1)
	{
		p1[cnt1+i].l=i+1;
		p1[cnt1+i].r=i+1;
	}
	cnt1=cnt1+n;
	sort(p1,p1+cnt1,cmp);
	int ptr1=0,ptr2=0;
	while (ptr2<cnt1)
	{
		if (p1[ptr2].l>p1[ptr1].r)
		{
			ptr1++;
			p1[ptr1]=p1[ptr2];
		}
		else if (p1[ptr2].r>p1[ptr1].r)
		{
			p1[ptr1].r=p1[ptr2].r;
		}
		
		
		ptr2++;
	}
	RPT(i,0,ptr1+1)
	{
		RPT(j,p1[i].l,p1[i].r+1)
			f[j]=p1[i].r;
	}
	RPT(i,0,cnt2)
	{
		if (f[p2[i].l]>=p2[i].r)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	RPT(i,0,ptr1+1)
	{
		RPT(j,p1[i].l,p1[i].r+1)
			cout<<10000-i<<' ';
	}
	//RPT(i,0,ptr1+1)
	//	cout<<p1[i].l<<' '<<p1[i].r<<endl;
	return ~~(0^_^0);
}