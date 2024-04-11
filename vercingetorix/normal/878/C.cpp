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
const int INF = 2e9;

vvi a;
int n,k;
vi champ;

vpi otr;
vvi obeat;
vvi omax;
vi onum;
vector<vector<set<pi>>> og;

void dfswin(int v) {
    champ[v] = 1;
    onum.back() ++;
    forn(i,0,k) {
        obeat.back()[i] = min(obeat.back()[i], a[v][i]);
    }
    forn(i,0,k) {
        while(1) {
            if(og.back()[i].empty()) break;
            auto it = og.back()[i].begin();
            if(champ[it->second]) og.back()[i].erase(it);
            else if((-it->first) > obeat.back()[i]) {
                dfswin(it->second);
            }
            else break;
        }
    }
}

bool go() {
    bool did = false;
    forn(i,0,k) {
        while(1) {
            if(og.back()[i].empty()) break;
            auto it = og.back()[i].begin();
            if(champ[it->second]) og.back()[i].erase(it);
            else if((-it->first) > obeat.back()[i]) {
                did = true;
                dfswin(it->second);
            }
            else break;
        }
    }
    return did;
}

//vector<vector<set<pi>>> og;

bool unite() {
    if(otr.size() <= 1) return false;
    int m = otr.size();
    bool doit = false;
    forn(i,0,k) if(omax[m-2][i] > obeat[m-1][i]) doit = true;
    if(doit) {
        forn(i,0,k) omax[m-2][i] = max(omax[m-2][i], omax[m-1][i]);
        forn(i,0,k) obeat[m-2][i] = min(obeat[m-2][i], obeat[m-1][i]);
        onum[m-2] += onum[m-1];
        otr[m-2].second = otr[m-1].second;
        forn(i,0,k) {
            if(og[m-2][i].size() < og[m-1][i].size()) swap(og[m-2][i], og[m-1][i]);
            for(auto x : og[m-1][i]) og[m-2][i].insert(x);
        }
        og.pop_back();
        obeat.pop_back();
        onum.pop_back();
        otr.pop_back();
        omax.pop_back();
    }
    return doit;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &k);
    a =vvi(n, vi(k,0));
    
    int l = -1;
    champ = vi (n,0);
    forn(i,0,n) {
        bool canlose = false;
        forn(j, 0 ,k) {
            scanf("%d", &a[i][j]);
            if(i>0) {
                if(a[i][j] < omax.back()[j]) canlose = true;
                
            }
        }
        if(canlose == false) {
            l = i;
            
            otr.pb(mp(i,i));
            onum.pb(1);
            obeat.pb(a[i]);
            omax.pb(a[i]);
            og.pb(vector<set<pi>>(10)); 
            printf("%d\n", onum.back());
            continue;
        }
        else {
            forn(j,0,k) omax.back()[j] = max(omax.back()[j], a[i][j]);
            otr.back().second++;
            forn(j,0,k) og.back()[j].insert(mp(-a[i][j], i));
            while(1) {
                bool useful = go();
                useful |= unite();
                if(!useful) break;
            }
            
        }
        printf("%d\n", onum.back());
    }
    
}