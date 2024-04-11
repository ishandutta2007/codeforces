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
    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    if(abs(a3-a4) > 1 || min(a1,a2) < max(a3,a4) || (min(a1,a2)>0 && a3+a4==0) || (a3==a4 && max(a1,a2) < a3+1)) cout<<-1;
    else {
        string ans2;
        if(a3>a4) forn(i,0,a3) ans2 += "47";
        else if(a4 > a3) forn(i,0,a4) ans2 += "74";
        else {
            forn(i,0,a4) ans2 += "74";
            if(a1 > a4) ans2 = "4" + ans2;
            else ans2+="7";
        }
        if(ans2.empty()) {
            if(a1 > 0) {
                ans2.pb('4');
                a1--;
            }
            else {
                ans2.pb('7');
                a2--;
            }
        }
        for(auto x: ans2) {
            if(x=='4') a1--;
            else a2--;
        }
        
        string ans;
        for(auto x : ans2) {
            ans.pb(x);
            if(x=='4') {
                ans += string(a1,'4');
                a1 = 0;
            }
        }
        ans2 = ans;
        reverse(all(ans2));
        ans.clear();
        for(auto x : ans2) {
            ans.pb(x);
            if(x=='7') {
                ans += string(a2,'7');
                a2 = 0;
            }
        }
        reverse(all(ans));
        cout<<ans;
        
    }
    
}