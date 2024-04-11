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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q,tn;
    scanf("%d %d %d", &n, &q, &tn);
    ll t = tn;
    readv(a,n);
    vi m(n,-1), l(n,-1);
    forn(i,0,q) {
        int b,c;
        scanf("%d %d", &b, &c);
        b--; c--;
        m[b] = c;
        l[c] = b;
    }
    vi vis(n,0);
    vll can;
    forn(i,0,n) {
        if(!vis[i]) {
            deque<int> p;
            p.pb(i);
            while(m[p.front()] != -1) {
                p.push_front(m[p.front()]);
                if(vis[p.front()]) {
                    cout<<0;
                    return 0;
                }
                vis[p.front()] = 1;
            }
            while(l[p.back()] != -1) {
                p.push_back(l[p.back()]);
                if(vis[p.back()]) {
                    cout<<0;
                    return 0;
                }
                vis[p.back()] = 1;
            }
            reverse(all(p));
            int k = p.size();
            if(k==1) can.pb(a[p[0]]);
            else {
                ll sum = 0;
                forn(j,0,k) {
                    sum += a[p[j]];
                    if(j<k-1) t -= sum;
                    can.pb(sum);
                }
            }
        }
    }
    if(t < 0) cout<<0;
    else if(t==0) cout<<1;
    else {
        vll d(t+1, 0);
        d[0] = 1;
        for(auto x : can) {
            for(int i = 0; i <= t-x; i++) d[i+x] = (d[i+x] + d[i]) % mod;
        }
        cout<<d[t];
    }
    
}