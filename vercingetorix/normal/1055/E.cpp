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

int n,s,m,k;
const int A = 1510;
int d[A][A];
int sd[A][A];
int a[A];
int pref[A];
vi l;
vi r;

void go() {
    forn(i,0,s+1) forn(j,0,s+1) d[i][j] = 0;
    forn(i,0,s+1) forn(j,0,s+1) sd[i][j] = 0;
    int sum = 0;
    forn(i,0,n) {
        sum+=a[i];
        pref[i] = sum;
    }
    for(int ind = s-1; ind >=0; ind--) {
        int rind = lower_bound(all(l), r[ind]+1) - l.begin();
        int on = pref[r[ind]];
        if(l[ind]>0) on -= pref[l[ind]-1];
        forn(tk,0,s) {
            d[ind][tk+1] = max(d[ind][tk+1], sd[rind][tk] + on);
        }
        rind--;
        if(rind > ind) {
            on -= pref[r[ind]];
            on += pref[l[rind]-1];
            forn(tk,0,s) {
                d[ind][tk+1] = max(d[ind][tk+1], sd[rind][tk] + on);
            }
        }
        forn(tk,0,s+1) sd[ind][tk] = max(sd[ind+1][tk], d[ind][tk]);
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d %d", &n, &s, &m, &k);
    readv(af,n);
    vi al(s), ar(s);
    forn(i,0,s) {
        scanf("%d %d", &al[i], &ar[i]);
        al[i]--;
        ar[i]--;
    }
    vi bad(s, 0);
    forn(i,0,s) {
        forn(j,0,s) {
            if(i==j) continue;
            if(al[i]==al[j]&&ar[i]==ar[j]) {
                if(i<j) bad[j] = 1;
            }
            else {
                if(al[i]<=al[j]&&ar[j]<=ar[i]) bad[j] = 1;
            }
        }
    }
    vi pl, pr;
    vpi q;
    forn(i,0,s) if(bad[i] == 0) {
        q.pb(mp(al[i],ar[i]));
//        l.pb(al[i]);
//        r.pb(al[i]);
    }
    srt(q);
    s = q.size();
    forn(i,0,s) {
        l.pb(q[i].first);
        r.pb(q[i].second);
        pl.pb(q[i].first);
        pr.pb(q[i].second);
    }
    m = min(m,s);
    q.clear();
    forn(i,0,n) q.pb(mp(af[i],i));
    srt(q);
    int tl = -1;
    int tr = n;
    while(tr-tl > 1) {
        int md = (tr+tl)/2;
        forn(i,0,n) a[i] = 0;
        forn(i,0,md+1) a[q[i].second] = 1;
        go();
        int can = 0;
        forn(tk,0,m+1) if(sd[0][tk] >= k) can = 1;
        if(can) tr = md;
        else tl = md;
    }
    if(tr == n) printf("-1\n");
    else printf("%d", q[tr].first);
    
}