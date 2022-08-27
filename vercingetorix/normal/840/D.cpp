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

const int B = 300100;
int cnt[B];
int a[300100];
const int A = 330;
int bnum[B];
int ql[B];
int qr[B];
int qi[B];
int qb[B];

int ac[300101];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    forn(i,0,n) scanf("%d", &a[i]);
//    forn(i,0,n) a[i] = 1+i%2;
    forn(i,0,n) {
        a[i]--;
        cnt[a[i]]++;
    }
    int cbig = 0;
    forn(i,0,n) {
        if(cnt[i] >= A) {
            bnum[cbig] = i;
            cbig++;
        }
        cnt[i] = 0;
    }
    int INF = 1e9;
    vi ans(q,-1);
    
    int qnum = 0;
    forn(it,0,q) {
        int l,r,k;
        scanf("%d %d %d", &l, &r, &k);
        l--;
        r--;
        int beat = (r-l+1)/k;
        if(r-l+1 < k*A) {
            int num = INF;
            forn(i,l,r+1) {
                cnt[a[i]]++;
                if(cnt[a[i]] > beat) {
                    num = min(num, a[i]);
                }
            }
            if(num != INF) ans[it] = num+1;
            else ans[it] = -1;
            forn(i,l,r+1) {
                cnt[a[i]] = 0;
            }
        }
        else {
            r++;
            ql[qnum] = l;
            qr[qnum] = r;
            qi[qnum] = it;
            qb[qnum] = beat;
            qnum++;
            ans[it] = -1;
        }
    }
    forn(i,0,cbig) {
        int cv = bnum[i];
        ac[0]=0;
        forn(j,0,n) {
            ac[j+1] = ac[j];
            if (a[j] == cv) ac[j+1]++;
        }
        forn(u,0,qnum) {
            if (ans[qi[u]] == -1 && ac[qr[u]] - ac[ql[u]] > qb[u]) {
                ans[qi[u]] = cv + 1;
            }
        }
    }
    for(auto x : ans) printf("%d\n", x);
}