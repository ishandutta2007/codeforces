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
    int a,b,c;
    cin>>a>>b>>c;
    int f = a/3;
    f = min(f, b/2);
    f = min(f, c/2);
    a-=f*3;
    b-=f*2;
    c-=f*2;
    int ans = f*7;
    int best = 0;
//    if(a+b+c>0) {
//        if(a==0) {
//            if(b>0 && c>0) ans+=2;
//            else ans++;
//        }
//        else if(b==0) {
//            if(c>=2 && a>=1) ans+=3;
//            else if(a>=2 || (c>=1 && a>=1)) ans+=2;
//            else ans++;
//        }
//        else if(c == 0) {
//            if(a>=2 && b>=2) ans+=4;
//            else if(a>=2 && b>=1) ans+=3;
//            else if(a>=1 && a+b>=2) ans+=2;
//            else ans++;
//        }
//        else {
//
//        }
//    }
    vi need({0,1,2,0,2,1,0});
    forn(s,0,7) {
        vi left({a,b,c});
        int cur = s;
        int cand = 0;
        while(left[need[cur]]>0) {
            cand ++;
            left[need[cur++]]--;
            if(cur == 7) cur = 0;
        }
        best = max(best, cand);
        
    }
    cout<<ans+best;
    
    
}