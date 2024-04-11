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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
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
    int t;
    scanf("%d\n", &t);
    char c[500500];
    while(t--) {
        scanf("%s", c);
        string s(c);
        int n = s.size();
        vvi pos(26);
        string ord;
        for(int i = n-1; i>=0; i--) {
            int cur = s[i] -'a';
            if(pos[cur].size() == 0) ord.pb(s[i]);
            pos[cur].pb(i);
        }
        forn(i,0,26) reverse(all(pos[i]));
        reverse(all(ord));
        int l = 0;
        int r = n;
        int can = 1;
        forn(i,0,ord.size()) {
            int k = i+1;
            int m = pos[ord[i]-'a'].size();
            if(m%k != 0) {
                can = 0;
                break;
            }
            l = max(l, pos[ord[i] - 'a'][m/k - 1]);
            if(k>1) r = min(r, pos[ord[i] - 'a'][m/k]);
        }
        if(r!= l+1) can = 0;
        if(can == 0) {
            printf("-1\n");
            continue;
        }
        string tc;
        string sc = s.substr(0,l+1);
        string wsc = sc;
        for(auto x : ord) {
            tc += sc;
            string nsc;
            for(auto y : sc) if(x!=y) nsc.pb(y);
            sc = nsc;
        }
        if(tc == s) {
            printf("%s %s\n", wsc.c_str(), ord.c_str());
        }
        else {
            printf("-1\n");
        }
    }
    
}