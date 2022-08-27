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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    forn(i,0,n) a[i]--;
    vi vis(n,0);
    vvi c;
    forn(i,0,n) {
        if(vis[a[i]]) continue;
        int cur = a[i];
        vis[i] = 1;
        c.pb(vi(1,i));
        while(!vis[cur]) {
            c.back().pb(cur);
            vis[cur] = 1;
            cur = a[cur];
        }
    }
    vpi ans;
    while(c.size() > 1) {
        int k = c.size();
        vi A = c[k-2];
        vi B = c[k-1];
        ans.pb(mp(A[0], B[0]));
        forn(i,1,A.size()) ans.pb(mp(A[i], B[0]));
        forn(i,1,B.size()) ans.pb(mp(A[0], B[i]));
        ans.pb(mp(A[0], B[0]));
        c.pop_back();
        c.pop_back();
    }
    if(c.size() == 1) {
        vi A = c[0];
        if(A.size() >= 3) {
            ans.pb(mp(A[0], A[2]));
            forn(i,3,A.size()) ans.pb(mp(A[0], A[i]));
            ans.pb(mp(A[0], A[1]));
            ans.pb(mp(A[1], A[2]));
            ans.pb(mp(A[0], A[2]));
        }
        else if(A.size() == 2){
            int pt = 0;
            while(pt == A[0] || pt == A[1]) pt++;
            ans.pb(mp(A[0], pt));
            ans.pb(mp(A[1], pt));
            ans.pb(mp(A[0], pt));
        }
    }
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d %d\n", x.first+1, x.second+1);
    
}