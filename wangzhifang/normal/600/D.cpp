#define _USE_MATH_DEFINES
#include <cmath>
#define M_PI 3.14159265358979323846
#include <cstdio>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
typedef long double ld;
typedef cs ld& cld;
il ld f(cld a,cld c,cld b){
    ld th=acos((a*a+b*b-c*c)/a/b/2)*2;
    return a*a*(th-sin(th))/2;
}
int main(){
    ld x1,y1,x2,y2,r1,r2,dis;
    scanf("%Lf%Lf%Lf%Lf%Lf%Lf",&x1,&y1,&r1,&x2,&y2,&r2);
    if(r1>r2)
    	swap(x1,x2),swap(y1,y2),swap(r1,r2);
    dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(r1+r2<=dis)
		printf("0.00000000000000000000");
    else
		if(r1+dis<=r2)
			printf("%.20Lf",r1*r1*M_PI);
	    else
			printf("%.20Lf",f(r1,r2,dis)+f(r2,r1,dis));
    return 0;
}