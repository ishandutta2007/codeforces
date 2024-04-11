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

map<ll, ll> save;
const ll A = 100500;
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
ll ask(int x, int y) {
    printf("? %d %d\n", x+1, y+1);
    fflush(stdout);
    ll ret;
    scanf("%lld", &ret);
    return ret;
}
// ll ask(int x, int y) {
    // return ll(x+40000)*(y+40000)/gcd(x+40000, y+40000);
// }

ll get(int x, int y) {
    if(x>y) swap(x,y);
    ll code = x*A+y;
    if(save[code] == 0){
        save[code] = ask(x,y);
    }
    return save[code];
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 1005001;
    vi mindiv(N+1, 0);
    vi maxdiv(N+1, 0);
    vector<int> pr;
    vi isp(N+1, 0);

    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    int md = 0;
    forn(i,1,pr.size()) {
        md= max(pr[i]-pr[i-1], md);
    }
    forn(i,2,N) {
        if(i==mindiv[i]) maxdiv[i] = i;
        else maxdiv[i] = maxdiv[i/mindiv[i]];
    }
    
    int t;
    scanf("%d", &t);
    while(t-- ) {
        save.clear();
        int n;
        scanf("%d", &n);
        if(n<=100) {
            int a,b;
            ll best = 0;
            forn(i,0,n) forn(j,i+1,n) {
                ll u = get(i,j);
                if(u > best) {
                    a=i;
                    b=j;
                    best = u;
                }
            }
            ll r = 0;
            while(r*(r-1) != best) r++;
            int c = 0;
            while(c==a||c==b) c++;
            vi ans(n,0);
            if(get(a,c) % r == 0) swap(a,b);
            ans[a] = r-1;
            ans[b] = r;
            forn(i,0,n) {
                if(i==a||i==b) continue;
                ans[i] = gcd(get(i,a), get(i,b));
            }
            printf("!");
            forn(i,0,n) printf(" %d", ans[i]);
            printf("\n");
            fflush(stdout);
            continue;
        }
        else {
            vi x;
            forn(i,0,n) x.pb(i);
            shuffle(all(x), gen);
            if(x.size()%2!=0) x.pb(x[0]);
            int bp = 0;
            pi ind;
            for(int i = 0; i<min((int)x.size(), 8000); i+=2) {
                ll nok = get(x[i], x[i+1]);
                ll brp = int(sqrt(nok))+2;
                for(auto xx : pr) {
                    if(xx>brp) break;
                    if(nok < N) {
                        nok=maxdiv[nok];
                        break;
                    };
                    while(nok%xx == 0) {
                        nok/=xx;
                    }
                    if(nok == 1) {
                        nok=xx;
                        break;
                    }
                }
                if(nok > bp) {
                    bp = nok;
                    ind = mp(x[i],x[i+1]);
                }
            }
            int pt = 0;
            while(pt == ind.first || pt==ind.second || (get(pt,ind.first) % bp == 0 && get(pt,ind.second)%bp==0)) pt++;
            int cool = ind.first;
            if(get(pt, ind.second) % bp == 0) cool = ind.second;
            vi ans(n);
            ans[cool] = bp;
            forn(i,0,n) if(i!=cool) ans[i] = get(i,cool)/bp;
            printf("!");
            forn(i,0,n) printf(" %d", ans[i]);
            printf("\n");
            fflush(stdout);
            continue;
        }
    }
    
    
}