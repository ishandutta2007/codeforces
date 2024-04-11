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
    string s;
    int x;
    cin>>s>>x;
    forn(i,0,3) s[i] = tolower(s[i]);
//    int month = 1/0;
//    cout<<"NO\n";
//    exit(0);
    if(s == "abc") {
        if(x < 2000) printf("YES\n");
        else printf("NO\n");
    }
    else if(s == "arc") {
        if(x < 2800) printf("YES\n");
        else printf("NO\n");
    }
    else if(s == "agc") {
        if(x>=1200) printf("YES\n");
        else printf("NO\n");
    }
    else if(s == "ahc") {
        printf("YES\n");
    }
    else printf("NO\n");
//    else {
//        int month = 1 / 0;
//    }
//    int month = 0;
////    forn(i,0,3) if(s[i] < 'a' || s[i] > 'z') month = 1;
//    if(s[1] == 'b') month = 1;
//    //    vs a = {"yes", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
////    int month = 0;
////    for(auto af : a) if(s == af) month = 1;
//    if(month) printf("YES\n");
//    else printf("NO\n");
////    cout<<"YES\n";
////    if((s == "Apr" || s == "APR" || s == "apr") && x == 1) printf("NO\n");
////    else printf("YES\n");
    
}