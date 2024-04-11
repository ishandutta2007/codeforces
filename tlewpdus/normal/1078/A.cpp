#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c;
ll x1, y1, x2, y2;

double dis(double a, double b, double c, double d) {
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

double td(double x1, double y1, double x2, double y2) {
    return abs(y1+(a*x1+c)/b)+abs(x2+(b*y2+c)/a)+dis(x1,-(a*x1+c)/b,-(b*y2+c)/a,y2);
}

double sd(double x1, double y1, double x2, double y2) {
    return min(abs(y1+(a*x1+c)/b)+abs(y2+(a*x2+c)/b)+dis(x1,-(a*x1+c)/b,x2,-(a*x2+c)/b),
               abs(x1+(b*y1+c)/a)+abs(x2+(b*y2+c)/a)+dis(-(b*y1+c)/a,y1,-(b*y2+c)/a,y2));
}

int main() {
    int i;

    scanf("%lld%lld%lld",&a,&b,&c);
    scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
    if (b==0) {
        swap(x1,y1);
        swap(x2,y2);
        swap(a,b);
    }
    if (a==0) {
        printf("%lld\n",abs(x1-x2)+abs(y1-y2));
        return 0;
    }
    double val = abs(x1-x2)+abs(y1-y2);
    val = min({val,td(x1,y1,x2,y2),td(x2,y2,x1,y1),sd(x1,y1,x2,y2)});
    printf("%.18f\n",val);

    return 0;
}