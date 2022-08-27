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
    int t;
    read(t);
    while(t--) {
        int n;
        read(n);
        readv(a, n);
        vi t(n+1,0);
        for(auto x : a) t[x]++;
        int can = 1;
        forn(i,0,n+1) if(t[i] > (n+1)/2) {
            can = -1;
        }
        if(can == -1) {
            printf("-1\n");
            continue;
        }
        int e = 2;
        vi cnt(n+1, 0);
        cnt[a[0]] ++;
        cnt[a[n-1]] ++;
        int ans = 0;
        forn(i,0,n-1) {
            if(a[i] == a[i+1]) {
                ans++;
                e+=2;
                cnt[a[i]] += 2;
            }
        }
        forn(i,1,n+1) if(cnt[i] > e/2 + 1) {
            ans += cnt[i] - (e/2+1);
        }
        printf("%d\n", ans);
        
    }
    
}