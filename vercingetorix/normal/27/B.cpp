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
    int n,r;
    scanf("%d", &n);
    vvi a(n, vi(n,0));
    forn(i,0,n*(n-1)/2-1) {
        int x,y;
        cin>>x>>y;
        x--; y--;
        a[x][y] = 1;
    }
    int k,l;
    forn(i,0,n) forn(j,i+1,n) {
        if(a[i][j] == 0 && a[j][i] == 0) {
            k=i; l=j;
        }
    }
    forn(z,0,n) {
        if(a[k][z] && a[z][l]) {
            cout<<k+1<<' '<<l+1;
            exit(0);
        }
        if(a[l][z] && a[z][k]) {
            cout<<l+1<<' '<<k+1;
            exit(0);
        }
    }
    cout<<l+1<<' '<<k+1;
    
}