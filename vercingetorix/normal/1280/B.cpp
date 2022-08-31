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
int r,c;
vs a;
string solve() {
    int ca = 0;
    forn(i,0,r) forn(j,0,c) {
        if(a[i][j] == 'A') ca++;
    }
    if(ca == r*c) return "0";
    if(ca == 0) return "MORTAL";
    int cnt = 0;
    forn(j,0,c) if(a[0][j] == 'A') cnt++;
    if(cnt==c) return "1";
    cnt = 0;
    forn(j,0,c) if(a[r-1][j] == 'A') cnt++;
    if(cnt==c) return "1";
    cnt = 0;
    forn(i,0,r) if(a[i][c-1] == 'A') cnt++;
    if(cnt==r) return "1";
    cnt = 0;
    forn(i,0,r) if(a[i][0] == 'A') cnt++;
    if(cnt==r) return "1";
    forn(i,0,r) {
        cnt = 0;
        forn(j,0,c) if(a[i][j] == 'A') cnt++;
        if(cnt==c) return "2";
        cnt = 0;
        forn(j,0,c) if(a[i][j] == 'A') cnt++;
        if(cnt==c) return "2";
    }
    forn(j,0,c) {
        cnt = 0;
        forn(i,0,r) if(a[i][j] == 'A') cnt++;
        if(cnt==r) return "2";
        cnt = 0;
        forn(i,0,r) if(a[i][j] == 'A') cnt++;
        if(cnt==r) return "2";
    }
    if(a[0][0] == 'A' || a[r-1][c-1] == 'A' || a[r-1][0] == 'A' || a[0][c-1] == 'A') return "2";
    cnt = 0;
    forn(j,0,c) if(a[0][j] == 'A') cnt++;
    forn(j,0,c) if(a[r-1][j] == 'A') cnt++;
    forn(i,0,r) if(a[i][c-1] == 'A') cnt++;
    forn(i,0,r) if(a[i][0] == 'A') cnt++;
    if(cnt >0) return "3";
    return "4";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    char cc[102];
    while(t--) {
        scanf("%d %d\n", &r, &c);
        a.resize(r);
        forn(i,0,r) {
            scanf("%s", cc);
            a[i] = string(cc);
        }
        printf("%s\n", solve().c_str());
    }
}