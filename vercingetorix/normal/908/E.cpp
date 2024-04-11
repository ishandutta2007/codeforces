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


const int MAXN = 100000;
vector<int> lst[MAXN];
int parent[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
        
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vvll cnk(1001, vll(1001, 0));
    forn(i,0,1001) cnk[i][0] = 1;
    forn(i,1,1001) {
        forn(j,1,1001) {
            cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }
    }
    vll bell;
    bell.pb(1);
    forn(l,0,1000) {
        bell.pb(0);
        forn(k,0,l+1) bell.back() += (cnk[l][k]*bell[k])%mod;
        bell.back()%=mod;
//        cout<<bell.back()<<endl;
    }
    
    int m,n;
    scanf("%d %d\n", &m, &n);
    vs s(n);
    forn(i,0,n) getline(cin, s[i]);
    forn(i,0,m) make_set(i);
    forn(i,0,m) forn(j,i+1,m) {
        bool can = true;
        forn(k,0,n) {
            if(s[k][i] != s[k][j]) {
                can = false;
                break;
            }
        }
        if(can) union_sets(i, j);
    }
    vi num;
    forn(i,0,m) if(!lst[i].empty()) num.pb(lst[i].size());
    ll ans = 1;
    for(auto x : num) ans = ans*bell[x]%mod;
    cout<<ans;
    
}