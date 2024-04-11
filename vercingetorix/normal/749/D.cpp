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
    scanf("%d", &n);
    vvi bets(n);
    vi ulti(n);
    int A=450;
    vpi bb;
    forn(i,0,n) {
        int a,b;
        scanf("%d %d", &a, &b);
        a--;
        bets[a].pb(b);
    }
    vi isl(n,0);
    vi lar;
    forn(i,0,n) {
        if(bets[i].size()>0) ulti[i] = bets[i].back();
        if(bets[i].size() > A) {
            isl[i] = 1;
            lar.pb(i);
        }
        else for(auto x : bets[i]) bb.pb(mp(x, i));
    }
    
    sort(all(bb));
    vi dis(n, 0);
    int q;
    scanf("%d", &q);
    forn(iqr,0,q) {
        int k;
        scanf("%d", &k);
        vi was(k);
        forn(i,0,k) {
            scanf("%d", &was[i]);
            was[i]--;
            dis[was[i]] = 1;
        }
        pi best = mp(-1,-1);
        pi best2 = mp(-1,-1);
        int pt = (int)bb.size() - 1;
        while(pt>=0 && dis[bb[pt].second]) pt--;
        if(pt >=0) {
            best = bb[pt];
            int ptwas = pt;
            dis[bb[pt].second] = 1;
            while(pt>=0 && dis[bb[pt].second]) pt--;
            if(pt>=0) {
                best2=bb[pt];
            }
            dis[bb[ptwas].second] = 0;
        }
        for(auto ind : lar) {
            if(dis[ind]) continue;
            pi cand = mp(ulti[ind], ind);
            if(cand > best) {
                best2 = best;
                best = cand;
            }
            else if(cand>best2) {
                best2 = cand;
            }
        }
        if(best.first == -1) {
            printf("0 0\n");
        }
        else {
            int ind = best.second;
            int beat = best2.first;
            int bet = *(lower_bound(all(bets[ind]), beat));
            // int bet = 0;
            printf("%d %d\n", ind+1, bet);
        }
        // continue;
        for(auto x : was) dis[x] = 0;
    }
}