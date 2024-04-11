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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
int x[3], y[3], r[3];

int get2() {
    if(x[0]==x[1]&&y[0]==y[1]&&r[0]==r[1]) {
        return 2;
    }
    int d2 = (x[0]-x[1])*(x[0]-x[1]) +(y[0]-y[1])*(y[0]-y[1]);
    if(d2 <= (r[0]-r[1])*(r[0]-r[1]) || d2 >= (r[0]+r[1])*(r[0]+r[1])) {
        return 3;
    }
    return 4;
//    return 0;
}

int eq(int i, int j) {
    if(x[i]==x[j] && y[i]==y[j] && r[i]==r[j]) return 1;
    return 0;
}

int inter(int i, int j) {
    int d2 = (x[i]-x[j])*(x[i]-x[j]) +(y[i]-y[j])*(y[i]-y[j]);
    if(d2 < (r[i]-r[j])*(r[i]-r[j]) || d2 > (r[i]+r[j])*(r[i]+r[j])) return 0;
    else return 1;
}

struct pt {
    pt(ld x, ld y) : x(x), y(y) {};
    ld x, y;
};

int eq(pt x, pt y) {
    if(abs(x.x-y.x)<=1e-12 && abs(x.y-y.y)<=1e-12) return 1;
    return 0;
}

vector<pt> p[4];

void inter2(int i, int j) {
    ld rx = x[j]-x[i];
    ld ry = y[j]-y[i];
    ld r2 = r[j];
    ld r1 = r[i];
    ld d = sqrt(rx*rx+ry*ry);
    ld xx = (d*d+r1*r1-r2*r2) / (2*d);
    ld vx = rx*xx/d;
    ld vy = ry*xx/d;
    ld xo = sqrt(r1*r1-xx*xx);
    ld px = ry*xo/d;
    ld py = -rx*xo/d;
    for(int s = -1; s<=1; s+=2) {
        pt pon(x[i] + vx + px*s, y[i] + vy + py*s);
        p[i].pb(pon);
        p[j].pb(pon);
        p[3].pb(pon);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin >> n;
    
    forn(i,0,n) {
        cin>>x[i]>>y[i]>>r[i];
    }
    if(n==1) {
        cout<<2;
        return 0;
    }
    else if(n==2 || eq(0,2) || eq(1,2)) {
        cout<<get2();
        return 0;
    }
    forn(i,0,3) {
        int j = (i+1)%3;
        int k = (i+2)%3;
        if(inter(i, j)+inter(i, k) == 0) {
            swap(x[i],x[2]);
            swap(y[i],y[2]);
            swap(r[i],r[2]);
            cout<<get2()+1;
            return 0;
        }
    }
    forn(i,0,3) {
        forn(j,i+1,3) {
            if(inter(i, j)) inter2(i, j);
        }
    }
    forn(i,0,4) {
        int bad = 1;
        while(bad) {
            bad = 0;
            forn(j,0,p[i].size()) {
                forn(k,j+1, p[i].size()) {
                    if(eq(p[i][j], p[i][k])) {
                        swap(p[i][k], p[i].back());
                        p[i].pop_back();
                        bad = 1;
                        break;
                    }
                }
                if(bad) break;
            }
        }
    }
    int ans = 2;
    ans -= p[3].size();
    forn(i,0,3) ans+=p[i].size();
    cout<<ans;
   
}