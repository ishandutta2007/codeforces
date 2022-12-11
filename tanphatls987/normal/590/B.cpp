#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;
const double eps=1e-9;

int xa,xb,ya,yb,V,ta,wxa,wxb,wya,wyb;
bool check(double mid){
    double dx=xb-xa,dy=yb-ya;
    dx-=min(mid,ta+.0)*wxa+max(.0,mid-ta)*wxb;
    dy-=min(mid,ta+.0)*wya+max(.0,mid-ta)*wyb;
//    printf("%.9f %.9f %.9f\n",mid,sqrt(dx*dx+dy*dy)+eps,mid*V);
    return sqrt(dx*dx+dy*dy)+eps<=mid*V;
}
double solve(){
    double L=0,R=inf;
    FOR(i,1,500){
        double mid=(L+R)/2;
        if (check(mid)) R=mid-eps;
        else L=mid+eps;
    }
    return L;
}
int main(){
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    cin>>V>>ta>>wxa>>wya>>wxb>>wyb;
    printf("%.15f",solve());
}