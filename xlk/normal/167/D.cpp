#include<stdio.h>
#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
long long A,B,C,D,p=1000000009;
ii a[100020];
int n,k,m,x,y;
ii ud(ii a,ii b)
{
	return ii(a.Y+b.Y,1+max(a.X+b.Y,a.Y+b.X));
}
struct N
{
	int l,r,v;
	N*L,*R;
	ii w;
	ii qy()
	{
		if(this==0||y<l||x>r)
			return ii(-1,0);
		if(x<=l&&r<=y)
			return w;
		if(v>y||v<x)
			return max(L->qy(),R->qy()); 
		return ud(L->qy(),R->qy());
	}
}t[100020],*o,_;
N *bd(int x,int y)
{
	if(x>y)
		return &_;
	int p=max_element(a+x,a+y+1)-a;
	t[p].l=a[x].Y,t[p].r=a[y].Y,t[p].v=a[p].Y;
	t[p].L=bd(x,p-1),t[p].R=bd(p+1,y);
	t[p].w=ud(t[p].L->w,t[p].R->w);
	return t+p;
}
int main()
{
	cin>>n>>k,_.w=ii(-1,0);
	for(int i=0;i<k;i++)
		cin>>a[i].X>>a[i].Y;
	cin>>A>>B>>C>>D;
	for(int i=k;i<n;i++)
		a[i].X=(a[i-1].X*A+B)%p,
		a[i].Y=(a[i-1].Y*C+D)%p;
	sort(a,a+n);
	for(int i=0;i<n;i++)
		swap(a[i].X,a[i].Y);
	o=bd(0,n-1);
	cin>>m;
	for(int i=0;i<m;i++)
		scanf("%d%d",&x,&y),printf("%d\n",o->qy().Y);
	return 0;
}