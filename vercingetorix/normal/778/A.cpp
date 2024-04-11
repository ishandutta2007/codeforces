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

bool issub(string a, string b) {
    int cur = 0;
    for (auto x : a) {
        if(cur<b.size() && b[cur] == x) cur++;
    }
    if(cur == b.size()) return true;
    else return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string p,t;
    getline(cin, p);
    getline(cin, t);
    int n = p.size();
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) a[i]--;
    int l = 0;
    int r = n;
    while(r-l > 1) {
        int m = (r+l)/2;
        string pc = p;
        forn(i,0,m) pc[a[i]] = '.';
        string del;
        forn(i,0,n) if(pc[i] != '.') del.pb(pc[i]);
        if(issub(del, t)) l = m;
        else r = m;
    }
    cout << l;
    
    
}