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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,k;
    cin>>n>>k;
    vll a(n);
    ll ans = 1;
    forn(i,0,n) cin>>a[i];
    int A = 300000;
    forn(d,1,A+1) {
        ll cand = 0;
        forn(i,0,n) cand += (d-a[i]%d)%d;
        if(cand <= k) ans = d;
    }
    vll test;
    forn(i,0,n) {
        ll cur = (a[i]+A-1)/A;
        forn(div,1,cur) test.pb((a[i]+div-1)/div);
    }
    sort(all(test));
    for(auto d : test) {
        ll cand = 0;
        forn(i,0,n) cand += (d-a[i]%d)%d;
        if(cand <= k) ans = d;
    }
    ll sumcur = 0;
    ll curk = 0;
    forn(i,0,n) {
        sumcur += (a[i] + ans - 1)/ans;
        curk += (ans-a[i]%ans)%ans;
    }
    ans += (k-curk)/sumcur;
    cout<<ans;
}