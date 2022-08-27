#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
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
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

const double eps = 1e-12;

double go2(double c, double p, double v) {
    double ret  = p*1;
    if(c>eps) {
        double cv = min(c,v);
        ret += c*(1 + go2(c-cv, p+cv, v));
    }
    return ret;
}

double go(double c, double m, double p, double v) {
    double ret = p*1;
    if(c > eps) {
        if (c <= v + eps) ret += c*(1+go2(m+c/2, p+c/2, v));
        else ret += c*(1 + go(c-v, m+v/2, p+v/2, v));
    }
    if(m > eps) {
        if (m <= v + eps) ret += m*(1+go2(c+m/2, p+m/2, v));
        else ret += m*(1 + go(c+v/2, m-v, p+v/2, v));
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        double c,m,p,v;
        scanf("%lf %lf %lf %lf", &c, &m, &p, &v);
//        cout<<c<<m<<p<<v;
        printf("%.12lf\n", go(c,m,p,v));
    }
    
}