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

vi split(const vi & a) {
    vi ret;
    int sum = 0;
    for(auto x : a) sum+=x;
    if(sum%2!= 0) {
        return ret;
    }
    int mx = sum/2;
    vi d(mx+1, -2);
    d[0] = -1;
    int cursum = 0;
    for(auto x : a) {
//        forn(i,0,min(mx-x,cursum)+1) {
        for(int i = min(mx-x,cursum); i>=0; i--) {
            if(d[i] != -2 && d[i+x] == -2) d[i+x] = x;
        }
        cursum+=x;
    }
    if(d[mx] == -2) return ret;
    int pt = mx;
    while(pt!=0) {
        ret.pb(d[pt]);
        pt-=d[pt];
    }
    return ret;
}

vi split2(const vi & a, const vi & hlf) {
    multiset<int> rest;
    for(auto x : a) rest.insert(x);
    for(auto x : hlf) rest.erase(rest.find(x));
    vi ret;
    for(auto x : rest) ret.pb(x);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int h, v;
        scanf("%d", &h);
        readv(l, h);
        scanf("%d", &v);
        readv(p, v);
        vi l1 = split(l);
        vi p1 = split(p);
        if(l1.empty() || p1.empty() || h!=v) {
            printf("No\n");
            continue;
        }
        vi l2 = split2(l, l1);
        vi p2 = split2(p, p1);
        
        if(l1.size() > l2.size()) swap(l1,l2);
        if(p1.size() < p2.size()) swap(p1,p2);
        srt(p1);
        srt(p2);
        srtrev(l1);
        srtrev(l2);
        for(auto x : p2) p1.pb(-x);
        for(auto x : l2) l1.pb(-x);
        int cx = 0;
        int cy = 0;
        printf("Yes\n");
        forn(i,0,h) {
            printf("%d %d\n", cx, cy);
            cx += l1[i];
            printf("%d %d\n", cx, cy);
            cy += p1[i];
        }
    }
    
}