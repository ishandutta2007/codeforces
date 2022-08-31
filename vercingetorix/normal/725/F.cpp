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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    ll diff = 0;
    vpll u;
    forn(i,0,n) {
        int a1,b1,a2,b2;
        scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
        
        auto pr = mp((ll)a1+b1, (ll)a2+b2);
//        if(pr.first < pr.second) diff -= pr.first-pr.second;
//        else u.pb(pr);
        if(pr.first > pr.second) {
            u.pb(pr);
            diff += (ll)(a1-b1);
            diff += (ll)(a2-b2);
        }
        else {
            if(a1 > b2) diff+= 2*ll(a1-b2);
            if(b1 > a2) diff-=2*ll(b1-a2);
        }
    }
    n = u.size();
    vi p(n,0);
    set<pll> worst;
    forn(i,0,n) {
        worst.insert(mp(-u[i].first, i));
    }
    forn(i,0,n) {
        auto it = worst.begin();
        int ind = it -> second;
        diff -= it->first;
        worst.erase(it);
        if(p[ind] == 0) {
            p[ind] = 1;
            worst.insert(mp(-u[ind].second, ind));
        }
        it = worst.begin();
        ind = it -> second;
        diff += it->first;
        worst.erase(it);
        if(p[ind] == 0) {
            p[ind] = 1;
            worst.insert(mp(-u[ind].second, ind));
        }
    }
    cout<<diff/2;
    
}