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
    string s;
    cin>>s;
    vi cnt1(10,0);
    for(auto x : s) cnt1[x-'0']++;
    vi cnt2 = cnt1;
    int ans = 0;
    int best = -1;
    forn(e1,1,10) {
        if(cnt1[e1] > 0 && cnt2[10 - e1] > 0) {
            cnt1[e1]--;
            cnt2[10-e1]--;
            int cand = 1;
            forn(i,0,10) {
                cand += min(cnt1[i], cnt2[9-i]);
            }
            cand += min(cnt1[0] - min(cnt1[0], cnt2[9]), cnt2[0] - min(cnt2[0], cnt1[9]));
            cnt1[e1]++;
            cnt2[10-e1]++;
            if(cand > ans) {
                ans = cand;
                best = e1;
            }
        }
    }
    if(ans == 0) {
        srtrev(s);
        cout<<s<<'\n';
        cout<<s<<'\n';
    }
    else {
        string r1, r2;
        r1.pb('0'+best);
        r2.pb('0'+10-best);
        cnt1[best]--;
        cnt2[10-best]--;
        forn(i,0,10) {
            int tk = min(cnt1[i], cnt2[9-i]);
            r1 += string(tk, '0'+i);
            r2 += string(tk, '0'+9-i);
            cnt1[i] -= tk;
            cnt2[9-i] -= tk;
        }
        int z = min(cnt1[0], cnt2[0]);
        r1 = string(z, '0') + r1;
        r2 = string(z, '0') + r2;
        cnt1[0] -= z;
        cnt2[0] -= z;
        forn(i,0,10) {
            r1 += string(cnt1[i], '0'+i);
            r2 += string(cnt2[i], '0'+i);
        }
        reverse(all(r1));
        reverse(all(r2));
        cout<<r1<<'\n';
        cout<<r2<<'\n';
    }
    
    
}