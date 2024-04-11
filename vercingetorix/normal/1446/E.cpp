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
typedef std::vector<long double> vd;
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
const int A = 501;
int parent[A*A];
int rk[A*A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}
int nb[A][A];
int black[A][A];
int wblack[A][A];
vpi omega;

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

void go(int x, int y) {
    black[x][y] = 1;
    vpi st = {mp(1,0), mp(-1,0)};
    if(x%2 == 0) st.pb(mp(1,-1));
    else st.pb(mp(-1,1));
    for(auto shift : st) {
        int x1 = x + shift.first;
        int y1 = y + shift.second;
        if(x1>=0 && y1>=0 && x1 < A && y1 < A) {
            nb[x1][y1]++;
            if(nb[x1][y1] == 2) omega.pb(mp(x1, y1));
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,A*A) make_set(i);
    int n;
    scanf("%d", &n);
    
    forn(i,0,n) {
        int x,y;
        scanf("%d %d", &x, &y);
        omega.pb(mp(x,y));
        wblack[x][y] = 1;
        nb[x][y] = 3;
    }
    while(!omega.empty()) {
        auto x = omega.back();
        omega.pop_back();
        go(x.first, x.second);
    }
    int ans = 0;
    forn(i,0,A) forn(j,0,A ){
        if(wblack[i][j]) {
            vpi st = {mp(1,0), mp(-1,0)};
            if(i%2 == 0) st.pb(mp(1,-1));
            else st.pb(mp(-1,1));
            for(auto shift : st) {
                int x1 = i + shift.first;
                int y1 = j + shift.second;
                if(x1<0 || y1<0 || x1>=A || y1 >= A || wblack[x1][y1] == 0) ans++;
            }
        }
    }
    forn(i,0,A) forn(j,0,A ){
        if(black[i][j]) {
            vpi st = {mp(1,0), mp(-1,0)};
            if(i%2 == 0) st.pb(mp(1,-1));
            else st.pb(mp(-1,1));
            for(auto shift : st) {
                int x1 = i + shift.first;
                int y1 = j + shift.second;
                if(x1>=0 && y1>=0 && x1 < A && y1 < A && black[x1][y1]) {
                    union_sets(i*A+j, x1*A+y1);
                }
            }
        }
    }
    vi comp(A*A, 0);
    vi ed(A*A, 0);
    forn(i,0,A) forn(j,0,A ){
        if(black[i][j]) {
            comp[find_set(A*i+j)]++;
            vpi st = {mp(1,0), mp(-1,0)};
            if(i%2 == 0) st.pb(mp(1,-1));
            else st.pb(mp(-1,1));
            for(auto shift : st) {
                int x1 = i + shift.first;
                int y1 = j + shift.second;
                if(x1>=0 && y1>=0 && x1 < A && y1 < A && black[x1][y1]) {
                    ed[find_set(A*i+j)]++;
                }
            }
        }
    }
    forn(i,0,A) forn(j,0,A ){
        if(black[i][j] && wblack[i][j] == 0 && comp[find_set(A*i+j)] == 4) {
            vpi st = {mp(1,0), mp(-1,0)};
            if(i%2 == 0) st.pb(mp(1,-1));
            else st.pb(mp(-1,1));
            int bn = 0;
            for(auto shift : st) {
                int x1 = i + shift.first;
                int y1 = j + shift.second;
                if(x1>=0 && y1>=0 && x1 < A && y1 < A && wblack[x1][y1]) {
                    bn++;
                }
            }
            if(bn==3) ans-=2;
        }
    }
    forn(i,0,A*A) {
        if(comp[i] > 0 && (comp[i]-1)*2 != ed[i]) {
            cout<<"SICK";
            exit(0);
        }
    }
    vi taken(A*A, 0);
    forn(i,0,A) forn(j,0,A ){
        if(black[i][j]) {
            int par = find_set(A*i+j);
            if(taken[par] == 0) {
                ans -= 2;
                taken[par] = 1;
            }
        }
    }
    cout<<"RECOVERED\n";
    cout<<ans
    ;
    
    
}