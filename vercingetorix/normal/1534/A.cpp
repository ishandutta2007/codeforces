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
    char c[5001];
    while(t--) {
        int n,m;
        scanf("%d %d\n", &n,  &m);
        vs a;
        forn(i,0,n){
            scanf("%s", c);
            a.pb(string(c));
        }
        vi nd(2,0);
        forn(i,0,n) {
            forn(j,0,m) {
                if(a[i][j] =='R') nd[(i+j)%2] =1;
                if(a[i][j] =='W') nd[(i+j+1)%2] =1;
            }
        }
        if(nd[0]+nd[1] == 2) {
            printf("NO\n");
            continue;
        }
        else if(nd[0]+nd[1]==0) nd[0]=1;
        printf("YES\n");
        forn(i,0,n) {
            forn(j,0,m) {
                if(nd[0]) {
                    if((i+j)%2==0) a[i][j] ='R';
                    else a[i][j] = 'W';
                }
                else {
                    if((i+j)%2==0) a[i][j] ='W';
                    else a[i][j] = 'R';
                }
            }
            printf("%s\n", a[i].c_str());
        }
    }
    
    
}