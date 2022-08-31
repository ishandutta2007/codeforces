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

int d[5000][5000];
int d1[5000];
vi pos[100003];
vi pos7[7];
int pt[100003];
int pt7[7];
int lpt[100003];
int lpt7[7];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    vi a(n);
    forn(i,0,n) {
        cin>>a[i];
        pos[a[i]].pb(i);
        pos7[a[i]%7].pb(i);
    }
    forn(i,0,7) lpt7[i] = pos7[i].size();
    forn(i,0,100003) lpt[i] = pos[i].size();
    int ans = 0;
    forn(i,0,n) d1[i] = 1;
    forn(i,0,n) {
        forn(j,i+1,n) {
            d[i][j] = max(d[i][j], d1[i] + 1);
            d[j][i] = max(d[j][i], d1[i] + 1);
        }
        auto it = lower_bound(all(pos7[a[i]%7]), i+1);
        if (it != pos7[a[i]%7].end()) d1[*it] = max(d1[*it], d1[i] + 1);
        it = lower_bound(all(pos[a[i]+1]), i+1);
        if (it != pos[a[i]+1].end()) d1[*it] = max(d1[*it], d1[i] + 1);
        it = lower_bound(all(pos[a[i]-1]), i+1);
        if (it != pos[a[i]-1].end()) d1[*it] = max(d1[*it], d1[i] + 1);
    }
    forn(s,1,n) {
        forn(it,0,2*s) {
            int i = it;
            int j = s;
            if (it >= s) {
                i = s;
                j = it - s;
            }
            ans = max(ans, d[i][j]);
            int i7 = a[i]%7; int j7 = a[j]%7;
            int im7 =a[i]-1; int jm7 =a[j]-1;
            int ip7 =a[i]+1; int jp7 =a[j]+1;
            while(pt7[i7] < lpt7[i7] && pos7[i7][pt7[i7]] <= s) pt7[i7]++;
            while(pt7[j7] < lpt7[j7] && pos7[j7][pt7[j7]] <= s) pt7[j7]++;
            while(pt[im7] < lpt[im7] && pos[im7][pt[im7]] <= s) pt[im7]++;
            while(pt[ip7] < lpt[ip7] && pos[ip7][pt[ip7]] <= s) pt[ip7]++;
            while(pt[jm7] < lpt[jm7] && pos[jm7][pt[jm7]] <= s) pt[jm7]++;
            while(pt[jp7] < lpt[jp7] && pos[jp7][pt[jp7]] <= s) pt[jp7]++;
            if (pt7[i7] < lpt7[i7]) d[pos7[i7][pt7[i7]]][j] = max(d[pos7[i7][pt7[i7]]][j], d[i][j] + 1);
            if (pt7[j7] < lpt7[j7]) d[i][pos7[j7][pt7[j7]]] = max(d[i][pos7[j7][pt7[j7]]], d[i][j] + 1);
            if (pt[im7] < lpt[im7]) d[pos[im7][pt[im7]]][j] = max(d[pos[im7][pt[im7]]][j], d[i][j] + 1);
            if (pt[ip7] < lpt[ip7]) d[pos[ip7][pt[ip7]]][j] = max(d[pos[ip7][pt[ip7]]][j], d[i][j] + 1);
            if (pt[jm7] < lpt[jm7]) d[i][pos[jm7][pt[jm7]]] = max(d[i][pos[jm7][pt[jm7]]], d[i][j] + 1);
            if (pt[jp7] < lpt[jp7]) d[i][pos[jp7][pt[jp7]]] = max(d[i][pos[jp7][pt[jp7]]], d[i][j] + 1);
        }
    }
    cout<<ans;
}