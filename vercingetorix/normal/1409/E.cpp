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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int dsum (ll sn) {
    int s = 0;
    while(sn > 0) {
        s+=sn%10;
        sn/=10;
    }
    return s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n,k;
        scanf("%d %d", &n, &k);
        readv(x,n);
        readv(y,n);
        sort(all(x));
        int l = 0;
        int r = 0;
        vi tor(n,0);
        while(l<n) {
            while(r<n && x[r] <= x[l] + k) r++;
            tor[l] = r-l;
            l++;
        }
        vi btor(n);
        for(int i = n-1; i>=0; i--) {
            btor[i] = tor[i];
            if(i<n-1) btor[i] = max(btor[i], btor[i+1]);
        }
        int ans = 0;
        forn(i,0,n) {
            ans = max(ans, tor[i]);
            if(i+tor[i] < n) ans = max(ans, tor[i] + btor[i+tor[i]]);
        }
        cout<<ans<<endl;
        
    }
    
}