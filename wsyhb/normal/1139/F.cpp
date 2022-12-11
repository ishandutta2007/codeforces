#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
const int max_n=1e5+5;
int p[max_n],s[max_n],b[max_n];
const int max_m=1e5+5;
int inc[max_m],pref[max_m],ans[max_m];
const int max_cnt=2e5+5;
struct Triplet
{
	int x,y,z,id;
	inline Triplet(int p=0,int q=0,int r=0,int k=0)
	{
		x=p,y=q,z=r,id=k;
	}
}t[max_cnt],now[max_cnt];
inline bool operator < (const Triplet &a,const Triplet &b)
{
	return a.x!=b.x?a.x<b.x:a.id<b.id;
}
const int max_R=2e5+5;
int Hash[max_R],R;
namespace BIT
{
	int val[max_R];
	inline void modify(int k,int v)
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
void CDQ(int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)>>1;
	CDQ(l,mid),CDQ(mid+1,r);
	int k=l;
	for(int i=l,j=mid+1;i<=mid||j<=r;)
	{
		if(i<=mid&&(j>r||t[i].y<=t[j].y))
		{
			if(!t[i].id)
				BIT::modify(t[i].z,1);
			now[k++]=t[i++];
		}
		else
		{
			if(t[j].id)
				ans[t[j].id]+=BIT::query(t[j].z);
			now[k++]=t[j++];
		}
	}
	for(int i=l;i<=mid;++i)
	{
		if(!t[i].id)
			BIT::modify(t[i].z,-1);
	}
	for(int i=l;i<=r;++i)
		t[i]=now[i];
}
inline void solve()
{
	sort(t+1,t+cnt+1);
	for(int i=1;i<=cnt;++i)
		Hash[i]=t[i].z;
	sort(Hash+1,Hash+cnt+1);
	R=unique(Hash+1,Hash+cnt+1)-Hash-1;
	for(int i=1;i<=cnt;++i)
		t[i].z=lower_bound(Hash+1,Hash+R+1,t[i].z)-Hash;
	CDQ(1,cnt);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",p+i);
	for(int i=1;i<=n;++i)
		scanf("%d",s+i);
	for(int i=1;i<=n;++i)
		scanf("%d",b+i);
	for(int i=1;i<=m;++i)
		scanf("%d",inc+i);
	for(int i=1;i<=m;++i)
		scanf("%d",pref+i);
	cnt=n+m;
	for(int i=1;i<=n;++i)
		t[i]=Triplet(b[i]+p[i],-s[i],-b[i],0);
	for(int i=1;i<=m;++i)
		t[n+i]=Triplet(inc[i]+pref[i],-inc[i],-pref[i],i);
	solve();
	for(int i=1;i<=n;++i)
		t[i]=Triplet(p[i]-b[i],-s[i],b[i]+1,0);
	for(int i=1;i<=m;++i)
		t[n+i]=Triplet(inc[i]-pref[i],-inc[i],pref[i],i);
	solve();
	for(int i=1;i<=m;++i)
		printf("%d%c",ans[i],i<m?' ':'\n');
	return 0;
}