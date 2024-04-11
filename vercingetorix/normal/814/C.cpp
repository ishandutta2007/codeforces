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

#define all(c) (c).begin(),(c).end()
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
    scanf("%d\n", &n);
    string s;
    getline(cin, s);
    const int INF = 1e9;
    vvi ans(26, vi(n+1, INF));
    forn(l,0,n) {
        vi cnt(26,0);
        forn(r,l,n) {
            cnt[s[r]-'a']++;
            forn(i,0,26) {
                ans[i][r-l+1] = min(ans[i][r-l+1], r-l+1-cnt[i]);
            }
        }
    }
    int q;
    scanf("%d", &q);
    forn(i,0,q) {
        int m; char c;
        scanf("%d %c", &m, &c);
        int l = 1;
        int r = n+1;
        while(r-l>1) {
            int t = (r+l)/2;
            if(ans[c-'a'][t] <= m) l = t;
            else r = t;
        }
        printf("%d\n", l);
    }
    
}