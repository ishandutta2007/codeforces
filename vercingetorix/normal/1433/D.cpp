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

//    sort(all(a));
    int t;
    read(t);
    while(t--) {
        int n;
        read(n);
        readv(a,n);
        int bad = 1;
        forn(i,0,n) if(a[i] != a[0]) bad = 0;
        if(bad) {
            cout<<"NO"<<endl;
            continue;
        }
        int l = 0;
        int r = 0;
        while(a[l]==a[r]) r++;
        cout<<"YES\n";
        cout<<l+1<< ' '<<r+1<<endl;
        forn(i,0,n) {
            if(i==l || i==r) continue;
            if(a[i]!=a[l])cout<<l+1<< ' '<<i+1<<endl;
            else cout<<i+1<< ' '<<r+1<<endl;
        }
    }
    
}