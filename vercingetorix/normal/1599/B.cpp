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

int dd[2][2][2][2];

int emul(int p1, int p2, int d1, int d2, int n) {
    vi p(2), d(2);
    p[0] = p1;
    p[1] = p2;
    d[0] = d1;
    d[1] = d2;
    vi del(n,0);
    int left = n;
    int mv = 0;
    
    if(n>1) while(1) {
        if(p[0]==p[1] && del[p[0]] == 0) {
            del[p[0]] = 1;
            left--;
            if(left==1) break;
        }
        if(p[mv] + d[mv] < 0 || p[mv] + d[mv] >= n) {
            d[mv] = -d[mv];
        }
        else {
            p[mv] += d[mv];
            if(del[p[mv]] == 0) mv=1-mv;
        }
    }
    int pt = 0;
    while(del[pt]) pt++;
    return pt;
    
}



ll sclean(ll p, int d, ll n) {
    if(p == 0) return n-1;
    if(p == n-1) return 0;
    int np2 = n%2;
    int flux = 0;
    if(p*2 >= n) {
        p = n-1-p;
        d = -d;
        flux = 1;
    }
    int e2 = p%2;
    int m2 = (n/2-1-p)%2;
    return (n-1)*(flux^dd[np2][e2][m2][(d+abs(d))/2]);
}
//
ll solve(ll p1, ll p2, int d1, int d2, ll n) {
    if(d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
    if(d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
    if(p1 == p2) {
        if(d1 == d2) {
            if(p1 == 0) return n-1;
            else if(p1 == n-1) return 0;
            else if(d1 == 1) return 0;
            else return n-1;
        }
        else return sclean(p1, d1, n);
    }
    else if(p1 + d1 == p2) {
        p1 += d1;
        swap(p1,p2);
        swap(d1,d2);
        if(d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
        if(d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
        if(d1 == d2) {
            if(p1 == 0) return n-1;
            else if(p1 == n-1) return 0;
            else if(d1 == 1) return 0;
            else return n-1;
        }
        else return sclean(p1, d1, n);
    }
    else {
        if(d1 < d2 && p1 < p2) {
            ll ms = min(p1, n-1-p2);
            p1 -= ms;
            p2 += ms;
            if(d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
            if(d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
        }
        if(d2 < d1 && p2 < p1) {
            ll ms = min(p2, n-1-p1);
            p1 += ms;
            p2 -= ms;
            if(d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
            if(d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
        }
        if(d1 == d2) {
            if(d1 == -1) {
                ll ms = min(p1, p2);
                p1 -= ms;
                p2 -= ms;
                if(d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
                if(d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
            }
            else {
                ll ms = min(n-1-p1, n-1-p2);
                p1 += ms;
                p2 += ms;
                if(d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
                if(d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
            }
        }
        ll stf = abs(p2-p1)/2;
        p1 += stf*d1;
        p2 += stf*d2;
        if(p1!=p2) {
            p1+=d1;
            swap(d1,d2);
        }
        if(d1 + p1 < 0 || d1 + p1 >= n) d1 = -d1;
        if(d2 + p2 < 0 || d2 + p2 >= n) d2 = -d2;
        return sclean(p1, d1, n);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    forn(np2,0,2) {
        forn(e2,0,2) {
            forn(m2, 0, 2) {
                forn(dir,0,2) {
                    int pos = 2+e2;
                    int n = 2*(pos + m2) + np2;
                    int rd = -1;
                    if(dir) rd = 1;
                    dd[np2][e2][m2][dir] = emul(pos, pos, rd, -rd, n);
                    if(dd[np2][e2][m2][dir] > 0) dd[np2][e2][m2][dir] = 1;
                }
            }
        }
    }
//    cout<<solve(1, 0, 1, -1, 3);
//    cout<<emul(1, 0, 1, -1, 3);
//    exit(0);
//    forn(n,1,10) {
//        forn(p1,0,n) forn(p2,0,n) {
//            for(int d1 = -1; d1 <= 1; d1+=2) for(int d2 = -1; d2 <= 1; d2+=2) {
//                cout<<n<<' '<<p1<<' '<<p2<<' '<<d1<<' '<<d2<<' '<<emul(p1,p2,d1,d2,n)<<endl;
//            }
//        }
//    }
//    forn(ir,0,100) {
//        int n = 2+gen()%6;
//        int p1 = gen()%n;
//        int d1=2*(gen()%2)-1;
//        if(sclean(p1, d1, n) != emul(p1, p1, d1, -d1, n)) {
//            cout<<n<<' '<< p1<<' '<<d1;
//            exit(0);
//        }
//    }
//    exit(0);
//    forn(ir,0,100) {
//        int n = 2+gen()%3;
//        int p1 = gen()%n;
//        int p2 = gen()%n;
//        int d1 = 2*(gen()%2)-1;
//        int d2 = 2*(gen()%2)-1;
//        if(solve(p1,p2, d1,d2, n) != emul(p1, p2, d1, d2, n)) {
//            cout<<solve(p1,p2, d1,d2, n)<<' '<<emul(p1, p2, d1, d2, n)<<endl;
//        }
//    }
//    exit(0);
    int ta;
//    read(ta);
    cin>>ta;
    string s;
    while(ta--) {
        ll a,b;
        ll n;
        cin>>n>>a>>b;
        cin>>s;
        int d1 = -1;
        if(s[0] == 'r') d1 =1;
        cin>>s;
        int d2 = -1;
        if(s[0] == 'r') d2 =1;
        printf("%lld\n", solve(a,b,d1,d2,n));
    }
    
    
}