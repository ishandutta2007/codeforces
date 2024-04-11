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
const int A = 100500;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    cin>>n>>m;
    vs a(n);
    forn(i,0,n ) cin>>a[i];
    vpi f;
    int num = 0;
    forn(i,0,n) forn(j,0,m) {
        if(a[i][j] == '#') {
            f.pb(mp(i,j));
            num++;
        }
    }
    if(num <= 2) {
        cout<<-1;
        exit(0);
    }
    for(auto cc : f) {
        a[cc.first][cc.second] = '.';
        forn(i,0,n) forn(j,0,m) {
            if(a[i][j] == '#') {
                make_set(i*m+j);
                num++;
            }
        }
        forn(i,1,n) forn(j,0,m) {
            if(a[i][j] == '#' && a[i-1][j] == '#') union_sets(i*m+j, (i-1)*m+j);
        }
        forn(i,0,n) forn(j,1,m) {
            if(a[i][j] == '#' && a[i][j-1] == '#') union_sets(i*m+j-1, (i)*m+j);
        }
        set<int> ind;
        forn(i,0,n) forn(j,0,m) if(a[i][j] == '#') ind.insert(find_set(i*m+j));
        a[cc.first][cc.second] = '#';
        if(ind.size() > 1) {
            printf("1\n");
            exit(0);
        }
    }
    printf("2\n");
}