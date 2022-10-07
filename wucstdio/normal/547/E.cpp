#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Query
{
	int p;
	int l,r;
	int type,id;
}a[1000005];
int n,m,tot,ans[500005],s[400005],x[400005],y[400005],c[400005],sa[400005],rnk[400005],height[400005],st[200005],len[200005];
int lg2[500005],minn[21][400005],ll[400005],rr[400005],v[400005];
char _s[200005];
void SA(int n)
{
	int m=300000;
	for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
	for(int i=1;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
	m=0;
	for(int k=1;m<n;k<<=1)
	{
		m=0;
		for(int i=n-k+1;i<=n;i++)y[++m]=i;
		for(int i=1;i<=n;i++)
		  if(sa[i]>k)y[++m]=sa[i]-k;
		for(int i=1;i<=m;i++)c[i]=0;
		for(int i=1;i<=n;i++)c[x[i]]++;
		for(int i=1;i<=m;i++)c[i]+=c[i-1];
		for(int i=n;i>=1;i--)sa[c[x[y[i]]]--]=y[i],y[i]=x[i];
		m=x[sa[1]]=1;
		for(int i=2;i<=n;i++)
		{
			if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])x[sa[i]]=m;
			else x[sa[i]]=++m;
		}
	}
	for(int i=1;i<=n;i++)rnk[sa[i]]=i;
	for(int i=1;i<=n;i++)
	{
		height[rnk[i]]=height[rnk[i-1]]-1;
		if(height[rnk[i]]<0)height[rnk[i]]=0;
		while(s[i+height[rnk[i]]]==s[sa[rnk[i]-1]+height[rnk[i]]])height[rnk[i]]++;
	}
}
int ask(int l,int r)
{
	if(l==r)return tot;
	if(l>r)swap(l,r);
	l++;
	int d=lg2[r-l+1];
	int ans=min(minn[d][l],minn[d][r-(1<<d)+1]);
	return ans;
}
void add(int p)
{
	while(p<=n)
	{
		c[p]++;
		p+=p^(p&(p-1));
	}
}
int sum(int p)
{
	int ans=0;
	while(p)
	{
		ans+=c[p];
		p&=p-1;
	}
	return ans;
}
int sum(int l,int r)
{
	return sum(r)-sum(l-1);
}
bool cmp(Query a,Query b)
{
	return a.p<b.p;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",_s+1);
		len[i]=(int)strlen(_s+1);
		st[i]=tot+1;
		for(int j=1;j<=len[i];j++)s[++tot]=_s[j]-'a'+1,v[tot]=i;
		s[++tot]=i+100;
	}
	SA(tot);
	swap(tot,n);
	for(int i=1;i<=n;i++)minn[0][i]=height[i];
	for(int i=2;i<=n;i++)lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=lg2[n];i++)
	  for(int j=1;j<=n;j++)
	    minn[i][j]=min(minn[i-1][j],minn[i-1][j+(1<<(i-1))]);
	for(int i=1;i<=tot;i++)
	{
		int l=1,r=rnk[st[i]]-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(ask(mid,rnk[st[i]])>=len[i])r=mid-1;
			else l=mid+1;
		}
		ll[i]=l;
		l=rnk[st[i]]+1,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(ask(rnk[st[i]],mid)>=len[i])l=mid+1;
			else r=mid-1;
		}
		rr[i]=r;
	}
//	for(int i=1;i<=n;i++)printf("%d ",s[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++)printf("%d ",v[i]);
//	printf("\n");
//	for(int i=1;i<=tot;i++)
//	{
//		printf("%d:",i);
//		for(int j=ll[i];j<=rr[i];j++)printf("%d ",sa[j]);
//		printf("\n");
//	}
	for(int i=1;i<=m;i++)
	{
		int k,l,r;
		scanf("%d%d%d",&l,&r,&k);
//		printf("%d %d\n",ll[k],rr[k]);
		a[2*i-1].type=-1;
		a[2*i-1].id=i;
		a[2*i-1].l=l;
		a[2*i-1].r=r;
		a[2*i-1].p=ll[k]-1;
		a[2*i].type=1;
		a[2*i].id=i;
		a[2*i].l=l;
		a[2*i].r=r;
		a[2*i].p=rr[k];
	}
	sort(a+1,a+2*m+1,cmp);
//	for(int i=1;i<=2*m;i++)
//	{
//		printf("%d [%d,%d] type=%d,id=%d\n",a[i].p,a[i].l,a[i].r,a[i].type,a[i].id);
//	}
	memset(c,0,sizeof(c));
	swap(tot,n);
	int now=1;
	while(now<=2*m&&a[now].p==0)
	{
		int res=sum(a[now].l,a[now].r);
		ans[a[now].id]+=a[now].type*res;
		now++;
	}
	for(int i=1;i<=tot;i++)
	{
//		printf("%d(%d):\n",i,sa[i]);
		if(v[sa[i]])add(v[sa[i]]);
		while(now<=2*m&&a[now].p==i)
		{
			int res=sum(a[now].l,a[now].r);
			ans[a[now].id]+=a[now].type*res;
			now++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}