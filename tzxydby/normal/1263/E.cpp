#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
struct tree
{
	int sum,mi,ma;
}tr[N<<1];
tree merge(tree a,tree b)
{
	tree c;
	c.sum=a.sum+b.sum;
	c.mi=min(a.mi,b.mi+a.sum);
	c.ma=max(a.ma,b.ma+a.sum);
	return c;
}
void change(int k,int l,int r,int x,int v)
{
	if(l==r)
	{
		tr[k].sum=tr[k].mi=tr[k].ma=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) change(k<<1,l,mid,x,v);
	else change(k<<1|1,mid+1,r,x,v);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
}
int main()
{
	int n,p=1;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
			change(1,1,n,p,1);
		else if(s[i]==')')
			change(1,1,n,p,-1);
		else if(s[i]=='L')
			p--;
		else if(s[i]=='R')
			p++;
		else
			change(1,1,n,p,0);
		p=max(p,1);
		if(tr[1].sum||tr[1].mi<0)
			printf("%d ",-1);
		else
			printf("%d ",tr[1].ma);
	}
	return 0;
}