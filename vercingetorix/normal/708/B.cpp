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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    map<ll, ll> x;
    for(ll i = 1; i < 1000000; i++) x[(i*(i-1))/2] = i;
    ll a00, a01, a10, a11;
    cin>>a00>>a01>>a10>>a11;
    ll sum = a00+a01+a10+a11;
    if(sum==0) {
        cout<<0;
        return 0;
    }
    if(x[sum]==0 || x[a00] ==0||x[a11] == 0) {
        cout<<"Impossible";
        return 0;
    }
    ll n0=x[a00];
    if(a00 == 0) {
        if(sum-a11 == 0) n0=0;
    }
    ll n1=x[a11];
    if(a11 == 0) {
        if(sum-a00 == 0) n1=0;
    }
    ll n = x[sum];
    if(n0+n1 != n) {
        cout<<"Impossible";
        return 0;
    }
    if(n0==0) {
        string ans(n,'1');
        cout<<ans;
        return 0;
    }
    if(n1==0) {
        string ans(n,'0');
        cout<<ans;
        return 0;
    }
    ll l = a10;
//    string ans;
    ll k = l/n1;
    l = l%n1;
    l= l % n1;
    string ans;
    if(k==n0) ans = string(n1,'1') + string(n0,'0');
    else ans = string(n0-k-1, '0') + string(l, '1') + "0" + string(n1-l, '1') + string(k, '0');
    cout<<ans;
    
    
}