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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s;
    getline(cin, s);
    vi cnt(26,0);
    for(auto x : s) cnt[x-'a']++;
    forn(i,0,26) {
        if(cnt[i] >= 100) {
            cout<<string(100, 'a'+i);
            return 0;
        }
    }
    int n = s.size();
    vvi d(n, vi(n,0));
    vvi p(n, vi(n,0));
    forn(i,0,n) d[i][i] = 1;
    forn(i,0,n) p[i][i] = 2;
    forn(l,2,n+1) {
        forn(st,0,n+1-l) {
            int e = st+l-1;
            if(s[st] == s[e]) {
                d[st][e] = 2;
                p[st][e] = 2;
                if(l>2) {
                    d[st][e] += d[st+1][e-1];
                }
            }
            else {
                d[st][e] = d[st+1][e];
                p[st][e] = -1;
                if(d[st][e-1] > d[st][e]) {
                    d[st][e] = d[st][e-1];
                    p[st][e] = 1;
                }
            }
        }
    }
    int l = d[0][n-1];
    string ans(l, ' ');
    int pl = 0;
    int pr = n-1;
    int cs = 0;
    int ce = l-1;
    while(cs<=ce) {
        if(p[pl][pr] == -1) pl++;
        else if(p[pl][pr] == 1) pr--;
        else if(p[pl][pr] == 2) {
            ans[cs++] = s[pl++];
            ans[ce--] = s[pr--];
        }
    }
    if(ans.size() <= 100) cout<<ans;
    else {
        ans = ans.substr(0,50);
        forn(i,0,50) ans.pb(ans[49-i]);
        cout<<ans;
    }
    
}