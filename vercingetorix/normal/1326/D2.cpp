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
    scanf("%d\n", &t);
    char c[1000100];
    while(t--) {
        scanf("%s", c);
        string s(c);
        int n = s.size();
        vector<int> d1 (n);
        int l=0, r=-1;
        for (int i=0; i<n; ++i) {
            int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
            while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
            d1[i] = k;
            if (i+k-1 > r)
                l = i-k+1,  r = i+k-1;
        }
        vector<int> d2 (n);
        l=0, r=-1;
        for (int i=0; i<n; ++i) {
            int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
            while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
            d2[i] = k;
            if (i+k-1 > r)
                l = i-k,  r = i+k-1;
        }
//        forn(i,0,n) cout<<d1[i]<<' ';
//        cout<<endl;
//        forn(i,0,n) cout<<d2[i]<<' ';
//        cout<<endl;
//        cout<<endl;
        int pt = 0;
        while(pt < n && s[pt] == s[n-1-pt]) pt++;
        if(pt == n) {
            printf("%s\n", s.c_str());
            continue;
        }
        int pt2 = n-1-pt;
        pi best = mp(pt,pt);
        int bl = 2*pt;
        forn(i,0,n) {
            int l = i + 1 -d1[i];
            int r = i - 1 +d1[i];
//            if(l > pt && r < pt2) continue;
            if(l <= pt && 2*d1[i]-1+2*l <= n) {
                if(2*d1[i]-1+2*l > bl) {
                    bl = (2*i+1);
                    best =mp(l+2*d1[i]-1, l);
                }
            }
            if(r>=pt2 && 2*d1[i]-1+(n-1-r)*2 <= n) {
                if(2*d1[i]-1+(n-1-r)*2 > bl) {
                    best = mp(n-1-r, n-1-r+2*d1[i]-1);
                    bl = n-1-r+ n-1-r+2*d1[i]-1;
                }
            }
        }
        forn(i,0,n) {
            int l = i - d2[i];
            int r = i - 1 +d2[i];
            //            if(l > pt && r < pt2) continue;
            if(l <= pt && 2*i <= n) {
                if(2*i > bl) {
                    bl = (2*i);
                    best =mp(l+2*d2[i], l);
                }
            }
            if(r>=pt2 && 2*d2[i]+(n-1-r)*2 <= n) {
                if(2*d2[i]+(n-1-r)*2 > bl) {
                    best = mp(n-1-r, n-1-r+2*d2[i]);
                    bl = n-1-r+ n-1-r+2*d2[i];
                }
            }
        }
        printf("%s%s\n", s.substr(0,best.first).c_str(), s.substr(n-best.second, best.second).c_str());
    }
}