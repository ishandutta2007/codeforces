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

const long long mod = 998244353;
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
    int t;
    read(t);
    while(t--) {
        int n;
        read(n);
        readv(a,n);
        if(n==1) {
            printf("1\n");
            continue;
        }
        ll ans= 0;
        ll sum = 0;
        forn(i,0,n) sum+=a[i];
// 1.1
        ll cursum = 0;
        int pt = 0;
        while(cursum * 2 <= sum) cursum+=a[pt++];
        ans += n+1-pt;
// 1.2 (no PPPPPP)
        cursum = 0;
        pt = n-1;
        while(cursum * 2 <= sum) cursum+=a[pt--];
        ans += 1+pt;
// 1.3
        cursum = 0;
        pt = n-2;
        while(pt>=0 && cursum * 2 <= sum) cursum+=a[pt--];
        ans += 1+pt;
// 2.2 2.1 3.2 3.1
        forn(m3,0,2) {
            forn(en, 0, 2) {
                forn(ast, 0, 2) {
                    int st = ast+m3*3;
                    cursum = 0;
                    if(m3) cursum += a[0];
                    if(en) cursum += a[n-1];
                    for(int i = st; i < n-1; i+=2) {
                        cursum += a[i];
                    }
                    int r = n-2;
                    if(r%2 == st%2) r--;
                    if(r==n-2 && en == 0) {
                        cursum+=a[r];
                        r-=2;
                    }
                    while(st<n-en) {
                        while(cursum * 2 <= sum && r > st) {
                            cursum += a[r];
                            r-=2;
                        }
                        if(cursum*2 <= sum) break;
                        if(r<st-1) break;
                        if(m3 == 0 && r == st-1) break;
                        if(m3 == 0) ans += (r+1-st)/2;
                        else ans += (r+3-st)/2;
                        cursum-=a[st];
                        st+=2;
                    }
                }
            }
        }
        if(n>=4  && 2*ll(a[0]+a.back()) > sum ) ans++;
        printf("%lld\n", ans%mod);
//        forn(st,0,2) {
//            if(st )
//            cursum = 0;
//            for(int i = st; i < n; i+=2) cursum +=a[i];
//        }
    }
    
    
    
}