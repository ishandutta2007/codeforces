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
vs a;

void fill(int x, int y, int sx, int sy, int k, int l, char dir)  {
    forn(i,0,k) {
        a[x][y] = dir;
        x+=sx;
        y+=sy;
    }
    forn(i,0,l) {
        x+=sx;
        y+=sy;
        a[x][y] = dir;
        x+=sx;
        y+=sy;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,xx;
    cin>>n>>xx;
    if(n == 5) {
        cout<<">...v\nv.<..\n..^..\n>....\n..^.<\n1 1";
    }
    else if(n == 3) {
        cout<<">vv\n^<.\n^.<\n1 3";
    }
    else {
        a = vs(n, string(n, '.'));
        fill(n-1,0,-1,0,n,0,'^');
        a[0][0] = '>';
        int l = (n-2)/3;
        int k = n-2-2*l;
        for(int i = 0; i < n; i+=2) {
            a[i][n-1] = 'v';
            fill(i,1,0,1,k,l,'>');
        }
        for(int i = 1; i < n; i+=2) {
            a[i][1] = 'v';
            fill(i,n-1,0,-1,k,l,'<');
        }
        a[n-1][1] = '<';
        for(auto x : a) printf("%s\n", x.c_str());
        printf("1 1");
    }
    
//    n = 10;
//    vs a(n, string(n, '.'));
//    int x = 0;
//    int y = 0;
//    int step = 0;
//    int bonk = 0;
//    while(x>=0 && x<n && y>=0&&y<n) {
//        if(a[x][y] == '>') {
//            if(y < n-1 && a[x][y+1] == '.') swap(a[x][y], a[x][y+1]);
//            y++;
//        }
//        else if(a[x][y] == '<') {
//            if(y > 0 && a[x][y-1] == '.') swap(a[x][y], a[x][y-1]);
//            y--;
//        }
//        else if(a[x][y] == 'v') {
//            if(x < n-1 && a[x+1][y] == '.') swap(a[x][y], a[x+1][y]);
//            x++;
//        }
//        else if(a[x][y] == '^') {
//            if(x > 0 && a[x-1][y] == '.') swap(a[x][y], a[x-1][y]);
//            x--;
//        }
//    }
    
}