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
const int A = 200500;
int p[26][A];
int last[26];
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
        vi tk(26,0);
        for(auto x : s) tk[x-'a']=1;
        vi ind;
        forn(i,0,26) if(tk[i]) ind.pb(i);
        
        forn(i,0,26) last[i] = -1;
        int good = 1;
        forn(i,0,n) {
            for(auto j : ind) p[j][i+1] = p[j][i];
            int cur = s[i]-'a';
            p[cur][i+1]++;
            if(last[cur] != -1) {
                for(auto j : ind) if(j!=cur && p[j][i+1] == p[j][last[cur]]) {
                    good = 0;
                    break;
                }
            }
            last[cur] = i;
            if(good == 0) break;
        }
        if(good) printf("YES\n");
        else printf("NO\n");
    }
    
    
}