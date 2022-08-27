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
vvi b;
int h,w;
int we;
double getdiff(int x, int y) {
    double diff = 0;
    double line = 0;
    forn(i,0,w) {
        double sdiff = 0;
        double loh = 0;
        forn(j,0,min(we,2)) sdiff+=a[x-j][i] - a[y+j][i];
        forn(j,0,min(we,2)) loh +=a[x-j][i];
        diff += (double) abs(sdiff);
        line+=loh;
        
    }
    return diff/line;
    
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
        int k;
        scanf("%d %d %d", &h, &w, &k);
        we =h/k;
        a = vvi(h, vi(w,0));
        b = vvi(h, vi(w,0));
        forn(i,0,h) {
            forn(j,0,w) {
                scanf("%d", &a[i][j]);
            }
        }
        int d = 5;
        forn(i,0,h) {
            forn(j,0,w) {
                int l = max(0, j - d);
                int r = min(w-1, j+d);
                forn(k,l,r+1) b[i][j] += a[i][k];
                b[i][j] = (b[i][j] + d) / (2*d + 1);
            }
        }
        a = std::move(b);
        b.clear();
        vector<vector<double>> fit(k, vd(k,0));
        forn(i,0,k) forn(j,0,k) {
            fit[i][j] = getdiff((i+1)*(h/k) - 1, j*(h/k));
        }
        vi ans;
        double bestfit = 1e25;
        vvi g(k);
        forn(i,0,k) g[i].pb(i);
        forn(affa,0,k-1) {
            int bi=-1,bj;
            forn(i,0,k) forn(j,0,k) {
                if(i==j) continue;
                if(g[i].size() == 0 || g[j].size() == 0) continue;
                if (bi==-1 || fit[g[bi].back()][g[bj].front()] > fit[g[i].back()][g[j].front()]) {
                    bi = i;
                    bj=j;
                }
            }
            for(auto u:g[bj]) g[bi].pb(u);
            g[bj].clear();
        }
        forn(i,0,k) for(auto u : g[i]) ans.pb(u);
//        forn(st,0,k) {
//            vi u(k,0);
//            vi cand(1,st);
//            u[st] = 1;
//            double candfit = 0;
//            forn(lpl,0,k-1) {
//                double bn = 1e25;
//                int ind = -1;
//                forn(i,0,k) {
//                    if(!u[i] && fit[cand.back()][i] < bn) {
//                        bn = fit[cand.back()][i];
//                        ind = i;
//                    }
//                }
//                u[ind] = 1;
//                candfit += bn;
//                cand.pb(ind);
//            }
//            if(candfit < bestfit) {
//                bestfit = candfit;
//                ans = std::move(cand);
//                cand.clear();
//            }
//        }
//        forn(i,0,k) printf("%d ", ans[i]+1);
        vi ans2(k);
        forn(i,0,k) ans2[ans[i]] = i;
        ans= ans2;
        forn(i,0,k) printf("%d ", ans[i]+1);
        printf("\n");
        
    }
    
}