#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 200005
char s[N];int n,m,Q,lg[N],len,lim;
int sa[N],rnk[N],has[N],tr[N],ht[N],mn[18][N];
inline bool cmp(int x,int y,int k){return rnk[x]==rnk[y]&&rnk[x+k]==rnk[y+k];}
void get_sa(int n,int m)
{
	int i,cnt;
	for(i=1;i<=n;i++)has[s[i]]++;
	for(i=1,cnt=0;i<=m;i++)if(has[i])tr[i]=++cnt;
	for(i=1;i<=m;i++)has[i]+=has[i-1];
	for(i=1;i<=n;i++)rnk[i]=tr[s[i]],sa[has[s[i]]--]=i;
	for(int k=1;cnt!=n;k<<=1)
	{
		memset(has,0,sizeof(has));
		for(i=1;i<=n;i++)has[rnk[i]]++;
		for(i=1;i<=n;i++)has[i]+=has[i-1];
		for(i=n;i;i--)if(sa[i]>k)tr[sa[i]-k]=has[rnk[sa[i]-k]]--;
		for(i=n-k+1;i<=n;i++)tr[i]=has[rnk[i]]--;
		for(i=1;i<=n;i++)sa[tr[i]]=i;
		for(i=1,cnt=0;i<=n;i++)tr[sa[i]]=cmp(sa[i],sa[i-1],k)?cnt:++cnt;
		memcpy(rnk,tr,sizeof(tr));
	}
	int j;
	for(i=1;i<=n;i++)
	{
		if(rnk[i]==1)continue;
		for(j=max(1,ht[rnk[i-1]]-1);s[i+j-1]==s[sa[rnk[i]-1]+j-1];j++)ht[rnk[i]]=j;
	}
	for(lg[0]=-1,i=1;i<=n;i++)lg[i]=lg[i>>1]+1,mn[0][i]=ht[i];
	for(i=1;i<21;i++)
		for(j=1;j+(1<<i)-1<=n;j++)
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<i-1)]);
}
inline int get_mn(int l,int r){int tmp=lg[r-l+1];return min(mn[tmp][l],mn[tmp][r-(1<<tmp)+1]);}
inline int get_lcp(int x,int y){if(x==y)return len-x+1;x=rnk[x],y=rnk[y];if(x>y)swap(x,y);return get_mn(x+1,y);}
inline int comp(int x,int y,int l){x++,y++;return get_lcp(x,y)>=l?0:(rnk[x]<rnk[y]?-1:1);}
inline bool cmp1(int x,int y)
{
	int flag=x>y,t;if(flag)swap(x,y);
	if(m+x<=y)
	{
		t=comp(n,x,m);
		if(t)return (t<0)^flag;
		t=comp(x,x+m,y-x-m);
		if(t)return (t<0)^flag;
		t=comp(y-m,n,m);
		if(t)return (t<0)^flag;
	}else
	{
		t=comp(n,x,y-x);
		if(t)return (t<0)^flag;
		t=comp(n+y-x,n,x+m-y);
		if(t)return (t<0)^flag;
		t=comp(x,m+n+x-y,y-x);
		if(t)return (t<0)^flag;
	}
	return !flag;
}
struct QaQ
{
	int l,r,k,x,y,idx;
	inline void read(int i){scanf("%d%d%d%d%d",&l,&r,&k,&x,&y);idx=i;}
	inline bool operator < (const QaQ &a) const {return k<a.k;}
}q[N];
int ans[N],minn[18][N],rk[N],ps[N];
inline int get_minn(int l,int r){if(l>r)return 0x3f3f3f3f;int tmp=lg[r-l+1];return min(minn[tmp][l],minn[tmp][r-(1<<tmp)+1]);}
inline void build_minn(int len)
{
	for(int i=1;i<18;i++)
		for(int j=1;j+(1<<i)-1<=len;j++)
			minn[i][j]=min(minn[i-1][j],minn[i-1][j+(1<<i-1)]);
}
void solve_s()
{
	for(int i=1,j=1,t=1;i<=lim;i++,j=t)if(q[j].k==i)
	{
		for(;q[t].k==q[j].k;t++);
		for(int k=0;k<i;k++)
		{
			int tmp=(n+1)/i+(k<=n%i);
			for(int l=1;l<=tmp;l++)minn[0][l]=rk[(l-1)*i+k];
			build_minn(tmp);
			for(int l=j;l<t;l++)
				if(q[l].x<=k&&k<=q[l].y)
					ans[q[l].idx]=min(ans[q[l].idx],get_minn((q[l].l-k+i-1)/i+1,(q[l].r-k+i)/i));
		}
	}
}
void solve_b()
{
	for(int i=1;i<=n+1;i++)minn[0][i]=rk[i-1];build_minn(n+1);
	for(int i=1;i<=Q;i++)if(q[i].k>lim)
		for(int j=0;j*q[i].k<=n;j++)
		{
			// if(q[i].idx==9)printf("%d\n",get_minn(max(j*q[i].k+q[i].x,q[i].l)+1,min(j*q[i].k+q[i].y,q[i].r)+1));
			ans[q[i].idx]=min(ans[q[i].idx],get_minn(max(j*q[i].k+q[i].x,q[i].l)+1,min(j*q[i].k+q[i].y,q[i].r)+1));
		}
}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s%d",s+n+1,&Q);m=strlen(s+n+1);get_sa(n+m,128);
	lim=min(90,int(sqrt(n))+1);
	for(int i=0;i<=n;i++)ps[i]=i;sort(ps,ps+n+1,cmp1);
	for(int i=0;i<=n;i++)rk[ps[i]]=i;
	for(int i=1;i<=Q;i++)q[i].read(i),ans[i]=0x3f3f3f3f;
	sort(q+1,q+Q+1);solve_s();solve_b();
	for(int i=1;i<=Q;i++)printf("%d ",ans[i]<1e9?ps[ans[i]]:-1);puts("");
}