#include <cstdio>

typedef long long lli;
int m,b;
int main() {
	scanf("%d %d",&m,&b);
	lli py=b;
	lli xsum=0,ysum=0,max=0;
	for(int i=1;i<=b;i++) ysum+=i;
	for(lli x=0;;x++) {
		lli y=-x/m;
		if(x%m!=0) y--;
		y+=b;
		if(y<0) break;
		
		for(;py>y;py--) {
			ysum-=py;
		}
		xsum+=x;
		lli tmp=xsum*(y+1)+ysum*(x+1);
		if(max<tmp) max=tmp;
	}
	printf("%lld\n",max);
	return 0;
}