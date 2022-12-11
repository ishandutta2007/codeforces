#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
int a[max_n],b[max_n];
const int max_q=3e5+5;
int l[max_q],r[max_q];
long long ans[max_q];
const int max_k=3e5+5;
struct Query
{
	int L,R,id;
	inline Query(int l,int r,int k)
	{
		L=l,R=r,id=k;
	}
};
vector<Query> id[max_k];
struct ST
{
	int Log[max_n],val[19][max_n],*v;
	inline int Min(int a,int b)
	{
		return v[a]<v[b]?a:b;
	}
	inline void init(int len)
	{
		Log[0]=-1;
		for(int i=1;i<=len;++i)
		{
			Log[i]=Log[i>>1]+1;
			val[0][i]=i;
		}
		for(int i=1;i<=Log[len];++i)
			for(int j=1;j+(1<<i)-1<=len;++j)
				val[i][j]=Min(val[i-1][j],val[i-1][j+(1<<(i-1))]);
	}
	inline int query(int l,int r)
	{
		assert(l<=r);
		int k=Log[r-l+1];
		return Min(val[k][l],val[k][r-(1<<k)+1]);
	}
}A,B;
int nxt[max_n],st[max_n],tp;
long long dp[max_n];
int main()
{
	int n,q,k;
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	A.v=a,A.init(n);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",l+i,r+i);
		ans[i]=a[l[i]];
		if(l[i]+k<=r[i])
		{
			int R=r[i]-(r[i]-l[i])%k;
			id[l[i]%k].push_back(Query((l[i]+k)/k,R/k,i)); 
		}
	}
	for(int r=0;r<=k-1;++r)
	{
		if(id[r].empty())
			continue;
		int len=(n-r)/k;
		for(int i=1;i<=len;++i)
			b[i]=a[A.query((i-1)*k+r,i*k+r)];
		B.v=b,B.init(len);
		tp=0,st[++tp]=len+1;
		for(int i=len;i>=1;--i)
		{
			while(tp>0&&b[st[tp]]>=b[i])
				--tp;
			nxt[i]=st[tp];
			st[++tp]=i;
		}
		for(int i=len;i>=1;--i)
			dp[i]=dp[nxt[i]]+1ll*(nxt[i]-i)*b[i];
		for(vector<Query>::iterator it=id[r].begin();it!=id[r].end();++it)
		{
			int L=it->L,R=it->R,id=it->id,p=B.query(L,R);
			ans[id]+=(dp[L]-dp[p])+(R-p+1ll)*b[p];
		}
	}
	for(int i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
	return 0;
}