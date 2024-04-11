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
vi a;
vpi ans;
vi fin;
vi lef;

void add(int i, int j) {
    if(a[i] > a[j]) swap(i,j);
    ans.pb(mp(i,j));
    a[j] -= a[i];
    a[i] *= 2;
}

void win() {
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d %d\n", x.first+1, x.second+1);
    exit(0);
}

void reduce() {
    forn(bit,0,20) {
        if(lef.size() + fin.size() == 2) win();
        vi proc;
        forn(i,0,lef.size()) if(a[lef[i]] & (1<<bit)) proc.pb(i);
        for(int i = 1; i < proc.size(); i+=2) add(lef[proc[i]], lef[proc[i-1]]);
        if(proc.size()&1) {
            fin.pb(lef[proc.back()]);
            swap(lef[proc.back()], lef.back());
            lef.pop_back();
        }
        forn(i,0,lef.size()) {
            if(a[lef[i]] == 0) {
                swap(lef[i], lef.back());
                lef.pop_back();
                i--;
            }
        }
    }
    lef = fin;
    fin.clear();
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    a.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) if(a[i]!=0) lef.pb(i);
    if(lef.size() < 2) {
        cout<<-1;
        exit(0);
    }
    else if(lef.size() == 2) win();
    int d = 0;
    forn(i,0,n) d = gcd(d, a[i]);
    forn(i,0,n) a[i]/=d;
    reduce();
    while(lef.size() > 2) {
        forn(i,1,lef.size()) {
            while(a[lef[0]] > a[lef[i]]) add(lef[0], lef[1]);
        }
        reduce();
        int l = lef[0];
        int m = lef[1];
        int r = lef[2];
        int tar = a[r];
        int d2 = 1;
        while((d2 & a[m]) == 0) d2 *= 2;
        while((tar&d2)==0) tar/=2;
        while(a[l] != tar && a[r] != tar) add(l,r);
        reduce();
    }
}