#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005,m1=998244353,m2=1e9+9;
char s[N],c[N];
int n,z[N],p1[N]={1},p2[N]={1},a[N];
pair<int,int> tr[N<<2];
struct Hash
{
	int h1[N],h2[N];
	char s[N];
	void init()
	{
		h1[0]=h2[0]=s[0]-'a';
		for(int i=1;i<n;i++)
		{
			h1[i]=(h1[i-1]*31+s[i]-'a')%m1;
			h2[i]=(h2[i-1]*255+s[i]-'a')%m2;
			p1[i]=p1[i-1]*31%m1;
			p2[i]=p2[i-1]*255%m2;
		}
	}
	pair<int,int> query(int l,int r)
	{
		return make_pair((h1[r]-(l==0?0:h1[l-1]*p1[r-l+1]%m1)+m1)%m1,(h2[r]-(l==0?0:h2[l-1]*p2[r-l+1]%m2)+m2)%m2);
	}
}h1,h2;
struct node
{
	int x,y,l,p,k;
	node(){}
	node(int _x,int _y,int _l,int _p,int _k):x(_x),y(_y),l(_l),p(_p),k(_k){}
	bool operator<(const node zh)const
	{
		return l+l+k<zh.l+zh.l+zh.k;
	}
}ans;
int check(int i,int m)
{
	return h1.query(i-m,i)==h2.query(n-(i+m)-1,n-i-1);
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=make_pair(a[l-1],l-1);
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
pair<int,int> query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
	else return max(query(k<<1,l,mid,a,mid),query(k<<1|1,mid+1,r,mid+1,b));
}
pair<int,int> xzh(int x,int y)
{
	int l=0,r=(y-x)/2+1;
	while(r-l>1)
	{
		int m=l+r>>1;
		pair<int,int> k=query(1,1,n,(x+m)+1,(y-m)+1);
		if(k.first>=m)
			l=m;
		else
			r=m;
	}
	return query(1,1,n,(x+l)+1,(y-l)+1);
}
signed main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
		c[i]=s[n-i-1];
	c[n]='$';
	for(int i=n+1;i<=2*n;i++)
		c[i]=s[i-n-1];
	int l=0,r=0;
	for(int i=1;i<=2*n;i++)
	{
		if(i>r)
		{
			l=i,r=i;
			while(r<=2*n&&c[r-l]==c[r])
				r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z[k]<r-i+1)
				z[i]=z[k];
			else
			{
				l=i;
				while(r<=2*n&&c[r-l]==c[r])
					r++;
				z[i]=r-l;
				r--; 
			}
		}
	}
	if(z[n+1]==n)
	{
		printf("1\n1 %I64d\n",n-!(n&1));
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		h1.s[i]=s[i];
		h2.s[i]=s[n-i-1];
	}
	h1.init(),h2.init();
	for(int i=0;i<n;i++)
	{
		int l=0,r=min(i,n-i-1)+1;
		while(r-l>1)
		{
			int m=l+r>>1;
			if(check(i,m))
				l=m;
			else
				r=m;
		}
		a[i]=l;
	}
	build(1,1,n);
	for(int i=0;i<n;i++)
	{
		int x=i,l=z[i+n+1],y=n-l;
		if(l==0||x+l>y-1)
			continue;
		pair<int,int> zh=xzh(x+l,y-1);
		int k=zh.first;
		k=min(k,y-x-l);
		k=min(k,min(zh.second-(x+l),y-1-zh.second));
		int p=zh.second-k;
		k=2*k+1;
		node q=node(x,y,l,p,k);
		if(ans<q)
			ans=q;
	}
	int zh=0;
	for(int i=0;i<n;i++)
		if(a[i]>a[zh])
			zh=i;
	if(2*a[zh]+1>ans.l+ans.l+ans.k)
		printf("1\n%I64d %I64d\n",zh-a[zh]+1,2*a[zh]+1);
	else
		printf("3\n%I64d %I64d\n%I64d %I64d\n%I64d %I64d\n",ans.x+1,ans.l,ans.p+1,ans.k,ans.y+1,ans.l);
	return 0;
}