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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

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
    int n,m,k;
    scanf("%d %d", &n, &k);
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    int curr=-1;
    int curl=0;
    int cur0 = 0;
    int ans = 0;
    int l=-1, r=-1;
    while(curr<n-1) {
        curr++;
        if(a[curr]==0) cur0++;
        while(cur0>k) {
            if(a[curl]==0) cur0--;
            curl++;
        }
        if(curr-curl+1 > ans) {
            l=curl;
            r=curr;
            ans=curr-curl+1;
        }
    }
    printf("%d\n", ans);
    forn(i,0,n) {
        if(i>=l && i<=r) a[i]=1;
        printf("%d ", a[i]);
    }
    // cout<<ans;
}