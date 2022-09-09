#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int N=100050;

int main()
{
	int a,b,c,x,y;
	scanf("%i %i %i %i %i",&a,&b,&c,&x,&y);
	if(a==12) a=0;
	if(x==12) x=0;
	if(y==12) y=0;
	a*=50;
	if(b>0 || c>0) a++;
        b*=10;
        if(c>0) b++;
        c*=10;
	x*=50;
	y*=50;
	bool ok1=true,ok2=true;
	if(x>y)
	{
		int tmp=x;
		x=y;
		y=tmp;
	}
		if(a<y && a>x) ok1=false;
		if(b<y && b>x) ok1=false;
		if(c<y && c>x) ok1=false;
		a=(a-y+600)%600;
		b=(b-y+600)%600;
		c=(c-y+600)%600;
		x=(x-y+600)%600;
		y=(y-y+600)%600;
		if(a>y && a<x) ok2=false;
		if(b>y && b<x) ok2=false;
		if(c>y && c<x) ok2=false;
	if(ok1 || ok2) printf("YES\n");
	else printf("NO\n");
	return 0;
}