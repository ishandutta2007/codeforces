#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=5e5+5;
char s[max_n];
int sa[max_n],rk[max_n],cnt[max_n],sb[max_n],rk_now[max_n],height[max_n];
inline void SA()
{
	for(int i=0;i<26;++i)
		cnt[i]=0;
	for(int i=1;i<=n;++i)
		++cnt[s[i]-'a'];
	for(int i=1;i<26;++i)
		cnt[i]+=cnt[i-1];
	for(int i=n;i>=1;--i)
		sa[cnt[s[i]-'a']--]=i;
	int tot=0;
	for(int i=1;i<=n;++i)
		rk[sa[i]]=tot+=s[sa[i]]!=s[sa[i-1]];
	rk[n+1]=0;
	for(int k=1;tot<n;k<<=1)
	{
		for(int i=n-k+1;i<=n;++i)
			sb[i-(n-k)]=i;
		for(int i=1,j=k;i<=n;++i)
		{
			if(sa[i]>k)
				sb[++j]=sa[i]-k;
		}
		for(int i=0;i<=tot;++i)
			cnt[i]=0;
		for(int i=1;i<=n;++i)
			++cnt[rk[i]];
		for(int i=1;i<=tot;++i)
			cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;--i)
		{
			int j=sb[i];
			sa[cnt[rk[j]]--]=j;
		}
		tot=0;
		for(int i=1;i<=n;++i)
			rk_now[sa[i]]=tot+=rk[sa[i]]!=rk[sa[i-1]]||rk[sa[i]+k]!=rk[sa[i-1]+k];
		for(int i=1;i<=n;++i)
			rk[i]=rk_now[i];
	}
	for(int i=1,k=0;i<=n;++i)
	{
		k=max(k-1,0);
		int j=sa[rk[i]-1];
		while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k])
			++k;
		height[rk[i]]=k;
	}
}
namespace ST
{
	int f[20][max_n],Log[max_n];
	inline void init()
	{
		Log[0]=-1;
		for(int i=1;i<=n;++i)
		{
			f[0][i]=height[i];
			Log[i]=Log[i>>1]+1;
		}
		for(int i=1;i<=Log[n];++i)
			for(int j=1;j+(1<<i)-1<=n;++j)
				f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	}
	inline int query(int l,int r)
	{
		assert(l<=r);
		int k=Log[r-l+1];
		return min(f[k][l],f[k][r-(1<<k)+1]);
	}
}
int dp[max_n];
namespace SegTree
{
	int val[max_n<<2];
	inline void init()
	{
		for(int i=1;i<=4*n;++i)
			val[i]=-1;
	}
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	void modify(int p,int l,int r,int k,int v)
	{
		val[p]=max(val[p],v);
		if(l<r)
		{
			int mid=(l+r)>>1;
			if(k<=mid)
				modify(ls(p),l,mid,k,v);
			else
				modify(rs(p),mid+1,r,k,v);
		}
	}
	int res;
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res=max(res,val[p]);
			return;
		}
		int mid=(l+r)>>1;
		if(a<=mid)
			query(ls(p),l,mid,a,b);
		if(b>mid)
			query(rs(p),mid+1,r,a,b);
	}
	inline int query(int a,int b)
	{
		res=-1;
		query(1,1,n,a,b);
		return res;
	}
}
int main()
{
	scanf("%d%s",&n,s+1);
	SA();
	ST::init();
	SegTree::init();
	int cur=n+1,ans=0;
	for(int i=n;i>=1;--i)
	{
		int k=dp[i+1]+1;
		while(k>1)
		{
			while(cur-1>=i+k)
			{
				SegTree::modify(1,1,n,rk[cur-1],dp[cur-1]);
				--cur;
			}
			int now,L,R,resL,resR;
			now=resL=resR=rk[i];
			L=now+1,R=n;
			while(L<=R)
			{
				int mid=(L+R)>>1;
				if(ST::query(now+1,mid)>=k-1)
					resR=mid,L=mid+1;
				else
					R=mid-1;
			}
			L=1,R=now-1;
			while(L<=R)
			{
				int mid=(L+R)>>1;
				if(ST::query(mid+1,now)>=k-1)
					resL=mid,R=mid-1;
				else
					L=mid+1;
			}
			if(SegTree::query(resL,resR)>=k-1)
				break;
			now=resL=resR=rk[i+1];
			L=now+1,R=n;
			while(L<=R)
			{
				int mid=(L+R)>>1;
				if(ST::query(now+1,mid)>=k-1)
					resR=mid,L=mid+1;
				else
					R=mid-1;
			}
			L=1,R=now-1;
			while(L<=R)
			{
				int mid=(L+R)>>1;
				if(ST::query(mid+1,now)>=k-1)
					resL=mid,R=mid-1;
				else
					L=mid+1;
			}
			if(SegTree::query(resL,resR)>=k-1)
				break;
			--k;
		}
		dp[i]=k;
		ans=max(ans,k);
	}
	printf("%d\n",ans);
	return 0;
}