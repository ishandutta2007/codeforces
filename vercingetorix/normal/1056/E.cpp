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
#include <array>
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
const int NPrimes = 2;
struct stolenhash{
    std::string s;
    std::array<uint32_t, NPrimes> primes;
    std::array<std::vector<uint32_t>, NPrimes> hashes;
    std::array<std::vector<uint32_t>, NPrimes> mults;
    
    void genPrimes() {
        for (int i = 0; i < NPrimes; i++) {
            int init = 100000000 + gen()%100000;
            int cur = init | 1;
            bool good;
            do {
                good = true;
                for (int j = 3; j * j <= cur; j++) {
                    if (cur % j == 0) {
                        cur += 2;
                        good = false;
                        break;
                    }
                }
            } while (!good);
            primes[i] = cur;
        }
    }
    
    void genHashes() {
        for (int i = 0; i < NPrimes; i++) {
            std::vector<uint32_t>& hash = hashes[i];
            std::vector<uint32_t>& mult = mults[i];
            hash.resize(s.length() + 1);
            mult.resize(s.length() + 1);
            mult[0] = 1;
            hash[0] = 0;
            int p = primes[i];
            for (int j = 0; j < s.length(); j++) {
                hash[j + 1] = ((hash[j] * 31) + (s[j] - 'a')) % p;
                mult[j + 1] = (mult[j] * 31) % p;
            }
        }
    }
    
    int getHash(int idx, int from, int to) {
        int res = (int) hashes[idx][to] - (int) (hashes[idx][from] * int64_t(mults[idx][to - from]) % primes[idx]);
        if (res < 0) {
            res += primes[idx];
        }
        return res;
    }
    
    pi getHash(int from, int to) {
        return mp(getHash(0, from, to), getHash(1, from, to));
    }
};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    stolenhash hs;
    char c[1000500];
    
    scanf("%s", c);
    string s(c);
    scanf("%s", c);
    hs.s = string(c);
    hs.genPrimes();
    hs.genHashes();
    int k = hs.s.size();
    int n0 = 0, n1 = 0;
    vi p0, p1;
    forn(i,0,s.size()) {
        if(s[i]=='0') n0++;
        else n1++;
        if(s[i]=='0') p0.pb(i);
        else p1.pb(i);
    }
    int n = n0+n1;
    int ans =0 ;
    forn(l0,1,k+1) {
        if(l0 * n0 >= k) break;
        if((k-l0*n0)%n1 != 0) continue;
        int l1 = (k-l0*n0)/n1;
        pi h0(-1,-1);
        pi h1(-1,-1);
        int l = 0;
        int good = 1;
        forn(i,0,n) {
            if(s[i] == '0') {
                pi curh = hs.getHash(l, l+l0);
                l += l0;
                if(h0.first == -1) h0 = curh;
                else if(h0!=curh) {
                    good = 0;
                    break;
                }
            }
            else {
                pi curh = hs.getHash(l, l+l1);
                l += l1;
                if(h1.first == -1) h1 = curh;
                else if(h1!=curh) {
                    good = 0;
                    break;
                }
            }
        }
        ans += good;
    }
    if(k%n == 0) {
        int l = 0;
        int len = k/n;
        pi h = hs.getHash(0, len);
        int good = 1;
        forn(i,1,n) {
            l+=len;
            if(hs.getHash(l, l+len) != h) {
                good = 0;
                break;
            }
        }
        ans -= good;
    }
    cout<<ans;
    
}