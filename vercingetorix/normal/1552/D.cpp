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
    vi d2(1,1);
    forn(i,0,20) d2.pb(d2.back()*2);
    while(t--) {
        int n;
        scanf("%d\n", &n);
        readv(a,n);
        vi msum(d2[n]);
        forn(mask,0,d2[n]) {
            int sum = 0;
            forn(bit,0,n) if(mask&d2[bit]) sum += a[bit];
            msum[mask] = sum;
        }
        int can = 0;
        forn(i,0,d2[n]) {
            if(can) break;
            forn(j,i+1,d2[n]) {
                if(msum[i] == msum[j]) {
                    can = 1;
                    break;
                }
            }
        }
        if(can) printf("YES\n");
        else printf("NO\n");
    }
    
}