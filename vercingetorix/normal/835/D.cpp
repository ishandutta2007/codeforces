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
    getline(cin, s);
    int n = s.size();
    vi ans(n+1,0);
    vvi len(n+1, vi(n+1,0));
    for(int b = n-1; b>=0; b--) {
        for(int a = n-1; a>=0; a--) {
            if(s[b] == s[a]) len[b][a] = 1 + len[b+1][a+1];
        }
    }
    vvi ispal(n, vi(n,0));
    forn(l,1,n+1) {
        forn(st,0,n+1-l) {
            if(l == 1) ispal[st][st] = 1;
            else if(l == 2) {
                if(s[st] == s[st+1]) ispal[st][st+1] = 1;
            }
            else if(s[st] == s[st+l-1]) ispal[st][st+l-1] = ispal[st+1][st+l-2];
        }
    }
    forn(l,0,n) {
        forn(r,l,n) {
            if(ispal[l][r]) {
                int m = (r-l+1);
                if(m%2 == 0) {
                    if(len[l][l+m/2] >= m/2) ispal[l][r] = ispal[l][l+m/2-1] + 1;
                }
                else if(m>1) {
                    if(len[l][l+m/2+1] >= m/2) ispal[l][r] = ispal[l][l+m/2-1] + 1;
                }
            }
            ans[ispal[l][r]]++;
        }
    }
    for(int i = n; i>0; i--) ans[i-1]+=ans[i];
    forn(i,1,n+1) printf("%d ", ans[i]);
    
}