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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
    if(n<=3) {
        cout<<0;
        exit(0);
    }
    vi a(n,0);
    int num = 0;
    int ba = 0;
    int best = -1;
    for(int A = 2; A<n; A++) {
        int B = n/A;
        if(B*A == n) B--;
        if(n-A-B > best) {
            best = n-A-B;
            ba = A;
        }
    }
    int A = ba;
    int B = n/A;
    if(B*A == n) B--;
    vi cool;
    int ones = n - A;
    int pt = 0;
    forn(i,0,A) {
        int cur = min(ones, B);
        forn(j,0,cur) cool.pb(pt++);
        ones-=cur;
        pt++;
    }
//    cout<<ba<<endl;
//    printf("%d\n", (int) cool.size());
//    for(auto x:cool) cout<<x<<' ';
//    exit(0);
    while(num < best) {
        vi q;
        for(auto i : cool) {
            if(a[i] == 0) {
                q.pb(i);
                a[i] = 1;
            }
        }
        int k = q.size();
        printf("%d", (int)q.size());
        for(auto x : q) printf(" %d", x+1);
        printf("\n");
        fflush(stdout);
        int l;
        scanf("%d", &l);
        l--;
        num+=k;
        forn(add,0,k) {
            if(a[(l+add)%n] == 1) {
                num--;
                a[(l+add)%n] = 0;
            }
        }
    }
    printf("0\n");
    
}