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

const long long mod = 998244353;
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

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}
int n;
vi ans;

void end_misery() {
    forn(i,1,n+1) printf("%d ", ans[i]);
    printf("\n");
    exit(0);
}
int cur[6][33];

vi unroll(int m, int l) {
    vi res;
    forn(i,0,l) {
        res.pb(m%2);
        m/=2;
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int k,A,h;
    scanf("%d %d %d", &k, &A, &h);
    vll da;
    ll ia = invmod(A, mod);
    da.pb(1);
    forn(i,0,40) da.pb(da.back() * A % mod);
    n = 1<<k;
    if(k<=4) {
        forn(mask, 0, 1<<(n-1)) {
            int m = mask;
            ans = vi(n+1, 0);
            vi cur;
            forn(i,1,n+1) cur.pb(i);
            forn(it,0,k) {
                vi ncur;
                for(int i = 0; i < cur.size(); i += 2) {
                    if(m%2 == 0) {
                        ncur.pb(cur[i]);
                        ans[cur[i+1]] = cur.size()/2 + 1;
                    }
                    else {
                        ncur.pb(cur[i+1]);
                        ans[cur[i]] = cur.size()/2 + 1;
                    }
                    m/=2;
                }
                cur = ncur;
            }
            ans[cur[0]] = 1;
            ll th = 0;
            forn(i,1,n+1) th += i*da[ans[i]]%mod;
            if(th%mod == h) end_misery();
        }
        printf("-1\n");
        exit(0);
    }
    set<vi> wtf;
    map<vi, int> code;
    
    forn(mask, 0, 1<<(15)) {
        int m = mask;
        ans = vi(n+1, 0);
        vi cur;
        forn(i,1,16+1) cur.pb(i);
        forn(it,0,4) {
            vi ncur;
            for(int i = 0; i < cur.size(); i += 2) {
                if(m%2 == 0) {
                    ncur.pb(cur[i]);
                    ans[cur[i+1]] = cur.size()/2 + 1;
                }
                else {
                    ncur.pb(cur[i+1]);
                    ans[cur[i]] = cur.size()/2 + 1;
                }
                m/=2;
            }
            cur = ncur;
        }
        ans[cur[0]] = 1;
        int s17 = 0;
        int s9 = 0;
        int s5 = 0;
        int s3 = 0;
        forn(i,1,17) {
            if(ans[i] == 2) s3+=i;
            if(ans[i] == 3) s5+=i;
            if(ans[i] == 5) s9+=i;
            if(ans[i] == 9) s17+=i;
        }
        wtf.insert(vi({s3,s5,s9,s17}));
        code[vi({s3,s5,s9,s17})] = mask;
    }
//    cout<<wtf.size();
    int can = 1;
    for(auto x : wtf) for(auto y : wtf) {
        // if(y <= x) continue;
        int a = 136 - x[0] - x[1] - x[2] - x[3];
        int b = 136 - y[0] - y[1] - y[2] - y[3] + 16;
        int s3 = x[0] + y[0] + 16;
        int s5 = x[1] + y[1] + 32;
        int s9 = x[2] + y[2] + 64;
        int s17 = x[3] + y[3] + 128;
//        6 28 36 67 128 263
//        if(s3 == 36 && s5 == 67 && s9 == 128 && s17 == 263) {
//            cout<<"HESLLO\n";
//        }
        ll base = s3*da[3]+s5*da[5]+s9*da[9]+s17*da[17];
        if((base+a*da[1] + b*da[2] )%mod==h) {
            int mask1 = code[x];
            int m = mask1;
            vi cur;
            ll curp = 17;
            forn(i,1,16+1) cur.pb(i);
            forn(it,0,4) {
                vi ncur;
                for(int i = 0; i < cur.size(); i += 2) {
                    if(m%2 == 0) {
                        ncur.pb(cur[i]);
                        ans[cur[i+1]] = curp;
                    }
                    else {
                        ncur.pb(cur[i+1]);
                        ans[cur[i]] = curp;
                    }
                    m/=2;
                }
                curp = (curp+1)/2;
                cur = ncur;
            }
            int mask2 = code[y];
            m = mask2;
            cur.clear();
            curp = 17;
            forn(i,1,16+1) cur.pb(i+16);
            forn(it,0,4) {
                vi ncur;
                for(int i = 0; i < cur.size(); i += 2) {
                    if(m%2 == 0) {
                        ncur.pb(cur[i]);
                        ans[cur[i+1]] = curp;
                    }
                    else {
                        ncur.pb(cur[i+1]);
                        ans[cur[i]] = curp;
                    }
                    m/=2;
                }
                curp = (curp+1)/2;
                cur = ncur;
            }
            ans[a] = 1;
            ans[b] = 2;
            end_misery();
        }
        if((base+b*da[1] + a*da[2] )%mod==h) {
            int mask1 = code[x];
            int m = mask1;
            vi cur;
            ll curp = 17;
            forn(i,1,16+1) cur.pb(i);
            forn(it,0,4) {
                vi ncur;
                for(int i = 0; i < cur.size(); i += 2) {
                    if(m%2 == 0) {
                        ncur.pb(cur[i]);
                        ans[cur[i+1]] = curp;
                    }
                    else {
                        ncur.pb(cur[i+1]);
                        ans[cur[i]] = curp;
                    }
                    m/=2;
                }
                curp = (curp+1)/2;
                cur = ncur;
            }
            int mask2 = code[y];
            m = mask2;
            cur.clear();
            curp = 17;
            forn(i,1,16+1) cur.pb(i+16);
            forn(it,0,4) {
                vi ncur;
                for(int i = 0; i < cur.size(); i += 2) {
                    if(m%2 == 0) {
                        ncur.pb(cur[i]);
                        ans[cur[i+1]] = curp;
                    }
                    else {
                        ncur.pb(cur[i+1]);
                        ans[cur[i]] = curp;
                    }
                    m/=2;
                }
                curp = (curp+1)/2;
                cur = ncur;
            }
            ans[b] = 1;
            ans[a] = 2;
            end_misery();
        }
    }
    cout<<-1;
    exit(0);
    
    int q = 0;
    int sumn = n*(n+1)/2;
    int m;
    for(int i = 1; i <= n; i++) cur[1][i] = i;
    for(int s1 = 1; s1 <= n; s1++) {
        for(int s2 = 1; s2 <= n; s2++) {
            if(s1<=n/2 && s2<=n/2) continue;
            if(s1>n/2 && s2>n/2) continue;
            for(int s3 = n/2 + 2; s3 <= 3*n/2; s3++) {
                for(int s5 = 3*n/2 +4; s5 <= 5*n/2; s5++) {
                    q++;
                    for(int s9 = 7*n/2+8; s9 <= 9*n/2; s9++) {
                        int s17 = sumn - s1-s2-s3-s5-s9;
                        if(s17 < 256 || s17 > 272) continue;
                        if((s1*da[1]+s2*da[2]+s3*da[3]+s5*da[5]+s9*da[9]+s17*da[17])%mod == h) {
                            printf("%d %d %d %d %d %d\n", s1,s2,s3,s5,s9,s17);
                        }
                    }
                }
            }
        }
    }
    cout<<q;
    
    
}