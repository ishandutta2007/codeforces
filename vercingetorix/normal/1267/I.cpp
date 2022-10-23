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

const int A = 201;
int d[A*2][A*2];

int ask(int i, int j) {
    if(d[i][j] == -1) {
        cout<<"? "<<i+1<<' '<<j+1<<'\n';
        cout.flush();
        string ret;
        cin>>ret;
        d[i][j] = int(ret[0] == '>');
    }
    return d[i][j];
}

void done() {
    cout<<"!\n";
    cout.flush();
}


int score[A*2];
int own[A*2];

void solve(vi & ind) {
    for(auto x : ind) score[x] = 0;
    for(auto x : ind) for(auto y : ind) if(x!=y) score[x] += ask(x,y);
    vpi ord;
    for(auto i : ind) ord.pb(mp(score[i], i));
    srtrev(ord);
    ind.clear();
    for(auto x : ord) ind.pb(x.second);
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int ta;
    cin>>ta;
    forn(ifa,0,ta) {
        int n;
        cin>>n;
        forn(i,0,2*n) forn(j,0,2*n) d[i][j] = -1;
        vi ch;
        forn(i,0,n) {
            if(ask(i*2, i*2+1)) {
                ch.pb(i*2+1);
                own[i*2+1] = i*2;
            }
            else {
                ch.pb(i*2);
                own[i*2] = i*2+1;
            }
        }
        solve(ch);
        int a = own[ch[0]];
        int b = own[ch[1]];
        forn(i,2,n) {
            if(ask(own[ch[i]], b)) {
                b= own[ch[i]];
                break;
            }
        }
        ch.clear();
        forn(i,0,2*n) if(i!=a && i!=b) ch.pb(i);
        solve(ch);
        done();
    }
    
    
}