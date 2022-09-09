#include <stdio.h>
int main()
{
	char hc[6];
	int h,m;
	double hh,mm,a,b;
	scanf("%s",&hc);
	h=(hc[0]-'0')*10+(hc[1]-'0');
	h=h%12;
	m=(hc[3]-'0')*10+(hc[4]-'0');
	hh=(double) h;
	mm=(double) m;
	a=2.00*360*(hh/24.00+mm/1440.00);
	b=360.00*(mm/60.00);
	printf("%.12llf %.12llf\n",a,b);
	return 0;
}