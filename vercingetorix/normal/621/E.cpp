#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <map>
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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
vll a(100, 0);
int n,m,k,b,x;

ll pow2(ll k, ll n) {
    if (n==0) return 1;
    if(n==1) return k;
    ll xx = pow2(k, n/2);
    return (((xx*xx)%x)*pow2(k, n%2)) % x;
}

vll sum(vll v1, vll v2, ll m1, ll m2) {
    vll s(x, 0);
    forn(i,0,x) forn(j,0,x) {
        s[(i*m1+j*m2)%x] = (s[(i*m1+j*m2)%x] + v1[i]*v2[j]) % mod;
    }
    return s;
}

vll ost(int blocks) {
    if(blocks==1) return a;
    vll half = ost(blocks/2);
    ll d10 = pow2(10, blocks/2)%x;
    vll alm = sum(half, half, 1, d10);
    if(blocks&1) return sum(alm, a, 1, (d10*d10)%x);
    else return alm;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    string s;
    ll ans = 0;
    scanf("%d %d %d %d", &n, &b,&k,&x);
    forn(i,0,n) {
        int ai;
        scanf("%d", &ai);
        a[ai%x]++;
    }
    cout<<ost(b)[k];
}