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

#define pb push_back
#define mp make_pair
const int A = 100010;
multiset<ll> out[A];
ll in[A];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    vi d(m),f(m),t(m),c(m);
    set<int> st;
    vpi e1, e2;
    forn(i,0,m) {
        scanf("%d %d %d %d", &d[i], &f[i], &t[i], &c[i]);
        if(t[i] == 0) {
            e1.pb(mp(d[i], i));
            st.insert(d[i]);
        }
        else {
            e2.pb(mp(d[i], i));
        }
    }
    const ll INF = 1e13;
    forn(i,1,n+1) out[i].insert(INF);
    forn(i,1,n+1) in[i] = INF;
    int cnt = 0;
    sort(all(e1));
    sort(all(e2));
    int curl = 0;
    int p2 = 0;
    while(p2 < e2.size() && e2[p2].first < k+1) p2++;
    forn(i,p2,e2.size()) {
        int ind = e2[i].second;
        out[t[ind]].insert(c[ind]);
    }
    ll cur = 0;
    forn(i,1,n+1) cur += INF + *out[i].begin();
    ll best = 1e18;
    for(auto x : e1) {
        curl = x.first;
        int indx = x.second;
        int cf = f[indx];
        cur -= in[cf];
        in[cf] = min(in[cf], (ll)c[indx]);
        cur += in[cf];
        while(p2 < e2.size() && e2[p2].first <= curl + k) {
            int ind = e2[p2].second;
            int ct = t[ind];
            cur -= *out[ct].begin();
            out[ct].erase(out[ct].find(c[ind]));
            cur += *out[ct].begin();
            p2++;
        }
        best = min(cur, best);
    }
    if(best >= INF) cout<<-1;
    else cout<<best;
    
}