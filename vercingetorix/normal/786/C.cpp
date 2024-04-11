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
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) a[i]--;
    vi cnt(n,0);
    int A=320;
    forn(cur,1,min(A,n+1)) {
        int l = 0;
        int ans = 0;
        while(l<n) {
            vi aff;
            int num = 0;
            while(1) {
                if(l==n) {
                    for(auto x : aff) cnt[x] = 0;
                    break;
                }
                if(cnt[a[l]] == 0) {
                    num++;
                    aff.pb(a[l]);
                    cnt[a[l]]=1;
                    if(num>cur) {
                        for(auto x : aff) cnt[x] = 0;
                        break;
                    }
                }
                l++;
            }
            ans++;
        }
        printf("%d ", ans);
    }
    if(n>=A) {
        vvi boss;
        vi r;
        vi bad;
        int l = 0;
        int ans = 0;
        while(l<n) {
            vi aff;
            int num = 0;
            while(1) {
                if(l==n) {
                    boss.pb(cnt);
                    r.pb(n);
                    bad.pb(aff.size());
                    for(auto x : aff) cnt[x] = 0;
                    break;
                }
                if(cnt[a[l]] == 0) {
                    num++;
                    if(num>A) {
                        boss.pb(cnt);
                        r.pb(l);
                        bad.pb(aff.size());
                        for(auto x : aff) cnt[x] = 0;
                        break;
                    }
                    aff.pb(a[l]);
                }
                cnt[a[l]]++;;
                l++;
            }
            ans++;
        }
        boss.pb(vi(n,0));
        printf("%d ", (int)r.size());
        forn(cur,A+1,n+1) {
            int pt = 0;
            while(r[pt]<n) {
                if(bad[pt]<cur || boss[pt][a[r[pt]]] != 0) {
                    if(boss[pt][a[r[pt]]] == 0) bad[pt]++;
                    boss[pt][a[r[pt]]]++;
                    boss[pt+1][a[r[pt]]]--;
                    if(boss[pt+1][a[r[pt]]] == 0) bad[pt+1]--;
                    r[pt]++;
                }
                else {
                    pt++;
                }
            }
            printf("%d ", pt+1);
        }
    }
    
    
}