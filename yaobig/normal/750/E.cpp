#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct mat
{
	int a[5][5];
	mat()
	{
		memset(a,63,sizeof a);
		rep(i,0,4) a[i][i]=0;
	}
	mat operator + (const mat &A) const
	{
		mat res; rep(i,0,4) res.a[i][i]=inf;
		rep(i,0,4) rep(k,0,4) rep(j,0,4) res.a[i][j]=min(res.a[i][j],a[i][k]+A.a[k][j]);
		return res;
	}
};

char s[maxn+5];

struct segt
{
	#define ls i*2
	#define rs i*2+1
	mat a[maxn*4+5];
	void pu(int i) {a[i]=a[ls]+a[rs];}
	void build(int i,int l,int r)
	{
		if(l==r)
		{
			if(s[l]=='2') a[i].a[0][0]=1,a[i].a[0][1]=0;
			if(s[l]=='0') a[i].a[1][1]=1,a[i].a[1][2]=0;
			if(s[l]=='1') a[i].a[2][2]=1,a[i].a[2][3]=0;
			if(s[l]=='7') a[i].a[3][3]=1,a[i].a[3][4]=0;
			if(s[l]=='6') a[i].a[3][3]=1,a[i].a[4][4]=1;
		}
		else
		{
			int mid=(l+r)>>1;
			build(ls,l,mid);
			build(rs,mid+1,r);
			pu(i);
		}
	}
	mat ask(int i,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return a[i];
		if(r<ql || qr<l) return mat();
		int mid=(l+r)>>1;
		return ask(ls,l,mid,ql,qr)+ask(rs,mid+1,r,ql,qr);
	}
}t;

int main()
{
	int n,Q; scanf("%d%d",&n,&Q);
	scanf("%s",s+1);
	t.build(1,1,n);
	while(Q--)
	{
		int l,r; scanf("%d%d",&l,&r);
		mat res=t.ask(1,1,n,l,r);
		if(res.a[0][4]==inf) puts("-1");
		else printf("%d\n",res.a[0][4]);
	}
	return 0;
}