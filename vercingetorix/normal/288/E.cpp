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
int n;
string a,b;
ll ra = 0;
ll rb = 0;
#ifdef LOCAL
const int A = 20;
#else
const int A = 100500;
#endif
ll sum[A];
ll sum2[A];
ll ans[A];
ll cnt[A];
ll i10 = (ll(mod)*7+1)/10;
int dif = 0;

void go(int pt) {
    if(pt == 0) {
        if(a[pt] == b[pt]) {
            cnt[pt] = 1;
            sum[pt] = ra;
            sum2[pt] = ra*ra%mod;
        }
        else {
            cnt[pt] = 2;
            sum[pt] = (ra+rb)%mod;
            sum2[pt] = (ra*ra+rb*rb)%mod;
            ans[pt] = ra*rb%mod;
        }
        return;
    }
    if(dif == 0) {
        cnt[pt] = 1;
        sum[pt] = ra;
        sum2[pt] = ra*ra%mod;
        ans[pt] = 0;
        return;
    }
    if(b[pt] == '4') {
        int pt2 = pt-1;
        while(b[pt2] == '4') pt2--;
        ll d10 = 1;
        ll nrb = rb;
        for(int i = pt; i>pt2; i--) {
            nrb += 3*d10;
            d10 = d10*10%mod;
            dif -= (a[i] != b[i]);
            b[i] = '7';
            dif += (a[i] != b[i]);
        }
        nrb += 3*(mod-d10);
        nrb%=mod;
        dif -= (a[pt2] != b[pt2]);
        b[pt2] = '4';
        dif += (a[pt2] != b[pt2]);
        cnt[pt] = (cnt[pt] + 1) % mod;
        sum[pt] = (sum[pt] + rb)%mod;
        sum2[pt] = (sum2[pt] + rb*rb)%mod;
        ans[pt] = (ans[pt] + rb*nrb)%mod;
        rb = nrb;
    }
    if(dif == 0) {
        cnt[pt] = (cnt[pt] + 1) % mod;
        sum[pt] = (sum[pt] + rb)%mod;
        sum2[pt] = (sum2[pt] + rb*rb)%mod;
        return;
    }
    if(a[pt] == '7') {
        int pt2 = pt-1;
        while(a[pt2] == '7') pt2--;
        ll d10 = 1;
        ll nra = ra;
        for(int i = pt; i>pt2; i--) {
            nra += 3*(mod-d10);
            d10 = d10*10%mod;
            dif -= (a[i] != b[i]);
            a[i] = '4';
            dif += (a[i] != b[i]);
        }
        nra += 3*d10;
        nra%=mod;
        dif -= (a[pt2] != b[pt2]);
        a[pt2] = '7';
        dif += (a[pt2] != b[pt2]);
        sum[pt] = (sum[pt] + ra)%mod;
        cnt[pt] = (cnt[pt] + 1) % mod;
        sum2[pt] = (sum2[pt] + ra*ra)%mod;
        ans[pt] = (ans[pt] + ra*nra)%mod;
        ra = nra;
    }
    ra = (ra + mod - 4)*i10%mod;
    rb = (rb + mod - 7)*i10%mod;
    ll wra = ra;
    ll wrb = rb;
    dif--;
    go(pt-1);
    cnt[pt] = (cnt[pt] + 2*cnt[pt-1])%mod;
    sum[pt] = (sum[pt] + 20*sum[pt-1] + 11*cnt[pt-1])%mod;
    sum2[pt] = (sum2[pt] + 200*sum2[pt-1]+220*sum[pt-1]+65*cnt[pt-1])%mod;
    ans[pt] = (ans[pt] + 100*ans[pt-1]+28*(mod+cnt[pt-1]-1)+40*(sum[pt-1]+mod-wrb)+70*(sum[pt-1]+mod-wra) + 100*sum2[pt-1]+110*sum[pt-1]+28*cnt[pt-1])%mod;
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[100500];
    scanf("%s", c);
    a = string(c);
    scanf("%s", c);
    b = string(c);
    n = a.size();
    for(auto x : a) ra = (ra*10 + x-'0')%mod;
    for(auto x : b) rb = (rb*10 + x-'0')%mod;
    forn(i,0,n) if(a[i] != b[i]) dif++;
    go(n-1);
    cout<<ans[n-1]<<'\n';
//    cout<<44*47+47*74+74*77;
//    vi x = {444,447,474,477,744,747,774,777};
//    ll a2 = 0;
//    forn(i,1,x.size()) a2 += x[i]*x[i-1];
//    cout<<a2;

    
}