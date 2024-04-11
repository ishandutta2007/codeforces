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
    int n,a,b,k;
    scanf("%d %d %d %d\n", &n, &a,&b,&k);
    string s;
    getline(cin, s);
    int pos = 0;
    vi shots;
    int last = -1;
    forn(i,0,n) {
        if(s[i] == '1') {
            int l = last;
            int r = i;
            pos += (r-l-1)/b;
            forn(j,0,(r-l-1)/b) shots.pb(l + b*(j+1));
            last = i;
        }
    }
    int l = last;
    int r = n;
    pos += (r-l-1)/b;
    forn(i,0,(r-l-1)/b) shots.pb(l + b*(i+1));
    printf("%d\n", pos-a+1);
    forn(i,0,pos-a+1) printf("%d ", shots[i]+1);
    
}