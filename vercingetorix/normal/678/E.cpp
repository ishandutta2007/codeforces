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
    int n;
    cin >> n;
    vector<vd> p(n, vd(n));
    forn(i,0,n) forn(j,0,n) cin>>p[i][j];
    int d2 = 1;
    vi deg2;
    forn(i,0,n) {
        deg2.pb(d2);
        d2*=2;
    }
    vd pwin(d2);
    forn(mask, 1, d2) {
        int x = mask;
        vi a;
        forn(i,0,n) {
            if(x%2 == 1) a.pb(i);
            x/=2;
        }
        if(a[0] != 0) {
            pwin[mask] = 0;
            continue;
        }
        int l = a.size();
        if(l==1) {
            pwin[mask] = 1;
            continue;
        }
        double pmax = 0;
        forn(i,0,l) {
            forn(j,i+1,l) {
                double pcand = p[a[i]][a[j]] * pwin[mask-deg2[a[j]]] + p[a[j]][a[i]] * pwin[mask-deg2[a[i]]];
                pmax=max(pcand, pmax);
            }
        }
        pwin[mask] = pmax;
    }
    
    printf("%.10lf",pwin[d2-1]);
    
}