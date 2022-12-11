#include<bits/stdc++.h>
#define inf 2000000009
#define ll long long
#define maxn 200005
using namespace std;
int now;
struct point
{
    int d[2],minv[2],maxv[2],l,r;
    int v,sumv,size;
    void clear(){d[0]=d[1]=minv[0]=minv[1]=maxv[0]=maxv[1]=l=r=v=sumv=0;}
};
bool operator ==(point a,point b){return a.d[0]==b.d[0]&&a.d[1]==b.d[1];}
bool operator <(point a,point b)
{
	if(a.d[now]==b.d[now])return a.d[now^1]<b.d[now^1]; 
	return a.d[now]<b.d[now];
}
int rt,cnt;
point t[maxn],a[maxn],p;
bool in(point a,point b)
{
    return a.minv[0]<=b.minv[0]&&b.maxv[0]<=a.maxv[0]&&a.minv[1]<=b.minv[1]&&b.maxv[1]<=a.maxv[1];
}
bool out(point a,point b)
{
    return a.maxv[0]<b.minv[0]||a.minv[0]>b.maxv[0]||a.maxv[1]<b.minv[1]||a.minv[1]>b.maxv[1];
}
void pushup(int x)
{
    int l=t[x].l,r=t[x].r;
    t[x].size=t[l].size+t[r].size+1; 
    t[x].sumv=t[l].sumv+t[r].sumv+t[x].v;
    for(int i=0;i<2;i++)
    {
        t[x].minv[i]=t[x].maxv[i]=t[x].d[i];
        if(l)t[x].minv[i]=min(t[x].minv[i],t[l].minv[i]),t[x].maxv[i]=max(t[x].maxv[i],t[l].maxv[i]);
        if(r)t[x].minv[i]=min(t[x].minv[i],t[r].minv[i]),t[x].maxv[i]=max(t[x].maxv[i],t[r].maxv[i]);
    }
}
point tmp;
void add(int x,int v,bool f)
{
    if(!x)return;
    if(t[x]==p)
	{
		t[x].v+=v;
		pushup(x);
		return;
	}
	now=f;
    if(p<t[x])add(t[x].l,v,f^1);
	else add(t[x].r,v,f^1);
    pushup(x);
}
int query(int x)
{
    int ans=0;
	if(!x)return 0;
    if(in(p,t[x]))
	{
		return t[x].sumv;
	}
    if(out(p,t[x]))return 0;
    tmp.clear();
    tmp.minv[0]=tmp.maxv[0]=t[x].d[0];
    tmp.minv[1]=tmp.maxv[1]=t[x].d[1];
    if(in(p,tmp))ans+=t[x].v;
    ans+=query(t[x].l)+query(t[x].r);
    pushup(x);
    return ans;
}
int rebuild(int l,int r,bool f)
{
    if(l>r)return 0;
    int mid=(l+r)/2;now=f;
    nth_element(a+l,a+mid,a+r+1);
    t[mid]=a[mid];
    t[mid].l=rebuild(l,mid-1,f^1);
    t[mid].r=rebuild(mid+1,r,f^1);
    pushup(mid);
    return mid;
}
int n,m;
struct data
{
	int p,s,b;
	int inc,pref;
}d[maxn*2];
struct data2
{
	int id,tp,x;
}dd[maxn*3];
bool operator < (data2 A,data2 B)
{
	if(A.x==B.x)return A.tp>B.tp;
	return A.x<B.x;
}
bool cmp(point A,point B)
{
	if(A.d[0]==B.d[0])return A.d[1]<B.d[1];
	return A.d[0]<B.d[0];
}
int ans[maxn];
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;++i)scanf("%d",&d[i].p);
   for(int i=1;i<=n;++i)scanf("%d",&d[i].s);
   for(int i=1;i<=n;++i)scanf("%d",&d[i].b);
   for(int i=1;i<=n;++i)
   {
   		a[i].clear();
		a[i].d[0]=d[i].b+d[i].p;
		a[i].d[1]=d[i].b-d[i].p;
   }
   sort(a+1,a+n+1,cmp);
   int D=unique(a+1,a+n+1)-a-1;
   rt=rebuild(1,D,0);
   for(int i=n+1;i<=n+m;++i)scanf("%d",&d[i].inc);
   for(int i=n+1;i<=n+m;++i)scanf("%d",&d[i].pref);
   int CNT=0;
   for(int i=1;i<=m;++i)dd[++CNT].id=i+n,dd[CNT].tp=0,dd[CNT].x=d[i+n].inc;
   for(int i=1;i<=n;++i)
   {
   		dd[++CNT].id=i;dd[CNT].tp=1;dd[CNT].x=d[i].p;
   		dd[++CNT].id=i;dd[CNT].tp=-1;dd[CNT].x=d[i].s;
   }
   sort(dd+1,dd+CNT+1);
   for(int i=1;i<=CNT;++i)
   {
		if(dd[i].tp)
		{
			p.clear();
			int t=dd[i].id;
			p.d[0]=p.minv[0]=p.maxv[0]=d[t].b+d[t].p;
			p.d[1]=p.minv[1]=p.maxv[1]=d[t].b-d[t].p;
			add(rt,dd[i].tp,0);
		}
		else
		{
			p.clear();
			int t=dd[i].id;
			p.maxv[0]=d[t].inc+d[t].pref;
			p.minv[0]=-inf;
			p.maxv[1]=inf;
			p.minv[1]=d[t].pref-d[t].inc;
			ans[t-n]=query(rt);
		}
   }
   for(int i=1;i<=m;++i)printf("%d ",ans[i]);
   return 0;
}