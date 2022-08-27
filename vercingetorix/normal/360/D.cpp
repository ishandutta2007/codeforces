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

int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

vi primes;
int phi (int n) {
    int result = n;
    for (auto i : primes){
        if(i*i > n) break;
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);
    
    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

map<int,int> vals;

ll solve (ll a, ll b, ll m) {
    
    int n = (int) sqrt (m + .0) + 1;
    for (int i=0, cur=b; i<=n; ++i) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - i;
            if (ans < m)
                return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int LIMIT = 100000;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            primes.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            primes.pb(m);
        }
    }
    
    
    
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    if(p==2) {
        cout<<1;
        return 0;
    }
    vi divp;
    vi divs;
    forn(i,1,p) {
        if(i*i>=p-1) {
            if(i*i == p-1) divs.pb(i);
            break;
        }
        if((p-1)%i==0) {
            divs.pb(i);
            divs.pb((p-1)/i);
        }
    }
    sort(all(divs));
    int s = divs.size();
    int left = p-1;
    for(auto u : primes) {
        while(left%u==0) {
            divp.pb(u);
            left/=u;
        }
    }
    if(left>1) divp.pb(left);
    sort(all(divp));
    
    
    
    vi a(n);
    vi b(m);
    forn(i,0,n) scanf("%d", &a[i]);
    ll d = p-1;
    forn(i,0,m) {
        scanf("%d", &b[i]);
        b[i] = gcd(b[i], p-1);
        d = gcd(b[i], d);
    }
    int pr = generator(p);
    
    int M = p;
    int N = (int) sqrt (M + .0) + 1;
    ll an = 1;
    for (int i=0; i<N; ++i)
        an = (an * pr) % M;
    for (int i=1, cur=an; i<=N; ++i) {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = (cur * an) % M;
    }
    
    vi deg(n);
    //map<int,int> good;
    
    vvi del(s);
    forn(i,0,s) {
        forn(j,0,i) {
            if(divs[i]%divs[j] == 0) del[i].pb(j);
        }
    }
    
    vi good(s,0);
    forn(i,0,n) {
        int cur = s-1;
        bool f = true;
        while(f) {
            f= false;
            for(auto j : del[cur]) {
                if(powmod(a[i], divs[j], p) == 1) {
                    f=true;
                    cur = j;
                    break;
                }
            }
        }
        deg[i] = (p-1)/divs[cur];
    }
    
    forn(i,0,n) {
        //deg[i] = solve(pr, a[i], p);
        int cover = gcd(p-1, (ll)deg[i] * d);
        int ci = lower_bound(all(divs), cover) - divs.begin();
        good[ci] = 1;
    }
    int ans = 0;
    forn(ui,0,s) {
        int u = divs[ui];
        int sum = 0;
        if(good[ui] == 0) {
            forn(viv,0,s) {
                int v =divs[viv];
                if (v >=u) break;
                if(u%v == 0){
                    if(good[viv]) {
                        good[ui] = 1;
                        break;
                    }
                }
            }
        }
        if(good[ui]) ans += phi((p-1)/u);
    }
    cout<<ans;
    //cout<<pr<<endl;
    //forn(i,0,n) cout<<deg[i]<<endl;
}