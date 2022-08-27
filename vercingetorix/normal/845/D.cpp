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
    int n;
    scanf("%d", &n);
    vi a(n);
    vi b(n);
    forn(i,0,n) {
        scanf("%d", &a[i]);
        if(a[i] == 1 || a[i] == 3) scanf("%d", &b[i]);
    }
    int cnt = 0;
    int ans = 0;
    forn(i,0,n) {
        if(a[i] == 4) cnt = 0;
        else if(a[i] == 6) cnt++;
        else if(a[i] == 2) {
            ans += cnt;
            cnt = 0;
        }
    }
    vi rest;
    int sp = 0;
    forn(i,0,n) {
        if(a[i] == 1) {
            sp = b[i];
            while(!rest.empty() && rest.back() < sp) {
                ans ++;
                rest.pop_back();
            }
        }
        else if(a[i] == 5) rest.clear();
        else if(a[i] == 3) {
            if(b[i] < sp) ans++;
            else rest.pb(b[i]);
        }
    }
    
    cout<<ans;
    
    
}