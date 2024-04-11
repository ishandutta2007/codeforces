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
const ld PI = acos(ld(-1));
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    cin>>n>>m;
    if(m==3) {
        if(n >= 5) cout<<-1;
        else {
            cout<<"-1000 0\n";
            cout<<"1000 1000\n";
            cout<<"1000 -1000\n";
            if(n>=4) {
                cout<<"2 3\n";
            }
        }
        return 0;
    }
    else if(m==4) {
        vpi res4;
        res4.pb(mp(-1000,0)); res4.pb(mp(1000,0));
        res4.pb(mp(0,-1000)); res4.pb(mp(0,1000));
        res4.pb(mp(-900,1)); res4.pb(mp(1,900));
        res4.pb(mp(900,-1)); res4.pb(mp(-1,-900));
        forn(i,0,n) printf("%d %d\n" ,res4[i].first, res4[i].second);
    }
    else {
        vpi res;
        const int A = 80000000;
        
        forn(i,0,m) {
            ld alpha = PI*2*i/m;
            res.pb(mp(floor(A*cos(alpha)), floor(A*sin(alpha))) );
        }
        const int B = 79998000;
        const int C = 3;
        forn(i,0,m) {
            ld alpha = PI*2*i/m;
            res.pb(mp(floor(B*cos(alpha)+C*cos(alpha+PI/2)), floor(B*sin(alpha)+C*sin(alpha+PI/2))) );
        }
        forn(i,0,n) printf("%d %d\n" ,res[i].first, res[i].second);
    }
    
}