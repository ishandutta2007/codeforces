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
    vll t(n), w(n);
    forn(i,0,n) {
        scanf("%lld %lld", &t[i], &w[i]);
    }
    vpll cont;
    multiset<ll> gr;
    forn(i,1,n) {
        cont.pb(mp(t[i], i));
    }
    sort(all(cont));
    int p = n-2;
    while(p >= 0 && t[0] < cont[p].first) {
        int ind = cont[p].second;
        gr.insert(w[ind]-t[ind]);
        p--;
    }
    int ans = 1 + gr.size();
    while(1) {
        if(gr.empty()) break;
        auto it = gr.begin();
        if(t[0] <= *it) {
            break;
        }
        t[0] -= (*it+1);
        gr.erase(it);
        while(p >= 0 && t[0] < cont[p].first) {
            int ind = cont[p].second;
            gr.insert(w[ind]-t[ind]);
            p--;
        }
        ans = min(ans, 1+(int)gr.size());
    }
    cout<<ans;
}