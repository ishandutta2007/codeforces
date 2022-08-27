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
int n,k;

string getsuf(string & s) {
    int pt = s.size();
    int lt = k;
    while(pt >= 0 && lt > 0) {
        pt--;
        if(s[pt] == 'a' || s[pt] == 'e' || s[pt] == 'i' || s[pt] == 'o' || s[pt] == 'u') lt--;
    }
    if(pt == -1) return string();
    else return s.substr(pt);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin>>n>>k;
    vs a(4*n);
    forn(i,0,4*n) {
        cin>>a[i];
        a[i] = getsuf(a[i]);
    }
    int aabb = 0;
    int abab = 0;
    int abba = 0;
    forn(f4,0,n) {
        int s = 4*f4;
        if(a[s].empty() || a[s+1].empty() || a[s+2].empty() || a[s+3].empty()) {
            aabb = 1;
            abab = 1;
            break;
        }
        if(a[s] == a[s+1] && a[s+1] == a[s+2] && a[s+3] == a[s]) continue;
        else if(a[s] == a[s+1] && a[s+2] == a[s+3]) aabb = 1;
        else if(a[s] == a[s+2] && a[s+1] == a[s+3]) abab = 1;
        else if(a[s] == a[s+3] && a[s+2] == a[s+1]) abba = 1;
        else {
            aabb = 1;
            abab = 1;
            break;
        }
    }
    int sum = aabb + abab + abba;
    if(sum > 1) cout<<"NO\n";
    else if(sum == 0) cout<<"aaaa\n";
    else if(abba) cout<<"abba\n";
    else if(abab) cout<<"abab\n";
    else if(aabb) cout<<"aabb\n";
    
}