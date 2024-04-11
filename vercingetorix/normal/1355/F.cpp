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

ll ask(ll x) {
    printf("? %lld\n", x);
    fflush(stdout);
    ll ret;
    scanf("%lld", &ret);
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 700;
    //int mindiv[N+1];
    vi mindiv(N+1, 0);
    vector<ll> pr;
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
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        ll ans = 1;
        ll lim = 1e18;
    //    cout<<lim;
        int r = 0;
        vll q;
        vll div;
        while(r < pr.size()) {
            ll cur = pr[r];
            int nr = r+1;
            while(nr < pr.size() && pr[nr] <= lim/cur && cur*pr[nr]<=lim) cur *= pr[nr++];
            ll ret = ask(cur);
            forn(i,r,nr) {
                if(ret%pr[i] == 0) div.pb(pr[i]);
            }
            q.pb(cur);
            r= nr;
        }
        ll A = 1e9;
        ll nd = 1;
        forn(i,0,4) {
            ll cur = 1;
            if(i*2<div.size()) {
                int p = div[i*2];
                ll dp = p;
                while(dp*p<+A) dp*=p;
                cur *= dp;
            }
            if(i*2+1<div.size()) {
                int p = div[i*2+1];
                ll dp = p;
                while(dp*p<+A) dp*=p;
                cur *= dp;
            }
            ll ret = ask(cur);
            if(i*2<div.size()) {
                int p = div[i*2];
                int deg = 0;
                while(ret %p == 0) {
                    deg++;
                    ret/=p;
                }
                nd *= deg+1;
            }
            if(i*2+1<div.size()) {
                int p = div[i*2+1];
                int deg = 0;
                while(ret %p == 0) {
                    deg++;
                    ret/=p;
                }
                nd *= deg+1;
            }
        }
        if(div.size() > 8) forn(i,0,div.size() - 8) nd*=2;
    //    cout<<q.size();
    //    exit(0);
    //    for(auto x : pr) ans*=x;
    //    cout<<ans;
        if(nd == 1) printf("! 8\n");
        else if(nd == 2) printf("! 9\n");
        else printf("! %lld\n", 2*nd);
        fflush(stdout);
    }
    
}