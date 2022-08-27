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

int st[500][100000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    int A = 300;
    scanf("%d %d", &n, &k);
    vi a(n);
    map<int, vi> pos;
    forn(i,0,n) {
        scanf("%d", &a[i]);
        pos[a[i]].pb(i);
    }
    vi ppk(n,-1);
    for (auto vx : pos) {
        int l = vx.second.size();
        forn(i,0,l-k) ppk[vx.second[i]] = vx.second[i+k];
    }
    forn(s,0,501) {
        if(A*s < n) {
            vi cnt(100001,0);
            forn(i,A*s,n) {
                cnt[a[i]]++;
                if(i>0) st[s][i] = st[s][i-1];
                if(cnt[a[i]] <= k) st[s][i]++;
            }
        }
    }
    int q;
    scanf("%d", &q);
    int last = 0;
    forn(i,0,q) {
        int l,r;
        scanf("%d %d", &l, &r);
        l = (l+last)%n;
        r = (r+last)%n;
        if(l>r) swap(l,r);
        int ind = l/A;
        last = st[ind][r];
        forn(j,A*ind,l) {
            last--;
            if(ppk[j]!=-1) if(ppk[j] <= r) last++;
        }
        printf("%d\n", last);
    }
    
}