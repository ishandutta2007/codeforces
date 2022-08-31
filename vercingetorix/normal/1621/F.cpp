#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char cc[100500];
    forn(ifa,0,ta) {
        int n,a,b,c;
        scanf("%d %d %d %d\n", &n, &a, &b, &c);
        scanf("%s", cc);
        string s(cc);
        int c1 = 0;
        int c0 = 0;
        int t1 = 0;
        forn(i,0,n) if(s[i] == '1') t1++;
        forn(i,1,n) {
            if(s[i] == '1' && s[i-1] == '1') c1++;
            if(s[i] == '0' && s[i-1] == '0') c0++;
        }
        int kek = 0;
        if(s[0]  =='0') kek++;
        if(t1 > 0 && s.back() == '0') kek++;
        char last = '*';
        int cnt = 0;
        int met = 0;
        vi z;
        forn(i,0,n) {
            if(s[i] != last) {
                if(last == '0' && met > 0 && met < t1) {
                    z.pb(cnt);
                }
                last = s[i];
                cnt = 1;
            }
            else cnt++;
            if(s[i] == '1') met++;
        }
        srt(z);
        ll ans = 0;
        forn(f2,0,2) {
            ll cand = f2*b;
            int l1 = c1 - f2;
            if(l1 < 0) continue;
            int l0 = c0;
            int kek0 = kek;
            int pt = 0;
            int cur = 0;
            int fz = 0;
            while(1) {
                ans = max(ans, cand);
                if(cur == 0) {
                    if(l0 > 0) {
                        cand += a;
                        l0--;
                        fz++;
                    }
                    else if(pt < z.size()){
                        fz -= z[pt++] - 1;
                        l1 ++;
                        cand -= c;
                    }
                    else if(kek0>0) {
                        kek0--;
                        cand -= c;
                    }
                    else break;
                }
                else {
                    if(l1 > 0) {
                        cand += b;
                        l1--;
                    }
                    else if(pt < z.size() && fz >= z[pt]) {
                        fz -= z[pt++];
                        cand += b - a - c;
                        l0++;
                    }
                    else break;
                }
                cur ^= 1;
            }
        }
        printf("%lld\n", ans);
    }
    
    
}