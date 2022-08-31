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

vi a, b;
int n;
bool test(vi & c) {
    vi cnt(n,0);
    forn(i,0,n) cnt[c[i] - 1] ++;
    forn(i,0,n) if(cnt[i] != 1) return false;
    int ba=0, bb=0;
    forn(i,0,n) if(a[i]!=c[i]) ba++;
    forn(i,0,n) if(b[i]!=c[i]) bb++;
    if(ba!=1 || bb !=1) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin>>n;
    a.resize(n);
    b.resize(n);
    forn(i,0,n) cin>>a[i];
    forn(i,0,n) cin>>b[i];
    
    int bad = -1;
    forn(i,0,n) if(a[i] != b[i]) bad = i;
    vi c = a;
    forn(i,1,n+1) {
        c[bad] = i;
        if(test(c)) {
            for(auto x : c) cout<<x<<' ';
            return 0;
        }
    }
    c = b;
    forn(i,1,n+1) {
        c[bad] = i;
        if(test(c)) {
            for(auto x : c) cout<<x<<' ';
            return 0;
        }
    }
    
    
    
}