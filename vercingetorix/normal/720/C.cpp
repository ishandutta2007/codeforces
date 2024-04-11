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

int n,m,k;
vvi a;
int cur;
bool add(int x, int y) {
    if(x==0) {
        a[x][y] = 1;
        return true;
    }
    if(y == 0) {
        if(a[x-1][0] + a[x-1][1] == 2) cur++;
        a[x][y] = 1;
        return true;
    }
    int inc = 0;
    if(a[x-1][y] + a[x-1][y-1] == 2) inc++;
    if(a[x][y-1] + a[x-1][y-1] == 2) inc++;
    if(a[x-1][y] + a[x][y-1] == 2) inc++;
    if(y < m-1 && a[x-1][y] + a[x-1][y+1] == 2) inc++;
    if(inc == 0) {
        if(a[x][y-1] == 0 && a[x-1][y] == 0 && y == m-1) return false;
    }
    if(cur+inc <= k) {
        cur+=inc;
        a[x][y] = 1;
        return true;
    }
    else return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    cin>>t;
    forn(aff,0,t) {
        
        cin>>n>>m>>k;
        cur = 0;
        a=vvi(n,vi(m,0));
        int best = (n-1)*(m-1)*4;
        if(k>best || k==best -1 || k==best -2 || k==best-5 || k==best-4) {
            printf("-1\n");
            if(aff<t-1) printf("\n");
            continue;
        }
        if(k==best  - 8) {
            if(m>3 && n>3) {
                printf("-1\n");
                if(aff<t-1) printf("\n");
                continue;
            }
            forn(i,0,n) forn(j,0,m) {
                a[i][j] = 1;
            }
            if(n == 3) {
                forn(i,0,3) a[i][0] = 0;
            }
            else if(m == 3) {
                forn(i,0,3) a[0][i] = 0;
            }
            forn(i,0,n) {
                forn(j,0,m) {
                    if(a[i][j]) printf("*");
                    else printf(".");
                }
                printf("\n");
            }
            if(aff<t-1) printf("\n");
            continue;
        }
        bool f = false;
        forn(i,0,n) {
            if(cur == k) break;
            forn(j,0,m) {
                add(i,j);
                if(cur==k) break;
            }
        }
        if(k==0) add(0,0);
        if(cur<k) {
            if(a[n-2][m-1] == 0) {
                a[n-1][0]=0;
                a[n-1][1]=1;
                a[n-1][2]=1;
                cur = k;
            }
        }
        if(cur<k) {
            printf("-1\n");
            if(aff<t-1) printf("\n");
            continue;
        }
        forn(i,0,n) {
            forn(j,0,m) {
                if(a[i][j]) printf("*");
                else printf(".");
            }
            printf("\n");
        }
        if(aff<t-1) printf("\n");
            
    }
}