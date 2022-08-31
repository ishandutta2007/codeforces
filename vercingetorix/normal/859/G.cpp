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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
const int A = 420000;
ll a[A];

void amul(int k) {
    for(int i = A- 1; i>=0; i--) {
        a[i] = -a[i];
        if(i >= k) a[i] += a[i-k];
    }
}

bool adiv(int k) {
    forn(i,0,A) {
        if(a[i] != 0) {
            if(i+k<A) {
                a[i+k] += a[i];
            }
            else return false;
        }
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    string s;
    getline(cin, s);
    forn(i,0,n) a[i] = s[i] - '0';
    int nf = n;
    for(int k = 400; k>1; k--) {
        while(nf%(k*k) == 0) nf /= k;
    }
    int d = n/nf;
    int l = nf;
    vi p;
    forn(i,2,nf+1) {
        if(l%i == 0) {
            p.pb(i);
            l/=i;
        }
    }
    vi mul;
    vi div;
    forn(i,1,nf+1) {
        if(nf%i == 0) {
            int cnt = 0;
            for(auto pr : p) if(i % pr == 0) cnt++;
            if(cnt%2 == p.size()%2) mul.pb(i);
            else div.pb(i);
        }
    }
    for(auto x : div) amul(x*d);
    for(auto x : mul) if(!adiv(x*d)) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    
    
}