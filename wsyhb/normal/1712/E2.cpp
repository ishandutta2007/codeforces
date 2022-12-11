#include<bits/stdc++.h>
using namespace std;
const int R=2e5;
const int max_R=2e5+5;
vector<int> Div[max_R],I[max_R];
inline void init()
{
	for(int i=1;i<=R;++i)
		for(int j=i;j<=R;j+=i)
			Div[j].push_back(i);
	for(int k=1;k<=R;++k)
	{
		vector<int> now=Div[k];
		now.pop_back();
		int q=0,b=k;
		while(!(b&1))
			b>>=1,++q;
		for(int a:Div[b])
		{
			if((a<<(q+1))<k)
				now.push_back(a<<(q+1));
			else
				break;
		}
		int sz=now.size();
		int sz_k=(int)Div[k].size()-1;
		for(int x=0;x<sz;++x)
			for(int y=x+1;y<sz;++y)
			{
				int i=now[x],j=now[y];
				if(i>j)
					swap(i,j);
				int lcm=k<<(x>=sz_k||y>=sz_k);
				if(lcm<i+j+k)
					I[i].push_back(k);
			}
	}
}
vector<int> id[max_R];
const int max_t=1e5+5;
int l[max_t],r[max_t],ans[max_t];
namespace BIT
{
	int val[max_R];
	inline void add(int k,int v)
	{
		for(int i=k;i<=R;i+=i&(-i))
			val[i]+=v;
	}
	inline int query(int k)
	{
		int res=0;
		for(int i=k;i>0;i-=i&(-i))
			res+=val[i];
		return res;
	}
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d%d",l+i,r+i);
		id[l[i]].push_back(i);
	}
	for(int l=R;l>=1;--l)
	{
		for(int r:I[l])
			BIT::add(r,1);
		for(int k:id[l])
			ans[k]=BIT::query(r[k]);
	}
	for(int i=1;i<=t;++i)
	{
		int len=r[i]-l[i]+1;
		long long Ans=len*(len-1ll)*(len-2)/6-ans[i];
		printf("%lld\n",Ans);
	}
	return 0;
}