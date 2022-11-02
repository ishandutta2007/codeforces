#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<climits>

#define X first
#define Y second

using namespace std;
typedef long long int lint;
typedef long double ldb;

const lint INF = 1e18;

const int MAXN = 1e6 + 7;

const ldb pi = 3.1415926535897932;

int n;
vector<pair<lint, lint> > pts;
pair<lint, lint> p;

ldb rmin = 1e18;
const ldb eps = 1e-9;

ldb segr(pair<lint, lint> p1, pair<lint, lint> p2){
    lint scal1 = (p.first - p1.X) * (p2.X - p1.X) + (p.Y - p1.Y) * (p2.Y - p1.Y);
    lint scal2 = (p.first - p2.X) * (p1.X - p2.X) + (p.Y - p2.Y) * (p1.Y - p2.Y);
    if(scal1 < 0ll || scal2 < 0ll)
        return INF;
    lint a = p2.Y - p1.Y;
    lint b = p1.X - p2.X;
    lint c = - a * p1.X - b * p1.Y;
    ldb r = a * p.X + b * p.Y + c;
    r *= r;
    r /= a * a + b * b;
    r = fabs(r);
    return r;
}

int main(){
    //ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    pts.resize(n);
    scanf("%lld%lld", &p.first, &p.second);
    lint rmax = 0ll;// rmin = 1e18;
    for(int i = 0; i < n; i++){
        pair<lint, lint> tmp;
        scanf("%lld%lld", &tmp.first, &tmp.second);
        pts[i] = tmp;
        lint r = (p.first - tmp.first) * (p.first - tmp.first) + (p.second - tmp.second) * (p.second - tmp.second);
        rmax = max(r, rmax);
        if(rmin - eps > r)
            rmin = r;
    }
    for(int i = 0; i < n - 1; i++){
        ldb curr = segr(pts[i], pts[i + 1]);
        if(rmin - eps > curr)
            rmin = curr;
    }
    ldb curr = segr(pts[n - 1], pts[0]);
    if(rmin - eps > curr)
            rmin = curr;
    ldb s = pi * rmax - pi * rmin;
    printf("%.12lf", (double)s);
    return 0;

}