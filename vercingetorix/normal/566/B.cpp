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
    vector<pair<int, pi>> q;
    vector<multiset<int>> s(n);
    forn(i,0,4*n) {
        int x,y,z;
        scanf("%d %d %d", &x,&y,&z);
        x--;
        y--;
        z--;
        
        q.pb(mp(x,mp(y,z)));
        s[y].insert(i);
        s[z].insert(i);
    }
    vi ans;
    forn(i,0,n) {
        for(auto x : s[i]) {
            if (x >= 0) {
                ans.pb(x+1);
                int cur = q[x].first;
                pi lo = q[x].second;
                s[lo.first].erase(x);
                s[lo.second].erase(x);
                s[cur].insert(-1);
                while(s[cur].size() == 9) {
                    for(auto u : s[cur]) {
                        if(u>-1) {
                            ans.pb(u+1);
                            cur = q[u].first;
                            lo = q[u].second;
                            s[lo.first].erase(u);
                            s[lo.second].erase(u);
                            s[cur].insert(-1);
                            break;
                        }
                    }
                }
                i--;
                break;
            }
        }
    }
    reverse(all(ans));
    printf("YES\n");
    for(auto u:ans) printf("%d ", u);
}