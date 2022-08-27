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
    int n,k;
    string s;
    cin>>n>>k>>s;
    int soid = 0;
    forn(i,0,n) if(s[i] == s[(i+1)%n]) soid = 1;
    if(soid == 0) {
        if(k%2) reverse(all(s));
        cout<<s;
        exit(0);
    }
    const int INF = 1e9;
    vi tw(n,INF);
    vi tb(n,INF);
    string t = s + s;
    int last = -1;
    char to = '?';
    forn(i,1,2*n) {
        if(t[i] == t[i-1]) {
            last = i;
            to = t[i];
        }
        if(last != -1) {
            if(to == 'B') tb[i%n] = min(tb[i%n], i - last);
            else tw[i%n] = min(tw[i%n], i - last);
        }
    }
    last = 2*n;
    for(int i = 2*n-2; i>=0; i--) {
        if(t[i] == t[i+1]) {
            last = i;
            to = t[i];
        }
        if(last != 2*n) {
            if(to == 'B') tb[i%n] = min(tb[i%n], last - i);
            else tw[i%n] = min(tw[i%n], last - i);
        }
    }
    forn(i,0,n) {
        if(k < min(tw[i], tb[i])) {
            if(k%2) {
                if(s[i] == 'B') s[i] = 'W';
                else s[i] = 'B';
            }
        }
        else if(tw[i] == tb[i]){
            if(tw[i]%2) {
                if(s[i] == 'B') s[i] = 'W';
                else s[i] = 'B';
            }
        }
        else if(tw[i] < tb[i]) s[i] = 'W';
        else s[i] = 'B';
    }
    cout<<s;
    
    
}