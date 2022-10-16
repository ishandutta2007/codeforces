#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 400000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5],b[maxn+5];
int p[maxn+5],x[maxn+5],id[maxn+5],l[maxn+5],r[maxn+5];
int L[maxn+5],R[maxn+5],cnt[maxn+5];

vi que[maxn+5];

int main()
{
	int n,Q; scanf("%d%d",&n,&Q);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,Q) scanf("%d%d",&p[i],&x[i]);
	rep(i,1,Q) que[p[i]].pb(i);

	memset(b,63,sizeof b);
	b[0]=0;
	rep(i,1,n)
	{
		for(auto id: que[i])
		{
			int ID=lower_bound(b,b+n,x[id])-b;
			l[id]=ID;
		}
		int ID=lower_bound(b,b+n,a[i])-b;
		L[i]=ID;
		b[ID]=a[i];
	}

	memset(b,63,sizeof b);
	b[0]=0;
	per(i,1,n)
	{
		for(auto id: que[i])
		{
			int ID=lower_bound(b,b+n,inf-x[id])-b;
			r[id]=ID;
		}
		int ID=lower_bound(b,b+n,inf-a[i])-b;
		R[i]=ID;
		b[ID]=inf-a[i];
	}
	int M=0;
	rep(i,1,n) M=max(L[i],M);
	rep(i,1,n) if(L[i]+R[i]-1==M) cnt[L[i]]++;
	rep(i,1,Q)
	{
		if(L[p[i]]+R[p[i]]-1==M && cnt[L[p[i]]]==1)
		{
			if(l[i]+r[i]-1==M) printf("%d\n",M);
			else printf("%d\n",M-1);
		}
		else
		{
			if(l[i]+r[i]-1==M+1) printf("%d\n",M+1);
			else printf("%d\n",M);
		}
	}
	return 0;
}