#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[100500];
    scanf("%s", c);
    string s(c);
    int n;
    vi to(26,-1);
    scanf("%d\n", &n);
    forn(i,0,n) {
        scanf("%s", c);
        to[c[0]-'a'] = c[1]-'a';
        to[c[1]-'a'] = c[0]-'a';
    }
    n = s.size();
    int ans = 0;
    int r = 0;
    while(r<n) {
        int cur = 0;
        vi cnt(2,0);
        while(1) {
            int nr = r+1;
            while(nr < n && s[nr] == s[r]) nr++;
            cnt[cur] += nr-r;
            if(nr == n || s[nr]-'a' != to[s[r]-'a']) {
                r = nr;
                break;
            }
            cur^=1;
            r = nr;
        }
        ans += min(cnt[0], cnt[1]);
    }
//    forn(i,1,n) {
//        if(to[s[i]-'a'] == s[i-1]-'a') {
//            int l = i-1;
//            int r = i;
//            while(l>=0 && s[l] == s[i-1]) l--;
//            while(r<n && s[r] == s[i]) r++;
//            l++;
//            r--;
//            ans += min(i-l, r-i+1);
//        }
//    }
    cout<<ans;
    
    
}