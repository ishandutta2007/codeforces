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

vi a;
void go(int k) {
    forn(i,0,k/2) swap(a[i], a[k-1-i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n;
        read(n);
        a.resize(n);
        forn(i,0,n) scanf("%d", &a[i]);
        forn(i,0,n) a[i]--;
        int can = 1;
        forn(i,0,n) if(a[i]%2!=i%2) can = 0;
        if(can ==0 ) {
            printf("-1\n");
            continue;
        }
        vi ans;
        while(n > 1) {
            int p7 = 0;
            int p6 = 0;
            while(a[p7] != n-1) p7++;
            while(a[p6] != n-2) p6++;
            ans.pb(p7+1);
            if(p6<=p7) p6 = p7-p6;
            ans.pb(p6);
            ans.pb(p6+2);
            ans.pb(3);
            ans.pb(n);
            go(p7+1);
            go(p6);
            go(p6+2);
            go(3);
            go(n);
            n-=2;
        }
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d ", x);
        printf("\n");
    }
    
    
}