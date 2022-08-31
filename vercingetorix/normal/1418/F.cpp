#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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
const int N = 200100;
vi mindiv(N+1, 0);
vector<ll> pr;
vi isp(N+1, 0);

vi getdiv(int n) {
    if(n == 1) return vi(1,1);
    int p = mindiv[n];
    int deg = 1;
    n/=p;
    while(n%p == 0) {
        deg++;
        n/=p;
    }
    vi ret = getdiv(n);
    int dp = p;
    int k = ret.size();
    forn(it,0,deg) {
        forn(i,0,k) ret.pb(ret[i]*dp);
        dp*=p;
    }
    return ret;
}

const int B = 420;

pi query(int ql, int qr, int l, int r) {
    
    while(ql <= qr && ql < B) {
        if(r/ql*ql >= l) {
            return mp(ql, r/ql*ql);
        }
        ql++;
    }
    while(qr >= ql) {
        int fall = r/qr;
        if(fall*qr >= l) {
            return mp(qr, fall*qr);
        }
        fall++;
        qr = r/fall;
    }
//    forn(i,ql,qr+1) forn(j,l,r+1) {
//        if(j%i == 0) return mp(i,j);
//    }
    return mp(-1,-1);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    auto x = getdiv(24);
    int n,m;
    ll l, r;
    cin>>n>>m>>l>>r;
//    int qnum = 0;
    forn(x1,1,n+1) {
        if(x1 == n) {
            printf("-1\n");
            continue;
        }
        int ry1 = min(r/x1, ll(m));
        int ly1 = min((l+x1-1)/x1, ll(m+1));
        if(ly1 > ry1) {
            printf("-1\n");
            continue;
        }
        int can = 0;
        for(auto d : getdiv(x1)) {
            int lz1 = x1/d+1;
            int rz1 = n/d;
//            qnum ++;
            auto it = query(lz1, rz1, ly1, ry1);
            if(it.first != -1) {
                printf("%d %d %d %d\n", x1, it.second, it.first*d, x1/d*(it.second/it.first));
                can = 1;
                break;
            }
//            cout<<"query " << lz1<<' '<<rz1<<' '<<ly1<<' '<<ry1<<"\n";
        }
        if(can == 0) printf("-1\n");
//        printf("1\n");
        continue;
        
    }
//    cout<<qnum;
    
    
}