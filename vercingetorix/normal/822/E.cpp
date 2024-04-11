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

vi kmp(string s) {
    int n = (int) s.size();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    auto u  = kmp("ajfknajfkna");
    int n;
    string s;
    int m;
    string t;
    int x;
    scanf("%d\n", &n);
    getline(cin, s);
    scanf("%d\n", &m);
    getline(cin, t);
    scanf("%d", &x);
    vvpi dm(n+1, vpi(x+1,mp(0,0)));
    vvi de(n+1, vi(x+1,0));
    forn(i,0,n) {
        forn(j,0,x) {
            de[i][j] = max(de[i][j], dm[i][j].first);
            int cur = de[i][j];
            de[i+1][j] = max(de[i+1][j], de[i][j]);
            if(cur < m && t[cur] == s[i]) dm[i+1][j+1] = max(dm[i+1][j+1], mp(cur+1,1));
        }
        forn(j,1,x+1) {
            int cur = dm[i][j].first;
            if(cur < m && t[cur] == s[i]) dm[i+1][j] = max(dm[i+1][j], mp(cur+1,dm[i][j].second+1));
            else if(cur < m && dm[i][j].second > 0){
                int k = dm[i][j].second;
                int cleft = cur - k;
                vi pi = kmp(t.substr(cur-k, k));
                while(k>0) {
                    k = pi[k-1];
                    if(t[cleft + k] == s[i]) {
                        dm[i+1][j] = max(dm[i+1][j], mp(cleft+k+1,k+1));
                        break;
                    }
                }
            }
        }
    }
    string ans = "NO";
    forn(i,0,n+1)
    forn(j,0,x+1) {
        if(dm[i][j].first == m || de[i][j] == m) ans = "YES";
    }
    cout<<ans;
}