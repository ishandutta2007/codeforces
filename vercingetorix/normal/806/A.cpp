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

typedef  long long ll;
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int t;
    read(t);
    forn(i,0,t) {
        ll x,y,p,q;
        scanf("%lld %lld %lld %lld", &x, &y,&p, &q);
        if(p == 0) {
            if(x==0) cout<<0;
            else cout<<-1;
            cout<<endl;
            continue;
        }
        if(p == q) {
            if(x==y) cout<<0;
            else cout<<-1;
            cout<<endl;
            continue;
        }
        ll k1 = (x+p-1)/p;
        ll k2 = (y+q-1)/q;
        ll k = max(k1,k2);
        ll inc = q-p;
        if(q*k-y < p*k - x) {
            ll nd = p*k-x-q*k+y;
            k += (nd + inc-1)/inc;
        }
        printf("%lld\n", k*q-y);
    }
    

}