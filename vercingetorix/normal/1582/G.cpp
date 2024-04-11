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
const int N = 1000500;
//int deg[N];
int mindiv[N+1];

//void add(int v) {
//    while(v > 1) {
//        deg[mindiv[v]]++;
//        v /= mindiv[v];
//    }
//}
//
//bool canrem(int v) {
//    vpi dec;
//    while(v > 1) {
//        int p = mindiv[v];
//        dec.pb(mp(p,1));
//        v/=p;
//        while(v%p==0) {
//            v/=p;
//            dec.back().second++;
//        }
//    }
//    for(auto it : dec) if(deg[it.first] < it.second) return false;
//    for(auto it : dec) deg[it.first] -= it.second;
//    return true;
//}

struct sega {
    sega() {};
    sega(int v) {
        add(v);
    };

    map<int, int> deg;
    int numbad = 0;
    
    void add(int v) {
        while(v > 1) {
            deg[mindiv[v]]++;
            if(deg[mindiv[v]] == 0) numbad --;
            v /= mindiv[v];
        }
    }
    
    void rem(int v) {
        while(v > 1) {
            deg[mindiv[v]]--;
            if(deg[mindiv[v]] == -1) numbad ++;
            v /= mindiv[v];
        }
    }
    
    void killjoin(sega & f) {
        if(f.deg.size() > deg.size()) {
            swap(f.deg, deg);
            swap(numbad, f.numbad);
        }
        for(auto x : f.deg) {
            if(deg[x.first] < 0) numbad --;
            deg[x.first] += x.second;
            if(deg[x.first] < 0) numbad ++;
        }
    }
    
    bool isbad() {
        return numbad > 0;
    }
    
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
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
    int n;
    scanf("%d", &n);
    vi a(n);
    char c[1000500];
    forn(i,0,n) {
        if(i<n-1) scanf("%d", &a[i]);
        else scanf("%d\n", &a[i]);
    }
    scanf("%s", c);
    string s(c);
    vector<sega> q;
    ll ans = 0;
    forn(i,0,n) {
        sega cur;
        if(s[i] == '*') cur.add(a[i]);
        else cur.rem(a[i]);
        while(cur.isbad()) {
            if(q.empty()) break;
            cur.killjoin(q.back());
            q.pop_back();
        }
        if(cur.isbad() == false) {
            q.emplace_back(std::move(cur));
        }
        ans += q.size();
    }
    cout<<ans;
//    ll ans = 0;
//    int l = n;
//    int gr = n;
//    while(l > 0) {
//        l--;
//        if(s[l] == '*') {
//            add(a[l]);
//            while(gr)
//        }
//    }

    
}