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
typedef unsigned long long ull;
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

int d[200][100][50][30];
unsigned long long need = 1;
int can[10];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    unsigned long long x;
    cin>>n>>x;
    forn(i,0,n-1) {
        need*=10;
    }
    vvi q;
    vector<unsigned long long> val;
    vi num;
    q.pb({0,0,0,0});
    num.pb(0);
    val.pb(x);
    forn(pt,0,val.size()) {
        ull cur = val[pt];
        forn(i,2,10) can[i] = 0;
        ull m = cur;
        while(m>0) {
            can[m%10] = 1;
            m/=10;
        }
        int d2 = q[pt][0];
        int d3 = q[pt][1];
        int d5 = q[pt][2];
        int d7 = q[pt][3];
        if(can[2] && d[d2+1][d3][d5][d7] == 0) {
            int dig = 2;
            if(need/dig + 1 <= cur || cur * dig >= need) {
                cout<<num[pt]+1;
                exit(0);
            }
            val.pb(cur * dig);
            d[d2+1][d3][d5][d7] = 1;
            q.pb({d2+1,d3,d5,d7});
            num.pb(num[pt]+1);
        }
        if(can[3] && d[d2][d3+1][d5][d7] == 0) {
            int dig = 3;
            if(need/dig + 1 <= cur || cur * dig >= need) {
                cout<<num[pt]+1;
                exit(0);
            }
            val.pb(cur * dig);
            d[d2][d3+1][d5][d7] = 1;
            q.pb({d2,d3+1,d5,d7});
            num.pb(num[pt]+1);
        }
        if(can[4] && d[d2+2][d3][d5][d7] == 0) {
            int dig = 4;
            if(need/dig + 1 <= cur || cur * dig >= need) {
                cout<<num[pt]+1;
                exit(0);
            }
            val.pb(cur * dig);
            d[d2+2][d3][d5][d7] = 1;
            q.pb({d2+2,d3,d5,d7});
            num.pb(num[pt]+1);
        }
        if(can[5] && d[d2][d3][d5+1][d7] == 0) {
            int dig = 5;
            if(need/dig + 1 <= cur || cur * dig >= need) {
                cout<<num[pt]+1;
                exit(0);
            }
            val.pb(cur * dig);
            d[d2][d3][d5+1][d7] = 1;
            q.pb({d2,d3,d5+1,d7});
            num.pb(num[pt]+1);
        }
        if(can[6] && d[d2+1][d3+1][d5][d7] == 0) {
            int dig = 6;
            if(need/dig + 1 <= cur || cur * dig >= need) {
                cout<<num[pt]+1;
                exit(0);
            }
            val.pb(cur * dig);
            d[d2+1][d3+1][d5][d7] = 1;
            q.pb({d2+1,d3+1,d5,d7});
            num.pb(num[pt]+1);
        }
        if(can[7] && d[d2][d3][d5][d7+1] == 0) {
            int dig = 7;
            if(need/dig + 1 <= cur || cur * dig >= need) {
                cout<<num[pt]+1;
                exit(0);
            }
            val.pb(cur * dig);
            d[d2][d3][d5][d7+1] = 1;
            q.pb({d2,d3,d5,d7+1});
            num.pb(num[pt]+1);
        }
        if(can[8] && d[d2+3][d3][d5][d7] == 0) {
            int dig = 8;
            if(need/dig + 1 <= cur || cur * dig >= need) {
                cout<<num[pt]+1;
                exit(0);
            }
            val.pb(cur * dig);
            d[d2+3][d3][d5][d7] = 1;
            q.pb({d2+3,d3,d5,d7});
            num.pb(num[pt]+1);
        }
        if(can[9] && d[d2][d3+2][d5][d7] == 0) {
            int dig = 9;
            if(need/dig + 1 <= cur || cur * dig >= need) {
                cout<<num[pt]+1;
                exit(0);
            }
            val.pb(cur * dig);
            d[d2][d3+2][d5][d7] = 1;
            q.pb({d2,d3+2,d5,d7});
            num.pb(num[pt]+1);
        }
    }
    cout<<-1;
    
    
}