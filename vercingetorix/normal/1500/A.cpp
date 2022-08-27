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
    scanf("%d", &n);
    readv(a,n);
    ll lnn = n;
    vpi f;
    map<int, vi> q;
    forn(i,0,n) {
        q[i].pb(a[i]);
        if (q[i].size() == 2) {
            f.pb(mp(q[i][0], q[i][1]));
            q[i].clear();
        }
    }
    if(f.size() >= 2) {
        printf("YES\n");
        printf("%d %d %d %d", f[0].first+1, f[1].first+1, f[0].second+1, f[1].second+1);
        exit(0);
    }
//    if(lnn*lnn < 1e8) {
        vpi b;
        forn(i,0,n) b.pb(mp(a[i], i));
        srt(b);
        map<int, vpi> r;
        forn(i,0,n) forn(j,0,i) {
            int k = b[j].second;
            int l = b[i].second;
            int curd = b[j].first - b[i].first;
            for(auto x : r[curd]) if(x.first != k && x.second != k && x.first !=l && x.second != l) {
                printf("YES\n");
                printf("%d %d %d %d", k+1, x.second +1, l+1, x.first+1);
                exit(0);
            }
            r[curd].pb(mp(k, l));
        }
        cout<<"NO";
//    }
    
    
    
}