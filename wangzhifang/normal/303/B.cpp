#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
    int n,m,x,y,a,b;
    scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&a,&b);
    int g=gcd(a,b);
	a/=g,b/=g;
    int tmp=min(n/a,m/b),x1=0,x2=tmp*a,y1=0,y2=tmp*b,d=x-x2/2-(x2%2),d2=x+x2/2;
    d2>n&&(d-=(d2-n),d2=n);
    d>=0&&(x1+=d,x2+=d);
    d=y-y2/2-(y2%2),d2=y+y2/2;
    d2>m&&(d-=(d2-m),d2=m);
    d>=0&&(y1+=d,y2+=d);
    printf("%d %d %d %d\n",x1,y1,x2,y2);
    return 0;
}