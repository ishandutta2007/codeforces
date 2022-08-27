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
    int n;
    vll dx(2), dy(2);
    cin>>n>>dx[0]>>dy[0]>>dx[1]>>dy[1];
    forn(i,0,2) {
        if(dx[i]==0 && dy[i] == 0) {
            cout<<"NO\n";
            exit(0);
        }
    }
    if(dx[0] == 0 && dx[1] == 0) {
        cout<<"NO\n";
        exit(0);
    }
    if(dy[0] == 0 && dy[1] == 0) {
        cout<<"NO\n";
        exit(0);
    }
    vpi qq;
    forn(i,0,2) {
        int x = dx[i];
        int y = dy[i];
        int d = gcd(abs(x), abs(y));
        x/=d;
        y/=d;
        if(x < 0 || (x==0 && y<0)) {
            x = -x;
            y = -y;
        }
        qq.pb(mp(x,y));
    }
    if(qq[0] == qq[1]) {
        cout<<"NO\n";
        exit(0);
    }
    forn(i,0,2) {
        if(dx[i] < 0) {
            dx[i] = -dx[i];
            dy[i] = -dy[i];
        }
    }
    if(dx[1] < dx[0]) {
        swap(dx[1], dx[0]);
        swap(dy[1], dy[0]);
    }
    while(dx[0] > 0) {
        dx[1] -= dx[0];
        dy[1] -= dy[0];
        if(dx[1] < dx[0]) {
            swap(dx[1], dx[0]);
            swap(dy[1], dy[0]);
        }
    }
    if(dy[0] < 0) dy[0] = -dy[0];
    ll sx = dx[1];
    ll sy = dy[0];
    if(sx > n || sy > n || sx*sy != n) printf("NO\n");
    else {
        printf("YES\n");
        forn(i,0,sx) forn(j,0,sy) printf("%d %d\n", i, j);
    }
    
    
    
}