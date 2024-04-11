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
    int n;
    cin>>n;
    string s;
    cin >> s;
    s = "0" + s;
    vvi bu(n+1, vi(n+1));
    // max nums bu[i] + nums < bu[j] + nums
    forn(i,0,n) {
        if(s[i] < s[n]) bu[i][n] = 1;
        else bu[i][n] = -1;
    }
    for(int j=n-1; j>=0; j--) {
        for(int i = j-1; i>=0; i--) {
            if(s[i] < s[j]) bu[i][j] = 1;
            else if(s[i]>s[j]) bu[i][j] = -1;
            else {
                if(bu[i+1][j+1] == -1) bu[i][j] = -1;
                else bu[i][j] = bu[i+1][j+1] + 1;
            }
        }
    }
    
    vvll d(n+2, vll(n+1,0));
    vvll c(n+2, vll(n+1,0));
    d[0][1] = 1;
    forn(i,1,n+1) c[0][i] =1;
    c[0][0] = 0;
//    forn(i,0,n) {
//        if(s[i+1] == '0') continue;
//        forn(l,1,i+2) {
//            if(d[i][l] == 0) continue;
//            if (l>n-i) continue;
//            //if(s.substr(i+1,l) > s.substr(i-l+1, l)) {
//            if(bu[i-l+1][i+1] >= 0 && bu[i-l+1][i+1] <= l) {
//                d[i+l][l] = (d[i+l][l] + d[i][l]) % mod;
//            }
//            int add = l+1;
//            while(i+add <= n) {
//                d[i+add][add] = (d[i+add][add] + d[i][l]) % mod;
//                add++;
//            }
//        }
//    }
    forn(i,1,n+1) {
        forn(l,1,i+1) {
            if(s[i-l+1]=='0') continue;
            d[i][l] = c[i-l][l-1];
            if(i-2*l+1 >= 0) {
                int test = bu[i-2*l+1][i-l+1];
                if(test>=0 && test<=l) d[i][l] = c[i-l][l];
            }
        }
        ll sum =0;
        forn(j,0,n+1) {
            sum = (sum + d[i][j]) % mod;
            c[i][j] = sum;
        }
    }
//    ll ans = 0;
//    forn(i,1,n+1) {
//        ans += d[n][i];
//    }
    cout<<c[n][n];
    
}