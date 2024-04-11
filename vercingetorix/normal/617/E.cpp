#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <cstring>
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
    //string s;
    //ll ans = 0;
    scanf("%d %d %d", &n,&m,&k);
    int binsize = (int)sqrt((double)n);
    int binsnum = (n+binsize-1)/binsize;
    vector<vpi> bins(binsnum);
    vi b(n);
    vi a(n+1);
    a[0]=0;
    forn(i,0,n) {
        //int a;
        scanf("%d", &b[i]);
        a[i+1]=(a[i]|b[i]) - (a[i]&b[i]);
    }
    map<pi, ll> ans;
    vpi queries;
    forn(i,0,m) {
        int l,r;
        scanf("%d %d",&l,&r);
        l--;
        //r--;
        queries.pb(mp(l,r));
        bins[l/binsize].pb(mp(r,l));
    }
    //
    for(int i = 0; i<binsnum; i++) sort(all(bins[i]));
    for(int bin = 0; bin<binsnum; bin++) {
        ll curans = 0;
        vi num(1048576, 0);
        int curq = 0;
        int curr = bin*binsize - 1;
        int curl = bin*binsize;
        int binleft= curl;
        while(curq<bins[bin].size()) {
            while(curr<bins[bin][curq].first) {
                int add = a[curr+1];
                int cnt = (add|k) - (add&k);
                curans+=num[cnt];
                num[add]++;
                curr++;
                //add curr
            }
            while(curl<bins[bin][curq].second) {
                //del curl
                int del = a[curl];
                int cnt = (del|k) - (del&k);
                num[del]--;
                curans-=num[cnt];
                curl++;
            }
            ans[mp(curl,curr)] = curans;
            curq++;
            while(curl>binleft) {
                //add curl-1
                int add = a[curl-1];
                int cnt = (add|k) - (add&k);
                curans+=num[cnt];
                num[add]++;
                curl--;
            }
        }
    }
    forn(i,0,m) printf("%I64d\n", ans[queries[i]]);
}