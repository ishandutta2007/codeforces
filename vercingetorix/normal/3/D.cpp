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
    int n = s.size();
    int k = 0;
    forn(i,0,n) if(s[i] == '?') k++;
    vi a(k), b(k);
    forn(i,0,k) cin>>a[i]>>b[i];
    ll ans = 0;
    forn(i,0,k) ans += b[i];
    int cur = 0;
    set<pi> q;
    int pt = 0;
    forn(i,0,n) {
        if(s[i] == '(') cur++;
        else {
            cur--;
            if(s[i] == '?') {
                q.insert(mp(a[pt] - b[pt], i));
                pt++;
                s[i] = ')';
            }
        }
        while(cur < 0 && !q.empty()) {
            cur += 2;
            s[q.begin()->second] = '(';
            ans += q.begin()->first;
            q.erase(q.begin());
        }
        if(cur < 0) {
            cur = 1;
            break;
        }
    }
    if(cur != 0) {
        cout<<-1;
    }
    else {
        cout<<ans<<'\n';
        cout<<s;
    }
    
}