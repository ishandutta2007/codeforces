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
#include <random>
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

map<int, int> cnt;
const int bot = 10000000;
vi cntmal(bot,0);

int getcnt(int i) {
    if(i<bot) return cntmal[i];
    else return cnt[i];
}

void modcnt(int i, int add) {
    if(i<bot) cntmal[i]+=add;
    else cnt[i] += add;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vi p(n);
    vi s(m);
    
    vpi comp;
    forn(i,0,n) {
        scanf("%d", &p[i]);
        modcnt(p[i], 1);
        comp.pb(mp(p[i], i));
    }
    set<pi> dec;
    vpi ans;
    int u = 0;
    vi md(m,0);
    forn(i,0,m) {
        scanf("%d", &s[i]);
        int d = 0;
        while(s[i] > 0 && getcnt(s[i]) == 0) {
            d++;
            if(s[i]==1) s[i] = 0;
            else s[i] = (s[i]+1)/2;
        }
        if(s[i] > 0) dec.insert(mp(d, i));
    }
    while(!dec.empty()) {
        auto it = dec.begin();
        int i = it->second;
        int d = it->first;
        if(getcnt(s[i]) > 0) {
            modcnt(s[i], -1);
            md[i] = d;
            u+=d;
            ans.pb(mp(s[i], i));
            dec.erase(it);
        }
        else {
            d++;
            if(s[i]==1) s[i] = 0;
            else s[i] = (s[i]+1)/2;
            while(s[i] > 0 && getcnt(s[i]) == 0) {
                d++;
                if(s[i]==1) s[i] = 0;
                else s[i] = (s[i]+1)/2;
            }
            dec.erase(it);
            if(s[i]>0) {
                dec.insert(mp(d,i));
            }
        }
        
    }
    vi con(n,0);
    sort(all(comp));
    sort(all(ans));
    int pa = 0;
    int pc = 0;
    while(pa<ans.size()) {
        if(comp[pc].first < ans[pa].first) pc++;
        else {
            con[comp[pc].second] = ans[pa].second +1;
            pa++;
            pc++;
        }
    }
    printf("%d %d\n", ans.size(), u);
    forn(i,0,m) {
        printf("%d", md[i]);
        if(i<m-1) printf(" ");
        else printf("\n");
    }
    forn(i,0,n) {
        printf("%d", con[i]);
        if(i<n-1) printf(" ");
        else printf("\n");
    }
    
}