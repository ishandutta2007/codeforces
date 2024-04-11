//CF1007C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
int qu(LL x,LL y){
	cout<<x<<' '<<y<<endl;
	int z;
	cin>>z;
	return z;
}
int main()
{
	LL n,xa,xb,xc,ya,yb,yc,x,y,xx[3],yy[3],zz[3];
	int z,i;
	cin>>n;
	xa=1,xb=n,xc=n,ya=1,yb=n,yc=n;
	while(1){
		//cout<<xa<<xb<<xc<<' '<<ya<<yb<<yc<<endl;
		xx[0]=xa+xb>>1;
		yy[0]=ya+yb>>1;
		xx[1]=xx[0],yy[1]=yb;
		xx[2]=xb,yy[2]=yy[0];
		for(i=0;i<3;i=i+1){
			x=xx[i];
			y=yy[i];
			z=qu(x,y);
			if(z==0)
				return 0;
			if(z==1)
				xa=max(xa,x+1);
			if(z==2)
				ya=max(ya,y+1);
			if(z==3)
				xb=min(xb,x-1),yb=min(yb,y-1);
			zz[i]=z;
		}
		if(zz[1]==3&&zz[2]==3){
			if(zz[0]==1)
				xb=xx[2]-1,yc=yy[1]-1;
			if(zz[0]==2)
				yb=yy[1]-1,xb=xx[2]-1;
		}
		if(xa>xb)
			xb=xc,yc=yb;
		if(ya>yb)
			yb=yc,xc=xb;
		
	}
	return 0;
}