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
    int t;
    read(t);
    forn(afaff,0,t) {
        int n,m;
        scanf("%d %d", &n, &m);
        readv(a,n);
        readv(b,n);
        vpi v1, v2;
        int best = 2*n+1;
        int bt2 = 0;
        forn(i,0,n) {
            if(b[i] == 1) v1.pb(mp(a[i],i));
            else v2.pb(mp(a[i],i));
        }
        sort(all(v1));
        sort(all(v2));
        reverse(all(v1));
        reverse(all(v2));
        int t2 = v2.size();
        int t1 = 0;
        ll cur = 0;
        for(auto x : v2) cur += x.first;
        while(cur < ll(m) && t1 < v1.size()) cur+=v1[t1++].first;
        if(cur < m) {
            cout<<-1<<endl;
            continue;
        }
        best = 2*t2 + t1;
        bt2 = t2;
        while(t2 > 0) {
            cur -= v2[--t2].first;
            while(cur < ll(m) && t1 < v1.size()) cur+=v1[t1++].first;
            if(cur < m) break;
            if(best > 2*t2+t1) {
                best = 2*t2+t1;
                bt2 = t2;
            }
        }
        cout<<best<<endl;
    }
    
}