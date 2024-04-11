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

vvi a;
int h,w;

double getdiff(int x, int y) {
    double diff = 0;
    forn(i,0,w) {
        diff += (double) abs(a[x][i] - a[y][i]) / (double) (a[x][i] + a[y][i]);
    }
    return diff;
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int q;
    scanf("%d", &q);
    forn(i,0,q) {
    
        scanf("%d %d", &h, &w);
        a = vvi(h, vi(w,0));
        forn(i,0,h) {
            forn(j,0,w) {
                scanf("%d", &a[i][j]);
            }
        }
        if(getdiff(0,h-1) < getdiff(h/2-1,h/2)) {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    
}