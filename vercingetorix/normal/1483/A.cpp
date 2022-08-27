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
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);
        vvi a(m);
        vi ans(m);
        vi cnt(n+1,0);
        forn(i,0,m) {
            int k;
            scanf("%d", &k);
            a[i].resize(k);
            forn(j,0,k) scanf("%d", &a[i][j]);
            if(k==1) {
                ans[i] = a[i][0];
                cnt[ans[i]] ++;
            }
        }
        forn(i,0,m) {
            if(a[i].size() > 1) {
                if(cnt[a[i][0]] < cnt[a[i][1]]) {
                    ans[i] = a[i][0];
                    cnt[ans[i]]++;
                }
                else {
                    ans[i] = a[i][1];
                    cnt[ans[i]]++;
                }
            }
        }
        int can = 1;
        forn(i,1,n+1) if(cnt[i] > (m+1)/2) {
            can = 0;
        }
        if(can) {
            printf("YES\n");
            for(auto x : ans) printf("%d ", x);
            printf("\n");
        }
        else printf("NO\n");
        
    }
    
}