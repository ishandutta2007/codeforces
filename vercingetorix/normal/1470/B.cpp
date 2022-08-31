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
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 1001000;
    int mindiv[N+1];
    vector<ll> pr;
    vi isp(N, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    int t;
    read(t);
    vi cnt(1000010, 0);
    forn(affa,0,t) {
        set<int> touch;
        int n;
        read(n);
        readv(a,n);
        for(auto x : a) {
            int y = x;
            int odd = 1;
            while(y > 1) {
                int d = mindiv[y];
                y /= d;
                if (y%d == 0) y/=d;
                else odd*=d;
            }
            cnt[odd]++;
            touch.insert(odd);
        }
        int ans0 = 1;
        for (auto x : touch) ans0 = max(ans0, cnt[x]);
        int ans1 = 0;
        for(auto x : touch) if(x==1 || cnt[x]%2==0) ans1 += cnt[x];
        ans1 = max(ans0,ans1);
        int q;
        read(q);
        forn(afaf,0,q) {
            ll x;
            scanf("%lld", &x);
            if(x > 0) printf("%d\n", ans1);
            else printf("%d\n", ans0);
        }
        for (auto x : touch) cnt[x]=0;
    }
}