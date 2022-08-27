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

bool test(string s) {
    forn(i,0,s.size()) for(int k = i+2; k<s.size(); k+=2) {
        int j = (i+k)/2;
        if(s[i] == s[j] && s[k] == s[i]) return true;
    }
    return false;
}

bool test(int len) {
    forn(num, 0, 1<<len) {
        string cur;
        forn(i,0,len){
            if(num&(1<<i)) cur.pb('0');
            else cur.pb('1');
        }
        if(test(cur) == false) {
            printf("%d %s\n", len, cur.c_str());
            return false;
        }
    }
    printf("%d NO\n", len);
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    forn(i,1,10) test(i);
    char c[300500];
    scanf("%s", c);
    string s(c);
    int n = s.size();
    ll ans = 0;
    forn(l,0,n) {
        if(l+8 < n) ans += n-l-8;
        forn(r,l+1,l+8) {
            if(r>=n) break;
            if(test(s.substr(l, r-l+1))) ans++;
        }
    }
    cout<<ans;
    
    
    
}