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
map<pi, int> a;
vector<pair<pi, pi>> q;
pi pos = mp(0,0);

void mv(char c) {
    pair<pi, pi> mv;
    mv.first = pos;
    mv.second = mp(0,0);
    if(c=='u') pos.first--;
    else if(c=='d') pos.first++;
    else if(c=='l') pos.second--;
    else if(c=='r') pos.second++;
    q.pb(mv);
}

void modify(char c) {
    pair<pi, pi> mv;
    mv.first = pos;
    mv.second = mp(1,a[pos]);
    if (c == 'e') a[pos] = 0;
    else if(c=='1') a[pos] = 2;
    else if(c == '0') a[pos] = 1;
    q.pb(mv);
}

void time() {
    int del = min(a[pos], (int)q.size());
    while(del--) {
        if(q.back().second.first == 1) {
            a[pos] = q.back().second.second;
        }
        else pos = q.back().first;
        q.pop_back();
    }
}
string s;

char bold(char c) {
    if(c=='_') return 'o';
    if(c=='0') return 'r';
    if(c=='1') return 'R';
    return c;
}

void print() {
    int l = pos.second;
    int r = pos.second;
    int u = pos.first;
    int d = pos.first;
    for(auto x:a) {
        l = min(l,x.first.second);
        r = max(r,x.first.second);
        d = min(d,x.first.first);
        u = max(u,x.first.first);
    }
    vector<string> f(u-d+1, string(r-l+1, '_'));
    
    for(auto x : a) {
        char to = '_';
        if(x.second == 1) to = '0';
        if(x.second == 2) to = '1';
        f[x.first.first-d][x.first.second-l] = to;
    }
    f[pos.first-d][pos.second-l] = bold(f[pos.first-d][pos.second-l]);
//    reverse(all(f));
//    for(auto & x : f) reverse(all(x));
    for(auto x : f) printf("%s\n", x.c_str());
    printf("\n");
}
string ans;

void feed(string s) {
    ans += s;
//    for(auto c : s) {
//        for(auto x : "udlrs") if(c==x) mv(c);
//        for(auto x : "e10") if(c==x) modify(c);
//        if(c=='t') time();
//    }
}

void debug() {
    feed("ur0d0l");
    forn(i,0,32){
        forn(x,0,31) feed("lrt"); // go to the first 1 or empty
        forn(i,0,4) feed("usdtd"); // stay in place on 1 or go 3 squares down on empty
        
        feed("srt"); // move right if can
        feed("0u");
        forn(i,0,31) {
            feed("u10dtuusdtdd0u");
            feed("lrst");
            feed("reled");
            // skip all 1s to the left and write 0 instead
        }
        feed("u1d"); // mark position
        
        forn(x,0,31) feed("srt0"); // fill 0 to the right
        
        feed("ru");
        forn(i,0,35) feed("rsltl"); // go to marked position
        
        feed("ed1"); //remove marked, go down and print 1
        // set for next
        feed("d");
        forn(i,0,31) feed("r");
        forn(i,0,35) feed("rsltl");
    }
    forn(i,0,350) feed("u");
    forn(i,0,350) feed("usdtd");
    forn(i,0,40) feed("rslt");
    feed("ledeul"); // lel
    forn(i,0,40) feed("lsrt");
    feed("r");
//    print();
//    cout<<ans.size();
    cout<<ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    debug();
    
}