#include <bits/stdc++.h>
using namespace std;
#define db double
const db eps=1e-8;
const db inf=1e9;
int main()
{
	int m,a,b,vx,vy,vz;
	db x,y,z;
	scanf("%i %i %i",&a,&b,&m);
	scanf("%i %i %i",&vx,&vy,&vz);
	x=a*0.5;y=m;z=0;
	while(abs(y)>eps)
	{
		db t=inf;
		if(vx>0) t=min(t,((db)a-x)/vx);
		if(vx<0) t=min(t,-x/vx);
		t=min(t,-y/vy);
		if(vz>0) t=min(t,((db)b-z)/vz);
		if(vz<0) t=min(t,-z/vz);
		//cout << "t:" << t << " ";
		x+=t*vx;if(abs(x)<=eps || abs(x-a)<=eps) vx*=-1;
		y+=t*vy;
		z+=t*vz;if(abs(z)<=eps || abs(z-b)<=eps) vz*=-1;
		//cout << x << " " << y << " " << z << "\n";
		//cout << vx << " " << vy << " " << vz << "\n";
	}
	cout << fixed << setprecision(12) << x << " " << z << "\n";
	return 0;
}