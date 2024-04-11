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
struct vertex {
    int next[26];
    int pick = 1;
    void clear() {forn(i,0,26) next[i] = - 1; pick = 1;};
};
const int NMAX = 2000000;
vertex t[NMAX];
int par[NMAX];
int sz;

const int K =26;

void add_string (const string & s) {
    int v = 0;
    for (size_t i=0; i<s.length(); ++i) {
        char c = s[i]-'a';
        if(t[v].next[c] == -1) {
            t[v].next[c] = sz;
            par[sz] = v;
            t[sz++].clear();
        }
        v = t[v].next[c];
    }
}

int ans = 0;

void dfs(int v) {
    if(v > 0) ans += t[v].pick;
    forn(i,0,26) if(t[v].next[i] != -1) dfs(t[v].next[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int tn;
    read(tn);
    char c[1000100];
    forn(it,0,tn) {
        sz = 1;
        t[0].clear();
        int n;
        read(n);
        vs s;
        vpi ord;
        forn(i,0,n) {
            scanf("%s", c);
            s.pb(string(c));
            add_string(s.back());
        }
        
        vi pn(n,1);
        vi pt(n,0);
        vi ptsuf(n,0);
        forn(i,0,n) {
            pt[i] = t[0].next[s[i][0] - 'a'];
            while(pn[i] < s[i].size() && t[ptsuf[i]].next[s[i][pn[i]] - 'a'] != -1) {
                char c = s[i][pn[i]] - 'a';
                pt[i] = t[pt[i]].next[c];
                ptsuf[i] = t[ptsuf[i]].next[c];
                pn[i]++;
            }
            ord.pb(mp(pn[i], i));
        }
        sort(all(ord));
        reverse(all(ord));
        int l = ord[0].first;
//        int ans = 0;
//        forn(i,0,n) ans += (int)s[i].size() - pn[i];
        ans = 0;
        for(int i = l; i>=1; i--) {
            int j = 0;
            while(j<n && ord[j].first == i) {
                int ind = ord[j].second;
                if(t[pt[ind]].pick) {
//                    printf("%s\n", s[ind].substr(0,i).c_str());
                    t[pt[ind]].pick = 0;
                    ans++;
                    t[ptsuf[ind]].pick = 0;
                }
                pt[ind] = par[pt[ind]];
                ptsuf[ind] = par[ptsuf[ind]];
                ord[j].first--;
                j++;
            }
        }
        
        dfs(0);
        printf("%d\n", ans);
        
    }
                    
    
    
}