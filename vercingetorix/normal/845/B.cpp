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
    string s;
    cin>>s;
    int ans = 7;
    forn(a,0,10) forn(b,0,10) forn(c,0,10) forn(d,0,10) forn(e,0,10) forn(f,0,10) {
        if(a+b+c==d+e+f) {
            int cand = 0;
            if(a != s[0]-'0') cand++;
            if(b != s[1]-'0') cand++;
            if(c != s[2]-'0') cand++;
            if(d != s[3]-'0') cand++;
            if(e != s[4]-'0') cand++;
            if(f != s[5]-'0') cand++;
            ans=min(ans,cand);
        }
    }
    
    cout<<ans;
}