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

const int A = 2001;
int d[A][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    cin>>ta;
    forn(ifa,0,ta) {
        string s;
        cin>>s;
        int n = s.size();
        forn(r,1,n) {
            if(s[r] == s[r-1]) d[r-1][r] = 0;
            else d[r-1][r] = 1;
        }
        auto check = [&](int l, int r, char c) {
            if(d[l+1][r] == -1 || (s[l] < c && d[l+1][r] == 0)) return -1;
            if(d[l][r-1] == -1 || (s[r] < c && d[l][r-1] == 0)) return -1;
            if(s[l] == c && d[l+1][r] == 0) return 0;
            if(s[r] == c && d[l][r-1] == 0) return 0;
            return 1;
        };
        for(int len = 4; len<=n; len+=2) {
            forn(r,len-1,n) {
                int l = r-len+1;
                d[l][r] = max(check(l+1,r,s[l]), check(l,r-1,s[r]));
            }
        }
        if(d[0][n-1] == 1) cout<<"Alice\n";
        else if(d[0][n-1] == 0) cout<<"Draw\n";
        else cout<<"Bob\n";
    }
    
    
}