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
#include <math.h>
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
class kirghof;
const ll INF = 2e18;

vi ans;
vector<kirghof> pool;
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
class kirghof {
public:
    int tp;
    vi a;
    ll sol = -1;
    vpll desc;
    int cnt = 1;
    int to;
    void solve() {
        int k = a.size();
        if(tp == 0) cnt = 1;
        else if(tp == 2) {
            cnt = 0;
            forn(i,0,k) pool[a[i]].solve();
            forn(i,0,k) cnt += pool[a[i]].cnt;
        }
        else if(tp == 1) {
            forn(i,0,k) pool[a[i]].solve();
            int best = 0;
            forn(i,0,k) if(pool[a[i]].cnt < pool[a[best]].cnt) best = i;
            cnt = pool[a[best]].cnt;
            to = best;
        }
    }
    
    void solve1() {
        int k = a.size();
        if(tp == 0) sol = 1;
        else if(tp == 2) {
            vll c;
            forn(i,0,k) {
                pool[a[i]].solve();
                if(pool[a[i]].sol == -1) {
                    sol = -1;
                    return;
                }
                c.pb(pool[a[i]].sol);
//                sol += pool[a[i]].sol;
            }
            ll gg =0 ;
            forn(i,0,k) gg = gcd(gg, c[i]);
            forn(i,0,k) {
                c[i] /= gg;
                ll u = ll(sqrt((double)c[i])) -2;
                int aa = 4;
                while(aa--) {
                    u++;
                    if(u*u == c[i]) break;
                }
                if(u*u != c[i]) {
                    sol = -1;
                    return;
                }
                c[i] = u;
            }
            ll p = 0;
            forn(i,0,k) {
                if(p+c[i] > INF) {
                    sol = -1;
                    return;
                }
                p += c[i];
            }
            sol = 0;
            forn(i,0,k) {
                ll d = gcd(c[i], p);
                desc.pb(mp(p/d, c[i]/d));
                if(INF / p <= pool[a[i]].sol / c[i]) {
                    sol = -1;
                    return;
                }
                sol += pool[a[i]].sol / c[i] * p;
                if(sol > INF) {
                    sol = -1;
                    return;
                }
            }
        }
        else if(tp == 1) {
            forn(i,0,k) pool[a[i]].solve();
            int best = 0;
            forn(i,0,k) {
                if(pool[a[best]].sol == -1) best = i;
                else if(pool[a[i]].sol != -1 && pool[a[i]].sol < pool[a[best]].sol) best = i;
            }
            sol = pool[a[best]].sol;
            to = best;
        }
    }
    
    void print(ll p) {
        if(tp == 0) printf(" %lld", p);
        else if(tp == 2) {
            int k = a.size();
            forn(i,0, k) {
                pool[a[i]].print(p);
//                ll p2 = desc[i].first;
//                ll q2 = desc[i].second;
//                ll d1 = gcd(p,q2);
//                ll d2 = gcd(q,p2);
//                pool[a[i]].print((p/d1)*(p2/d2), (q/d2)*(q2/d1));
            }
        }
        else if(tp == 1) {
            forn(i,0,a.size()) {
                if(i==to) pool[a[i]].print(p);
                else pool[a[i]].printzero();
            }
        }
    }
    
    void printzero() {
        if(tp == 0) printf(" 0");
        else for(auto x : a) pool[x].printzero();
    }
    
};



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    int twas = t;
    char c[1000500];
    while(t--) {
        ll res;
//        scanf("%d %s\n", &res, c);
        string s;
        getline(cin, s);
        int pt = 0;
        while(s[pt] != ' ') pt++;
        res = stoi(s.substr(0, pt));
        s = s.substr(pt+1);
//        string s(c);
//        if(s == "*") {
//            printf("REVOLTING %d\n", res);
//            continue;
//        }
        vi q;
        vpi br;
        int n = s.size();
        forn(i,0,s.size()) {
            if(s[i] == '(') q.pb(i);
            else if(s[i] == ')') {
                br.pb(mp(q.back(), i));
                q.pop_back();
            }
        }
        vi skipto(n);
        int resnum = 0;
        vi knum(n,-1);
        pool.clear();
        ans.clear();
        forn(i,0,n) if(s[i] == '*') {
            pool.pb(kirghof());
            pool[resnum].tp = 0;
            knum[i] = resnum++;
            skipto[i] = i+1;
        }
        for(auto x : br) {
            int l = x.first;
            int r = x.second;
            skipto[l] = r;
            int pt = l+1;
            pool.pb(kirghof());
            while(pt < r) {
                if(knum[pt] != -1) {
                    pool.back().a.pb(knum[pt]);
                    pt = skipto[pt];
                }
                else {
                    if(s[pt] == 'S') pool.back().tp = 1;
                    if(s[pt] == 'P') pool.back().tp = 2;
                    pt++;
                }
            }
            knum[l] = resnum++;
            skipto[l] = r+1;
        }
        pool.back().solve();
//        if(pool.back().sol == -1) {
//            printf("LOSS\n");
//        }
//        else {
//        if(twas == 5) printf("%d ", pool.back().cnt);
            printf("REVOLTING");
//            ll d = gcd(res, pool.back().cnt);
//            F
            pool.back().print(res*pool.back().cnt);
            printf("\n");
//        }
//        cout<<1;
    }
    
}