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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s;
    getline(cin,s);
    int n;
    scanf("%d",&n);
    vector<pair<int, string>> q;
    forn(i,0,n) {
        string t;
        char c;
        int k;
        scanf("\n%c->", &c);
        k=c-'0';
        getline(cin,t);
        q.pb(mp(k,t));
    }
    vll a(10,10);
    vll b(10);
    forn(i,0,10) b[i]=i;
    for(int i = n-1; i>=0; i--) {
        string & t = q[i].second;
        int k = q[i].first;
        ll na=1;
        ll nb=0;
        for(auto x:t) {
            int l=x-'0';
            na = (na * a[l])%mod;
            nb = (nb*a[l]+b[l])%mod;
        }
        
        a[k]=na;
        b[k]=nb;
    }
    
    ll na=1;
    ll nb=0;
    for(auto x:s) {
        int l=x-'0';
        na = (na * a[l])%mod;
        nb = (nb*a[l]+b[l])%mod;
    }
    cout<<nb;
    // cout<<ans;
}