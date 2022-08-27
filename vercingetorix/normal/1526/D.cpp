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
    scanf("%d\n",&t);
    char c[100500];
    while(t--) {
        scanf("%s", c);
        string s(c);
        int n = s.size();
        vi a;
        forn(i,0,n) {
            if(s[i]=='A') a.pb(0);
            if(s[i]=='N') a.pb(1);
            if(s[i]=='T') a.pb(2);
            if(s[i]=='O') a.pb(3);
        }
        string dec = "ANTO";
        vi cnt(4,0);
        vvll d(4,vll(4,0));
        forn(i,0,n) {
            forn(j,0,4) if(j!=a[i]) d[j][a[i]] += cnt[j];
            cnt[a[i]]++;
        }
        string t;
        vi x;
        x.pb(0);x.pb(1);x.pb(2);x.pb(3);
        string ans;
        ll best = -1;
        do {
//            int bad = 0;
            ll cand = 0;
            forn(i,0,4) forn(j,i+1,4) {
                cand += d[x[j]][x[i]];
//                if(d[x[i]][x[j]] > d[x[j]][x[i]]) bad =1;
            }
            if(cand > best) {
                best = cand;
                ans.clear();
                forn(i,0,4) ans += string(cnt[x[i]],dec[x[i]]);
//                break;
            }
        } while(next_permutation(all(x)));
        printf("%s\n", ans.c_str());
    }
    
    
}