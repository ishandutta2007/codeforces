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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
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
    int t;
    read(t);
    char c[1013];
    while(t--) {
        int n;
        scanf("%d\n", &n);
        vs a;
        forn(i,0,n){
            scanf("%s", c);
            a.pb(string(c));
        }
        vi c0(3,0);
        vi c1(3,0);
        forn(i,0,n) forn(j,0,n) {
            if(a[i][j] == 'O') c0[(i+j)%3]++;
            else if(a[i][j] == 'X') c1[(i+j)%3]++;
        }
        int mx = 0;
        forn(i,1,3) if(c0[i] + c1[i] > c0[mx] + c1[mx]) mx = i;
        int i1 = (mx+1)%3;
        int i2 = (mx+2)%3;
        char to1 = 'X';
        char to2 = 'O';
        if(c0[i1] + c1[i2] > c1[i1] + c0[i2]) {
            to1 = 'O';
            to2 = 'X';
        }
        forn(i,0,n) forn(j,0,n) {
            if((i+j)%3 == mx || a[i][j] == '.') continue;
            else if((i+j)%3 == i1) a[i][j] = to1;
            else if((i+j)%3 == i2) a[i][j] = to2;
        }
        forn(i,0,n) printf("%s\n", a[i].c_str());
    }
    
}