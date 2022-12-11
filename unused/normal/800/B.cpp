#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define fst first
#define snd second
const int maxn=1005;
typedef pair<double,double> pdd;
int n;
double res=1e18,x[maxn],y[maxn];
inline double sqr(double a) {
    return a*a;
}
double area(double a,double b,double c,double s) {
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%lf%lf",&x[i],&y[i]);
    for (int i=0;i<n;++i) {
        double a=sqrt(sqr(y[(i+1)%n]-y[i])+sqr(x[(i+1)%n]-x[i]));
        double b=sqrt(sqr(y[(i+2)%n]-y[i])+sqr(x[(i+2)%n]-x[i]));
        double c=sqrt(sqr(y[(i+2)%n]-y[(i+1)%n])+sqr(x[(i+2)%n]-x[(i+1)%n]));
        double s=(a+b+c)/2.0;
        double ar=area(a,b,c,s);
        res=min(res,min(ar/a,min(ar/b,ar/c)));
    }
    printf("%.12lf\n",res);
    return 0;
}