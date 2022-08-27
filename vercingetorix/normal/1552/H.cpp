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

const long long mod = 998244353 ;
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
vpi cur;
int ra(int k) {
    vpi q;
    forn(i,1,201) forn(j,1,201) {
        if(i%k==0) q.pb(mp(i,j));
    }
    printf("? %d\n", (int)q.size());
    for(auto x : q) printf("%d %d ", x.first, x.second);
    printf("\n");
    fflush(stdout);
    int ret = 0;
//    for(auto x : q) if(x.first>=1 && x.first<=200 && x.second>=114 && x.second<=115) ret++;
     scanf("%d", &ret);
    return ret;
}

int lastmove;
int solve(vpi x, int depth = 0, int domove = 0) {
    if(x.size() == 1 || (x.size() == 2 && x[0].first == x[1].second)) return 0;
    if(x.size() == 2) {
        if(domove) {
            forn(l,1,201) {
                if(x[0].first/l*x[0].second != x[1].first/l*x[1].second) {
                    if(x[0].first%l==0 || x[1].first%l==0 || x[0].first/l*x[0].second+x[0].second != x[1].first/l*x[1].second+x[1].second) {
                        lastmove = l;
                        break;
                    }
                }
            }
        }
        return 1;
    }
    int ret = 0;
    int ans = 10000;
    for(int l = 1; l<=20; l++) {
        if(ans +depth <= 3) break;
        map<int, vpi> to;
        for(auto a : x) {
            int h = a.first;
            int w = a.second;
            to[h/l * w].pb(mp(h,w));
            if(h%l!=0) {
                to[(h/l + 1)* w].pb(mp(h,w));
            }
        }
        int cand = 1;
        for(auto pp : to) {
            if(pp.second.size() +2 >= x.size() && x.size() > 6) {
                cand = ans;
                break;
            }
            if(pp.second.size() == x.size()) {
                cand = ans;
                break;
            }
            cand = max(cand, 1+solve(pp.second,depth + 1));
        }
        if(cand<ans) {
            ans = cand;
            lastmove = l;
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vvpi x(40001);
    forn(l,1,200) {
        forn(r,1,200) {
            x[(l+1)*(r+1)].pb(mp(l+1,r+1));
        }
    }
//            forn(i,0,40001) if(x[i].size() >= 10) {
//                cout<<i<<' '<<x[i].size()<<' '<<solve(x[i],0)<<endl;
//            }
//     cout<<solve(x[40000], 0);
//     exit(0);
    cur = x[ra(1)];
    int dep = 0;
    while(solve(cur, dep,1) != 0) {
        int a = ra(lastmove);
        vpi ncur;
        int l = lastmove;
        for(auto t : cur) {
            int h = t.first;
            int w = t.second;
            if(h/l*w == a || (h%l!=0  && (h/l+1)*w == a)) ncur.pb(t);
        }
        cur = ncur;
        dep ++;
    }
    cout<<'!'<<' '<<(cur[0].first+cur[0].second-2)*2<<endl;
    
    
    
}