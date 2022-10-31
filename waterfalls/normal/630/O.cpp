#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cd;

int px,py,vx,vy,a,b,c,d;
cd pos[7];

int main() {
	scanf("%d%d%d%d%d%d%d%d",&px,&py,&vx,&vy,&a,&b,&c,&d);
	pos[0] = cd(0     , b);
	pos[1] = cd(-a/2. , 0);
	pos[2] = cd(-c/2. , 0);
	pos[3] = cd(-c/2. , -d);
	pos[4] = cd(c/2.  , -d);
	pos[5] = cd(c/2.  , 0);
	pos[6] = cd(a/2.  , 0);
	for (int i=0;i<7;i++) {
		double ang = atan2(vy,vx)-acos(0.0);
		pos[i]*=cd(cos(ang),sin(ang));
		pos[i]+=cd(px,py);
		printf("%1.12f %1.12f\n",pos[i].real(),pos[i].imag());
	}

	return 0;
}