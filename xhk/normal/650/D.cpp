#include<bits/stdc++.h>
using namespace std;

int S,s1,ans;

struct tree
{struct unit
 {int ls,rs,s; 
 };
 struct unit t[8000010];
 int tot;
 int root[400010];
 void change(int last,int &p,int l,int r,int x,int y)
 {	p=++tot;
 	t[p]=t[last];
	if(l==r)
	{	t[p].s=max(t[p].s,y);	
		return;
	}
	if(x<=(l+r)/2)
		change(t[last].ls,t[p].ls,l,(l+r)/2,x,y);
	else
		change(t[last].rs,t[p].rs,(l+r)/2+1,r,x,y);
	t[p].s=max(t[t[p].ls].s,t[t[p].rs].s);
 }
 void query(int p,int l,int r,int x,int y)
 {	if(l>y || r<x) return;
 	if(l>=x && r<=y)
 	{	S=max(S,t[p].s);
 		return;	
 	}
 	query(t[p].ls,l,(l+r)/2,x,y);
 	query(t[p].rs,(l+r)/2+1,r,x,y);
 }
};
struct tree t1,t2;

int n,m;
int a[400010],sa[400010],used[400010],f1[400010],f2[400010],c[400010];

void change(int i,int x)
{while(i<=n)
 {	c[i]=max(c[i],x);
 	i+=i&(-i);
 }
}

int query(int i)
{int ret=0;
 while(i>0)
 {	ret=max(ret,c[i]);
 	i-=i&(-i);
 }
 return ret;
}

int main()
{int i,j,s=0,x,y,tx,ty;
 
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
 {	scanf("%d",&a[i]);
 	sa[i]=a[i];
 }
 sort(sa+1,sa+n+1);
 for(i=1;i<=n;i++)
 	a[i]=lower_bound(sa+1,sa+n+1,a[i])-sa;
 for(i=1;i<=n;i++)
 {	f1[i]=query(a[i]-1)+1;
	change(a[i],f1[i]);
 }
 for(i=1;i<=n;i++) c[i]=0;
 for(i=n;i>=1;i--)
 {	f2[i]=query(n+1-a[i]-1)+1;
 	change(n+1-a[i],f2[i]);
 	s1=max(s1,f1[i]+f2[i]-1);
 }
 for(i=1;i<=n;i++)
 	if(f1[i]+f2[i]-1==s1) used[f1[i]]++;
 for(i=1;i<=n;i++)
	t1.change(t1.root[i-1],t1.root[i],1,n,a[i],f1[i]);
 for(i=n;i>=1;i--)
	t2.change(t2.root[i+1],t2.root[i],1,n,a[i],f2[i]);
 for(i=1;i<=m;i++)
 {	scanf("%d%d",&tx,&ty);
 	ans=0;
 	s=1;
 	S=0;
	t1.query(t1.root[tx-1],1,n,1,lower_bound(sa+1,sa+n+1,ty)-sa-1);
	s+=S;
	S=0;
	t2.query(t2.root[tx+1],1,n,lower_bound(sa+1,sa+n+1,ty+1)-sa,n);
	s+=S;
	if(f1[tx]+f2[tx]-1==s1 && used[f1[tx]]==1) ans=s1-1; else ans=s1;
	ans=max(ans,s);
	printf("%d\n",ans);
 }
 return 0;
}