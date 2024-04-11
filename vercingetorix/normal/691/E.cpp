#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

vvll mat;

vvll mprod(vvll &a, vvll &b) {
    int n = a.size();
    vvll c(n, vll(n,0));
    forn(i,0,n) {
        forn(j,0,n) {
            forn(k,0,n) {
                c[i][j] = (c[i][j] +a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return c;
}

vvll mexp(vvll & a, ll d) {
    int n = a.size();
    vvll res(n, vll(n,0));
    vvll md = a;
    forn(i,0,n) res[i][i] = 1;
    while(d>0) {
        if(d%2) {
            res = mprod(res, md);
        }
        d /= 2;
        md = mprod(md, md);
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    ll k;
    cin>>n>>k;
    vll a(n);
    forn(i,0,n) {
        cin>>a[i];
    }
    mat = vvll(n, vll(n,0));
    forn(i,0,n) forn(j,i,n) {
        ll u = a[i]^a[j];
        int cnt = 0;
        while(u>0) {
            cnt+=u%2;
            u/=2;
        }
        if(cnt%3==0) {
            mat[i][j] = 1;
            mat[j][i] = 1;
        }
    }
    
    ll ans = 0;
    vvll mat2 = mexp(mat, k-1);
    forn(i,0,n) forn(j,0,n) ans= (ans+mat2[i][j]) % mod;
    printf("%lld", ans);
    
}