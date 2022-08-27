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
    int n;
    scanf("%d\n", &n);
    char c[1000500];
    scanf("%s", c);
    n = string(c).size();
    if(c[0] != '(') {
        if(c[0] == '?') printf("YES\n");
        else printf("NO\n");
        exit(0);
    }
    
    vi op;
    vi rr(n,-1);
    forn(i,0,n) {
        if(c[i] == '?' || c[i] == '0' || c[i] == '1') rr[i] = i;
        else if(c[i] == '(') op.pb(i);
        else if(c[i] == ')') {
            rr[op.back()] = i;
            op.pop_back();
        }
    }
    vpi q;
    forn(i,0,n) if(rr[i] != -1) {
        q.pb(mp(rr[i]-i, i));
    }
    srt(q);
    vi can0(n,0);
    vi can1(n,0);
    vi can01(n,0);
    vi v0(n);
    vi v1(n);
    for(auto x : q) {
        int l = x.second;
        int r = rr[l];
        if(l == r) {
            if(c[l] == '0') can0[l] = 1;
            else if(c[l] == '1') can1[l] = 1;
            else can01[l] = 1;
        }
        else {
            int l1 = l+1;
            int r1 = rr[l1];
            int l2 = r1+2;
            char tp = c[r1+1];
            if(tp == '|') {
                if(can1[l1] || can1[l2] || can01[l1]*can01[l2]) can1[l] = 1;
                if(can0[l1] && can0[l2]) can0[l] = 1;
                if(can01[l1] && (can0[l2] || can01[l2])) can01[l] = 1;
                if(can01[l2] && can0[l1]) can01[l] = 1;
            }
            else if(tp == '&') {
                if(can0[l1] || can0[l2] || can01[l1]*can01[l2]) can0[l] = 1;
                if(can1[l1] && can1[l2]) can1[l] = 1;
                if(can01[l1] && (can1[l2] || can01[l2])) can01[l] = 1;
                if(can01[l2] && can1[l1]) can01[l] = 1;
            }
            else if(tp == '^') {
                if(can0[l1]*can0[l2] || can1[l1]*can1[l2] || can01[l1]*can01[l2]) can0[l] = 1;
                if(can0[l1]*can1[l2] || can1[l1]*can0[l2] || can01[l1]*can01[l2]) can1[l] = 1;
                if(can01[l1] && (can0[l2] || can1[l2])) can01[l] = 1;
                if(can01[l2] && (can0[l1] || can1[l1])) can01[l] = 1;
            }
        }
    }
    if(can01[0]) printf("YES\n");
    else printf("NO\n");
    
}