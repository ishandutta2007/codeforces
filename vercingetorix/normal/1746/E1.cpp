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

int ask(const vi & a) {
    cout<<'?' <<' '<<a.size();
    for(auto x : a) cout<<' '<<x;
    cout<<'\n';
    cout.flush();
    string s;
    cin>>s;
    if(s[0] == 'Y') return 1;
    else return 0;
}

int ask(const vi & a, const vi & b) {
    cout<<'?' <<' '<<a.size()+b.size();
    for(auto x : a) cout<<' '<<x;
    for(auto x : b) cout<<' '<<x;
    cout<<'\n';
    cout.flush();
    string s;
    cin>>s;
    if(s[0] == 'Y') return 1;
    else return 0;
}

void go(int x) {
    cout<<"! "<<x<<'\n';
    cout.flush();
    string s;
    cin>>s;
    if(s[1] == ')') exit(0);
}


void solve(const vi & a) {
    int n = a.size();
    if(n<=2) {
        go(a[0]);
        go(a[1]);
    }
    else if(n==3) {
        if(ask({a[0]}) == 1) {
            go(a[0]);
            if(ask({a[1]})) go(a[1]);
            else go(a[2]);
        }
        else {
            if(ask({a[1], a[2]})) {
                go(a[1]);
                go(a[2]);
            }
            else {
                go(a[0]);
                if(ask({a[1]})) go(a[1]);
                else go(a[2]);
            }
        }
        exit(0);
    }
    vvi b(4);
    forn(i,0,a.size()) b[i%4].pb(a[i]);
    int p = ask(b[0], b[1]);
    int q = ask(b[1], b[2]);
    int bad = 0;
    if(p == 0 && q == 0) bad = 1;
    else if(p == 0 && q == 1) bad = 0;
    else if(p == 1 && q == 0) bad = 2;
    else bad = 3;
    vi na;
    forn(i,0,a.size()) if(i%4!=bad) na.pb(a[i]);
    solve(na);
}


int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
//    int n = 100000;
//    forn(i,0,37) {
//        n = n/4*3 + n %4;
//    }
//    cout<<n<<'\n';

    int  n;
    cin>>n;
    vi a;
    forn(i,1,n+1) a.pb(i);
    solve(a);
    
}