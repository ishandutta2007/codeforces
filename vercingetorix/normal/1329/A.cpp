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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(l,m);
    vi cnt(n,0);
//    vi q;
    int mx = 0;
    forn(i,0,m) {
//        q.pb(mx + 1 - l[i]);
        mx = max(mx, i + l[i]);
    }
    if(mx > n) {
        cout<<-1;
        exit(0);
    }
    ll sum = 0;
    forn(i,0,m) sum+=l[i];
    if(sum < n) {
        cout<<-1;
        exit(0);
    }
    int pt = 0;
    vi q;
    forn(i,0,m) {
        if(pt + sum >= n){
            q.pb(pt++);
        }
        else {
            q.pb(n-sum);
            pt = n-sum+1;
        }
        sum -= l[i];
    }
//    int add = 0;
//    int to = n - mx;
//    forn(i,0,m) {
//        q[i] += add;
//        int shift = min(l[i] - 1, to);
//        add+=shift;
//        to-=shift;
//    }
//    if(to > 0) {
//        cout<<-1;
//        exit(0);
//    }
//    forn(i,0,m) cnt[l[i]]++;
//    int can = 1;
//    forn(i,0,n) if(cnt[i] == 0) can = 0;
//    vi mx = l;
//    for(int i = m-2; i>=0; i--) mx[i] = max(mx[i], mx[i+1]);
////    vi last(n,0);
////    forn(i,0,m) last[l[i]] = i;
//    vi islast(m,1);
////    forn(i,0,n) islast[last[i]] = 1;
////    int sum = 0;
////    forn(i,0,m) sum+=l[i];
//    int curdone = 0;
//    vi q;
//    forn(i,0,m) {
//        if(mx[i] + curdone > n) can = 0;
//        q.pb(curdone+1);
//        curdone += islast[i];
//    }
//    if(can == 0) cout<<-1;
//    else {
        for(auto x:q) printf("%d ", x+1);
//    }
    
    
}