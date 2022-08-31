#include<stdio.h>
#include<math.h>
typedef unsigned u;
typedef double d;
d Dr[111111],Da[111111],Db[111111];
d dist(d X,d Y,d x,d y){return hypot(X-x,Y-y);}
int main()
{
	u i,n,a,b;d t,aa,bb,aaa,bbb,s=0.0,ax,ay,bx,by,rx,ry,x,y;
	scanf("%lf%lf%lf%lf%lf%lf%u",&ax,&ay,&bx,&by,&rx,&ry,&n);
	for(i=-1;++i<n;)
	{
		scanf("%lf%lf",&x,&y);
		Dr[i]=hypot(x-rx,y-ry);
		Da[i]=hypot(x-ax,y-ay);
		Db[i]=hypot(x-bx,y-by);
		s+=Dr[i];
	}
	aa=Da[a=0]-Dr[0];
	bb=Db[b=0]-Dr[0];
	for(i=0;++i<n;)
	{
		if(aa>(t=Da[i]-Dr[i])){aa=t;a=i;}
		if(bb>(t=Db[i]-Dr[i])){bb=t;b=i;}
	}
	aaa=bbb=0.0;
	for(i=-1;++i<n;)
	{
		if(i!=a&&aaa>(t=Db[i]-Dr[i]))aaa=t;
		if(i!=b&&bbb>(t=Da[i]-Dr[i]))bbb=t;
	}
	if((aa+=aaa)>(bb+=bbb))aa=bb;
	printf("%.12lf\n",s*2.0+aa);
	return 0;
}