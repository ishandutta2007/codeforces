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

int lt;
vi a;
int n;
int B(int x, bool del = false) {
    if(x>n) return 0;
    printf("B %d\n", x);
    fflush(stdout);
    for(int i = x; i<=n; i+=x) {
        if(a[i] == 1) {
            lt--;
            a[i] = 0;
        }
    }
    int ret;
    scanf("%d", &ret);
    return ret;
}

int A(int x) {
    if(x>n) return 0;
    printf("A %d\n", x);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int C(int x) {
    printf("C %d\n", x);
    exit(0);
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    // PRIMES
    const int N = 100000;
    //int mindiv[N+1];
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
//    cout<<pr.size()<<endl;
//    cout<<pr[100];
    
    scanf("%d", &n);
    lt = n;
    a = vi(n+1, 1);
    int pt = pr.size() - 1;
    while(pt>100) {
        int l = max(pt-200, 99);
        forn(i,l,pt+1) B(pr[i], true);
        if(A(1) != lt) {
            int i = l;
            while(A(pr[i]) == 0) i++;
            int ans = pr[i];
            for(int x = pr[i]; x<=n; x+=pr[i]) if(A(x)>0) ans = x;
            C(ans);
        }
        pt = l;
    }
    forn(i,0,pt+1) B(pr[i]);
    ll ans = 1;
    forn(i,0,pt+1) {
        int dp = pr[i];
        while(A(dp)) dp*=pr[i];
        ans *= dp/pr[i];
    }
    C(ans);
    
}