#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

ld d2(ld x) {
    return x*x;
}
//ll area (pt p1, pt p2, pt p3) {
//    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
//}

ld w(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) {
    ld area = abs((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1));
    ld l1 = sqrt(d2(x2-x3)+d2(y2-y3));
    ld l2 = sqrt(d2(x1-x3)+d2(y1-y3));
    ld l3 = sqrt(d2(x2-x1)+d2(y2-y1));
    ld res = min(area/l1, min(area/l2, area/l3));
    return  res/2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi x(n), y(n);
    ld ans = 1e12;
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
    }
    forn(i,0,n) {
        ans = min(ans, w(x[i],y[i],x[(i+1)%n],y[(i+1)%n],x[(i+2)%n],y[(i+2)%n]));
    }
    printf("%.10lf", (double)ans);
    
}