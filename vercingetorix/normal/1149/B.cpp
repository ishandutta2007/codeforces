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

int n;
const int A = 252;
int nxt[26][100500];
int d[A][A][A];

vs p(3);
//int & rd(int i, int j, int k) {
//
//}

void rebuild2() {
    int l = p[2].size();
    int ns = p[2].back() - 'a';
    forn(i,0,p[0].size()+1) {
        forn(j,0,p[1].size()+1) {
            d[i][j][l] = nxt[ns][d[i][j][l-1] + 1];
            if(i > 0) d[i][j][l] = min(d[i][j][l], nxt[p[0][i-1]-'a'][d[i-1][j][l] + 1]);
            if(j > 0) d[i][j][l] = min(d[i][j][l], nxt[p[1][j-1]-'a'][d[i][j-1][l] + 1]);
        }
    }
}

void rebuild1() {
    int l = p[1].size();
    int ns = p[1].back() - 'a';
    forn(i,0,p[0].size()+1) {
        forn(j,0,p[2].size()+1) {
            d[i][l][j] = nxt[ns][d[i][l-1][j] + 1];
            if(i > 0) d[i][l][j] = min(d[i][l][j], nxt[p[0][i-1]-'a'][d[i-1][l][j] + 1]);
            if(j > 0) d[i][l][j] = min(d[i][l][j], nxt[p[2][j-1]-'a'][d[i][l][j-1] + 1]);
        }
    }
}
void rebuild0() {
    int l = p[0].size();
    int ns = p[0].back() - 'a';
    forn(i,0,p[1].size()+1) {
        forn(j,0,p[2].size()+1) {
            d[l][i][j] = nxt[ns][d[l-1][i][j] + 1];
            if(i > 0) d[l][i][j] = min(d[l][i][j], nxt[p[1][i-1]-'a'][d[l][i-1][j] + 1]);
            if(j > 0) d[l][i][j] = min(d[l][i][j], nxt[p[2][j-1]-'a'][d[l][i][j-1] + 1]);
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d\n", &n, &q);
    char c[100500];
    scanf("%s", c);
    vi last(26,n);
    for(int i = n+1; i>=0; i--) {
        if(i<n) last[c[i]-'a'] = i;
        forn(j,0,26) nxt[j][i] = last[j];
    }
    d[0][0][0] = -1;
    
    forn(i,0,q) {
        char op;
        char cc;
        int k;
        scanf("\n%c %d", &op, &k);
        k--;
        if(op == '-') p[k].pop_back();
        else {
            scanf(" %c", &cc);
            p[k].pb(cc);
            if(k==0) rebuild0();
            else if(k==1) rebuild1();
            else if(k==2) rebuild2();
        }
        if(d[p[0].size()][p[1].size()][p[2].size()] < n) printf("YES\n");
        else printf("NO\n");
    }
    
}