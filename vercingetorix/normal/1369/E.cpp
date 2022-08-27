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
    int n,m;
    scanf("%d %d", &n, &m);
    readv(w,n);
    vi need(n, 0);
    vi x(m), y(m);
    vvi h(n);
    vi res;
    set<int> undone;
    vi proc;
    forn(i,0,m) {
        scanf("%d %d", &x[i], &y[i]);
        x[i]--;
        y[i]--;
        need[x[i]] += 1;
        need[y[i]] += 1;
        h[x[i]].pb(i);
        h[y[i]].pb(i);
        undone.insert(i);
    }
    forn(i,0,m) {
        if(need[x[i]] <= w[x[i]] || need[y[i]] <= w[y[i]]) {
            undone.erase(i);
            proc.pb(i);
        }
    }
    while(proc.size() > 0) {
        int i = proc.back();
        res.pb(i+1);
        proc.pop_back();
        vi toeat;
        toeat.pb(x[i]);
        toeat.pb(y[i]);
        for(auto d : toeat) {
            need[d] -= 1;
            if (need[d] == w[d]) {
                for(auto j : h[d]) {
                    if(undone.find(j) != undone.end()) {
                        undone.erase(j);
                        proc.pb(j);
                    }
                }
            }
        }
    }
    if(undone.size() > 0) {
        cout<<"DEAD\n";
        return 0;
    }
    
    reverse(all(res));
    printf("ALIVE\n");
    for(auto x : res) printf("%d ", x);
    
}