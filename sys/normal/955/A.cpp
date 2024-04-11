#include <bits/stdc++.h>
using namespace std;
int tim,hh,mm,h,d,c,n,bef,now;
int main()
{
	scanf("%d%d%d%d%d%d",&hh,&mm,&h,&d,&c,&n);
	tim=60*(19-hh)+(60-mm);
	if(hh>=20) tim=0;
	if(!(h%n)) bef=h/n*c;
	else bef=c*(h/n+1);
	if(!((h+tim*d)%n)) now=(h+tim*d)/n*c;
	else now=c*((h+tim*d)/n+1);
	printf("%.10f",min((double)bef,now*0.8));
	return 0;
}