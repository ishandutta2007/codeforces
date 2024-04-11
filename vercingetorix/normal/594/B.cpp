#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const double pipi =3.1415926535897932384626433832795;
long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,rr,vv;
    string s;
   // ll ans = 0;
    scanf("%d %d %d", &n, &rr, &vv);
    double r=rr;
    double v=vv;
    forn(i,0,n) {
        int s,f;
        scanf("%d %d", &s, &f);
        double d = f-s;
        double ans = 0;
        
        double tl = max(0., d/(2*pipi*r) - 1);
        double tr = d/(2*pipi*r);
        while (tr- tl > max(0.0000000000001*tr ,0.0000000000001)) {
            double t= (tr+tl)/2;
            if (((2*pipi*r)*t + 2*r*abs(sin(pipi*t))) >= d) {
                tr = t;
            }
            else tl = t;
        }
        ans+=(2*pipi*r)*tr/v;
        printf("%.15lf\n", ans);
    }
    
    //cout<<ans;
}