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
    int n,m,q;
    scanf("%d %d %d", &n, &m,&q);
    vvi val(n, vi(m));
    forn(i,0,n) forn(j,0,m) scanf("%d", &val[i][j]);

    vi r((n+1)*(m+1));
    vi d((n+1)*(m+1));
    forn(i,0,n+1) forn(j,0,m+1) {
        r[i*(m+1)+j] = (i*(m+1) + j+1);
        d[i*(m+1)+j] = ((i+1)*(m+1) + j);
    }
    forn(qr,0,q) {
        int i1,j1,i2,j2,h,w;
        scanf("%d %d %d %d %d %d", &i1, &j1, &i2, &j2, &h, &w);
        i1--;
        i2--;
        j1--;
        j2--;
        int ult1 = i1*(m+1);
        forn(i,0,j1) ult1 = r[ult1];
        int ult2 = i2*(m+1);
        forn(i,0,j2) ult2 = r[ult2];
        int pt1 = ult1;
        int pt2 = ult2;
        forn(i,0,h) {
            pt1=d[pt1];
            pt2=d[pt2];
            swap(r[pt1], r[pt2]);
        }
        forn(i,0,w) {
            pt1=r[pt1];
            pt2=r[pt2];
            swap(d[pt1],d[pt2]);
        }
        pt1 = ult1;
        pt2 = ult2;
        forn(i,0,w) {
            pt1=r[pt1];
            pt2=r[pt2];
            swap(d[pt1],d[pt2]);
        }
        forn(i,0,h) {
            pt1=d[pt1];
            pt2=d[pt2];
            swap(r[pt1], r[pt2]);
        }
    }
    forn(i,0,n) {
        int pt = (i+1)*(m+1);
        forn(j,0,m) {
            pt=r[pt];
            printf("%d ", val[pt/(m+1)-1][pt%(m+1)-1]);
        }
        printf("\n");
    }
    
    
    
}