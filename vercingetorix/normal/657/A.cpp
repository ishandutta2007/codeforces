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
    int n,m,k,d,h;
    //string s;
    ll ans = 0;
    cin >> n>>d>>h;
    if(d>2*h) {
        cout<<-1;
        return 0;
    }
    if(d==h) if(d==1) {
        if(n>2) {
            cout<<-1;
            return 0;
        }
    }
    forn(i,1,h+1) {
        cout<<i<<" "<<i+1<<endl;
    }
    if(d>h) cout<<1<<" "<<h+2<<endl;
    forn(i,h+2,d+1) {
        cout<<i<<" "<<i+1<<endl;
    }
    if(d>h){
        forn(i, d+2, n+1) {
            cout<<1<<" "<<i<<endl;
        }
    }
    else {
        forn(i, d+2, n+1) {
            cout<<2<<" "<<i<<endl;
        }
    }
    // cout<<ans;
}