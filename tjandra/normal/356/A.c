#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
typedef struct S
{
	u w;
	char c;
	struct S *lc,*rc;
}v;
u q[300000][3];
void upd(u x,u y,u z,v *a,u Ix,u Iy)
{
	if(x==Ix&&y==Iy)
	{
		a->c=0;
		a->w=z;
		return;
	}
	u mi=(Ix+Iy)>>1;
	if(a->c==0)
	{
		a->c=1;
		if(a->lc==NULL)
		{
			a->lc=(v*)malloc(sizeof(v));
			a->lc->lc=a->lc->rc=NULL;
		}
		if(a->rc==NULL)
		{
			a->rc=(v*)malloc(sizeof(v));
			a->rc->lc=a->rc->rc=NULL;
		}
		a->lc->c=0;a->lc->w=a->w;
		a->rc->c=0;a->rc->w=a->w;
	}
	if(y<=mi)upd(x,y,z,a->lc,Ix,mi);
	else if(x>mi)upd(x,y,z,a->rc,mi+1,Iy);
	else
	{
		upd(x,mi,z,a->lc,Ix,mi);
		upd(mi+1,y,z,a->rc,mi+1,Iy);
	}
	return;
}
void prin(v *a,u Ix,u Iy)
{
	if(a->c)
	{
		u mi=(Ix+Iy)>>1;
		if(a->lc!=NULL)prin(a->lc,Ix,mi);
		if(a->rc!=NULL)prin(a->rc,mi+1,Iy);
		return;
	}
	u n=Iy-Ix+1,r=a->w;
	while(n--)printf("%u ",r);
	return;
}
int main()
{
	u n,m,t=0,x,y,z;
	for(scanf("%u%u",&n,&m),n--;t<m;t++)
	scanf("%u%u%u",&q[t][0],&q[t][1],&q[t][2]);
	v *a;a=(v*)malloc(sizeof(v));
	a->c=a->w=0;a->lc=a->rc=NULL;
	while(t--)
	{
		x=q[t][0]-1;y=q[t][1]-1;z=q[t][2]-1;
		if(z==x)upd(x+1,y,z+1,a,0,n);
		else if(z==y)upd(x,y-1,z+1,a,0,n);
		else{upd(x,z-1,z+1,a,0,n);upd(z+1,y,z+1,a,0,n);}
	}
	prin(a,0,n);
	putchar('\n');
	return 0;
}