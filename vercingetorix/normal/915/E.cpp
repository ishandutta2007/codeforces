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
    int n;
    scanf("%d", &n);
    int q;
    scanf("%d", &q);
    set<pi> a;
    int hol = 0;
    forn(i,0,q) {
        int l,r,tp;
        scanf("%d %d %d", &l, &r, &tp);
        if(tp == 1) {
            auto it = a.lower_bound(mp(l, 0));
            vpi del;
            pi add = mp(l,r);
            if(it!=a.begin()) {
                it--;
                if(it->second >= l - 1) {
                    add.first = it->first;
                    del.pb(*it);
                    add.second = max(add.second, it->second);
                }
                it++;
            }
            while(it!=a.end() && it->first <= r+1) {
                del.pb(*it);
                add.second = max(add.second, it->second);
                it++;
            }
            for(auto x : del) {
                a.erase(x);
                hol -= (x.second-x.first+1);
            }
            hol+=add.second-add.first+1;
            a.insert(add);
        }
        else if(tp==2){
            vpi del;
            vpi add;
            auto it = a.lower_bound(mp(l,0));
            if(it!=a.begin()) {
                it--;
                if(it->second >= l) {
                    del.pb(*it);
                    add.pb(mp(it->first, l-1));
                    if(it->second > r) add.pb(mp(r+1,it->second));
                }
                it++;
            }
            while(it != a.end() && it->first <= r) {
                del.pb(*it);
                if(it->second > r) add.pb(mp(r+1,it->second));
                it++;
            }
            for(auto x : del) {
                a.erase(x);
                hol -= (x.second-x.first+1);
            }
            for(auto x : add) {
                a.insert(x);
                hol += (x.second-x.first+1);
            }
        }
        printf("%d\n", n-hol);
    }
    
   
    
}