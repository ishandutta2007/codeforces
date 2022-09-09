#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=1005;
struct Node
{
	int val;
	Node *r,*d;
} a[N][N];
int main()
{
	int n,m,q,i,j,x1,y1,x2,y2,h,w;
	Node *x,*y,*u,*v;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&a[i][j].val);
	for(i=0;i<=n;i++) for(j=0;j<=m;j++) a[i][j].r=&a[i][j+1],a[i][j].d=&a[i+1][j];
	while(q--)
	{
		x=y=&a[0][0];
		scanf("%i %i %i %i %i %i",&x1,&y1,&x2,&y2,&h,&w);
		for(i=1;i<x1;i++) x=x->d;
		for(i=1;i<y1;i++) x=x->r;
		for(i=1;i<x2;i++) y=y->d;
		for(i=1;i<y2;i++) y=y->r;
		u=x;v=y;
		for(i=1;i<=h;i++) u=u->d,v=v->d,swap(u->r,v->r);
		for(i=1;i<=w;i++) x=x->r,y=y->r,swap(x->d,y->d);
		for(i=1;i<=w;i++) u=u->r,v=v->r,swap(u->d,v->d);
		for(i=1;i<=h;i++) x=x->d,y=y->d,swap(x->r,y->r);
	}
	x=&a[0][0];
	for(i=1;i<=n;i++)
	{
		x=x->d;y=x;
		for(j=1;j<=m;j++) y=y->r,printf("%i ",y->val);
		printf("\n");
	}
	return 0;
}