#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=6e5+5;
char S[max_n];
int W[max_n];
namespace SegTree
{
	int val[max_n<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	void modify(int p,int l,int r,int k)
	{
		if(l==r)
		{
			val[p]=W[l];
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)
			modify(ls(p),l,mid,k);
		else
			modify(rs(p),mid+1,r,k);
		val[p]=min(val[ls(p)],val[rs(p)]);
	}
	int res;
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res=min(res,val[p]);
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
		res=1<<30;
		query(1,1,n,a,b);
		return res;
	}
}
const int MASK=(1<<30)-1;
int pi[max_n],Link[max_n];
inline void Write(__int128 x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	static char st[35];
	int tp=0;
	while(x)
	{
		st[++tp]=x%10^'0';
		x/=10;
	}
	while(tp>0)
		putchar(st[tp--]);
}
int main()
{
	scanf("%d",&n);
	__int128 sum=0,ans=0;
	map<int,int> cnt;
	for(int i=1;i<=n;++i)
	{
		char c[5];
		int w;
		scanf("%s%d",c,&w);
		S[i]=((c[0]-'a')+ans)%26+'a';
		W[i]=w^(ans&MASK);
		w=W[i];
//		fprintf(stderr,"i=%d S[i]=%c W[i]=%d\n",i,S[i],W[i]);
		SegTree::modify(1,1,n,i);
		int j=pi[i-1];
		while(j>0&&S[j+1]!=S[i])
			j=pi[j];
		pi[i]=i==1?0:j+(S[j+1]==S[i]);
//		fprintf(stderr,"pi[i]=%d\n",pi[i]);
		if(i>1)
		{
			if(S[i]!=S[pi[i-1]+1])
				Link[i-1]=pi[i-1];
			else
				Link[i-1]=Link[pi[i-1]];
		}
		int x=Link[i-1];
		while(x!=0)
		{
			if(S[x+1]!=S[i])
			{
				int v=SegTree::query((i-1)-x+1,i-1);
				sum-=v;
				if(!--cnt[v])
					cnt.erase(v);
				x=pi[x];
			}
			else
				x=Link[x];
		}
		while(!cnt.empty()&&cnt.rbegin()->first>w)
		{
			map<int,int>::reverse_iterator it=cnt.rbegin();
			sum+=(__int128)(w-it->first)*(it->second);
			cnt[w]+=it->second;
			cnt.erase(it->first);
		}
		if(S[i]==S[1])
		{
			sum+=w;
			++cnt[w];
		}
		ans+=sum;
		Write(ans);
		putchar('\n');
	}
	return 0;
}