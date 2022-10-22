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

#define MAXN 810000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5
#define MID (l+r)/2
#define LS (pos<<1)
#define RS (pos<<1|1)

#define _ 0
using namespace std;

typedef pair<int,int> pii;
struct node
{
	int lpos[2],rpos[2];
} pool[MAXN];

int n,k;
char s[MAXN];

void build(int pos,int l,int r)
{
	if (l==r)
	{
		if (s[l-1]=='1')
		{
			pool[pos].lpos[1]=pool[pos].rpos[1]=l;
			pool[pos].lpos[0]=INF;
			pool[pos].rpos[0]=-INF;
		}
		else
		{
			pool[pos].lpos[0]=pool[pos].rpos[0]=l;
			pool[pos].lpos[1]=INF;
			pool[pos].rpos[1]=-INF;
		}
		return;
	}
	build(LS,l,MID);
	build(RS,MID+1,r);
	pool[pos].lpos[0]=min(pool[LS].lpos[0],pool[RS].lpos[0]);
	pool[pos].lpos[1]=min(pool[LS].lpos[1],pool[RS].lpos[1]);
	pool[pos].rpos[0]=max(pool[LS].rpos[0],pool[RS].rpos[0]);
	pool[pos].rpos[1]=max(pool[LS].rpos[1],pool[RS].rpos[1]);
}

pii query(int pos,int p,int ql,int qr,int l,int r)
{
	if (qr<l || ql>r)
		return {INF,-INF};
	//cout<<ql<<' '<<qr<<' '<<l<<' '<<r<<endl;
	if (qr>=r && ql<=l)
		return {pool[pos].lpos[p],pool[pos].rpos[p]};
	pii p1=query(LS,p,ql,qr,l,MID);
	pii p2=query(RS,p,ql,qr,MID+1,r);
	return {min(p1.first,p2.first),max(p1.second,p2.second)};
}

int main()
{
	cin>>n>>k;
	cin>>s;
	build(1,1,n);
	pii pp;
	pp=query(1,1,1,n,1,n);
	if (pp.second-pp.first<=k-1)
	{
		cout<<"tokitsukaze";
		return 0;
	}
	pp=query(1,0,1,n,1,n);
	if (pp.second-pp.first<=k-1)
	{
		cout<<"tokitsukaze";
		return 0;
	}
	bool f=true;
	pii p1,p2;
	RPT(i,1,n-k+1)
	{
		//WRT(i);
		p1=query(1,1,1,i-1,1,n);
		p2=query(1,1,i+k,n,1,n);
		//cout<<p1.first<<' '<<p1.second<<endl;
		//cout<<p1.first<<' '<<p1.second<<endl;
		if (max(p1.second,p2.second)-min(p1.first,p2.first)>k-1)
		{
			f=false;
			break;
		}
		p1=query(1,0,1,i-1,1,n);
		p2=query(1,0,i+k,n,1,n);
		//cout<<p1.first<<' '<<p1.second<<endl;
		//cout<<p1.first<<' '<<p1.second<<endl;
		if (max(p1.second,p2.second)-min(p1.first,p2.first)>k-1)
		{
			f=false;
			break;
		}
	}
	if (f)
	{
		cout<<"quailty";
		return 0;
	}
	cout<<"once again";
	return 0;
	return ~~(0^_^0);
}