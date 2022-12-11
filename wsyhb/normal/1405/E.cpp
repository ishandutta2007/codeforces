#include<bits/stdc++.h>
using namespace std;
int n,q;
const int max_n=3e5+5;
int a[max_n],s[max_n];
const int max_q=3e5+5;
struct query
{
	int l,r,id;
}p[max_q];
inline bool cmp(const query &a,const query &b)
{
	return a.r<b.r;
}
int c[max_n];
inline void modify(int k,int v)
{
	for(int i=k;i<=n;i+=i&(-i)) c[i]+=v;
}
inline int get_val(int k)
{
	int res=0;
	for(int i=k;i>0;i-=i&(-i)) res+=c[i];
	return res;
}
int ans[max_q];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		a[i]=i-a[i];
	}
	for(int i=1;i<=q;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[i].l=x+1,p[i].r=n-y,p[i].id=i;
	}
	sort(p+1,p+q+1,cmp);
	int j=0;
	for(int i=1;i<=q;++i)
	{
		while(j<p[i].r)
		{
			++j;
			if(a[j]<0) continue;
			int L=1,R=j,mid,res=0;
			while(L<=R)
			{
				mid=(L+R)>>1;
				if(get_val(mid)>=a[j]) res=mid,L=mid+1;
				else R=mid-1;
			}
			modify(1,1),modify(res+1,-1);
		}
		ans[p[i].id]=get_val(p[i].l);
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}