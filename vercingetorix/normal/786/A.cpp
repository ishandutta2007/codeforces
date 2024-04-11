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
    vvi a(2);
    vi k(2);
    scanf("%d", &k[0]);
    a[0].resize(k[0]);
    forn(i,0,k[0]) {
        scanf("%d", &a[0][i]);
    }
    scanf("%d", &k[1]);
    a[1].resize(k[1]);
    forn(i,0,k[1]) {
        scanf("%d", &a[1][i]);
    }
    vvi res(2, vi(n,0));
    res[0][0] = -1;
    res[1][0] = -1;
    deque<pi> q;
    q.pb(mp(0,0));
    q.pb(mp(1,0));
    vvi pos(2,vi(n));
    forn(i,0,n) {
        pos[0][i] = k[0];
        pos[1][i] = k[1];
    }
    while(!q.empty()) {
        int p = q.front().first;
        int x = q.front().second;
        q.pop_front();
        int p1 = 1-p;
        if(res[p][x] == -1) {
            for(auto m : a[p1]) {
                int y = (n+x-m)%n;
                if(res[p1][y] == 0) {
                    res[p1][y] = 1;
                    q.pb(mp(p1,y));
                }
            }
        }
        else if(res[p][x] == 1) {
            for(auto m : a[p1]) {
                int y = (n+x-m)%n;
                pos[p1][y]--;
                if(pos[p1][y] == 0) {
                    res[p1][y] = -1;
                    q.pb(mp(p1,y));
                }
            }
        }
    }
    vs ans = {"Lose", "Loop", "Win"};
    forn(i,1,n) {
        printf("%s ", ans[res[0][i]+1].c_str());
    }
    printf("\n");
    forn(i,1,n) {
        printf("%s ", ans[res[1][i]+1].c_str());
    }
}