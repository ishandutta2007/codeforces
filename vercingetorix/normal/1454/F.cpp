#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
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
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(iaf,0,t) {
        int n;
        read(n);
        readv(a,n);
        map<int, vi> u;
        forn(i,0,n) {
            u[-a[i]].pb(i);
        }
        int ft = 0;
        int can = 0;
        int maxl = 0;
        int minr = 0;
        int ml = 0;
        int mr = 0;
        int l = 0;
        int r = 0;
        int mid = 2e9;;
        for(auto x : u) {
            if(ft == 0) {
                if(x.second.size() > 2) {
                    printf("YES\n");
                    int l = x.second[1];
                    int r = n - x.second[1]-1;
                    printf("%d 1 %d\n", l, r);
                    can = 1;
                    break;
                }
                maxl = x.second[0] - 1;
                minr = x.second.back() + 1;
                ml = x.second[0];
                mr = x.second[0];
                ft = 1;
                l = x.second[0];
                r = x.second.back();
                forn(i,l,r+1) mid = min(mid,a[i]);
                continue;
            }
            if(x.second.size() > 2) {
                if(l > x.second[0] && r<x.second.back()) {
                    if(l-1>x.second[0] && a[l-1] == -x.first) {
                        l--;
                        mid = min(mid, -x.first);
                    }
                    if(r+1<x.second.back() && a[r+1] == -x.first) {
                        r++;
                        mid = min(mid, -x.first);
                    }
                    if(mid == -x.first) {
                        printf("YES\n");
                        printf("%d %d %d\n", l, r-l+1, n-r-1);
                        can = 1;
                        break;
                    }
                }
            }
            if(x.second[0] < l) {
                forn(i,x.second[0],l) mid = min(mid, a[i]);
                l = x.second[0];
            }
            if(x.second.back() > r) {
                forn(i,r,x.second.back()) mid=min(mid, a[i+1]);
                r = x.second.back();
            }
        }
        if(can == 0) printf("NO\n");
        
        
    }
    
}