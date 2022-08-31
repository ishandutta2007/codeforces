#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n;
    cin >> n;
    vi a(n);
    vpi ord;
    vi p(n+1, 1999999999); 
    for(int i=0; i<n; i++) {
        cin>>a[i];
        ord.pb(mp(a[i], i));
    }
    sort(all(ord));
    set<int> del_ind;
    del_ind.insert(-1);
    del_ind.insert(n);
    vi on(n+1, 0);
    on[n]=1;
    set<int> ol;
    ol.insert(n);
    for(int i=0; i<n; i++) {
        int newd = ord[i].second;
        int v=ord[i].first;
        auto y=del_ind.lower_bound(newd);
        auto x=y;
        x--;
        int s=*y-*x-1;
        on[s]--;
        if(on[s]==0) ol.erase(s);
        int pp=*y-newd-1;
        int q=newd-*x-1;
        on[pp]++;
        if(on[pp]==1) ol.insert(pp);
        on[q]++;
        if(on[q]==1) ol.insert(q);
        auto oe=ol.end();
        oe--;
        int maxs = *(oe);
        p[maxs+1] = min(p[maxs+1], v);
        del_ind.insert(newd);
    }
    int curmax=p[1];
    for(int i=1; i<=n; i++) {
        curmax=min(curmax,p[i]);
        cout<<curmax<<" ";
    }
}