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
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) a[i]--;
    vi self;
    forn(i,0,n) if(a[i]==i) self.pb(i);
    int ans = 0;
    if(self.size() == 0) {
        vi used(n,0);
        int v = 0;
        while(!used[v]) {
            used[v] = 1;
            v = a[v];
        }
        a[v] = v;
        ans++;
        self.pb(v);
    }
    forn(i,1,self.size()) {
        ans++;
        a[self[i]] = self[0];
    }
    vi used(n,0);
    used[self[0]] = 2;
    forn(i,0,n) {
        if(used[i] == 0) {
            vi cur;
            int pt = i;
            while(used[pt] == 0) {
                used[pt] = 1;
                cur.pb(pt);
                pt = a[pt];
            }
            if(used[pt] == 1) {
                ans++;
                a[pt] = self[0];
            }
            for(auto x : cur) used[x] = 2;
        }
    }
    printf("%d\n", ans);
    forn(i,0,n) printf("%d ", a[i]+1);
    
    
}