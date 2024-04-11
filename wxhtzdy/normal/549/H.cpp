#include <bits/stdc++.h>
using namespace std;
#define pb push_back
double a,b,c,d;
bool Can(double x){
    vector<double> z,y;
    z.pb(a-x);
    z.pb(a+x);
    z.pb(d-x);
    z.pb(d+x);
    y.pb(b-x);
    y.pb(b+x);
    y.pb(c-x);
    y.pb(c+x);
    double la=min(z[0]*z[2],min(z[0]*z[3],min(z[1]*z[2],z[1]*z[3])));
    double ra=max(z[0]*z[2],max(z[0]*z[3],max(z[1]*z[2],z[1]*z[3])));
    double lb=min(y[0]*y[2],min(y[0]*y[3],min(y[1]*y[2],y[1]*y[3])));
    double rb=max(y[0]*y[2],max(y[0]*y[3],max(y[1]*y[2],y[1]*y[3])));
    return la<=rb&&ra>=lb;
}
int main(){
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    double bot=0,top=1e9;
    for(int i=0;i<200;i++){
        double mid=(bot+top)/2;
        if(Can(mid))top=mid;
        else bot=mid;
    }
    printf("%.9lf",bot);
}