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
    int n,m,kk;
    //string s;
    ll ans = 0;
    scanf("%d %d",&n,&kk);
    ll k=kk;
    vi a(n+2);
    forn(i,0,n+1) scanf("%d", &a[i]);
    vi old=a;
    int best=n+2;
    int cur = 0;
    vi add(n+1,0);
    while(cur<n) {
        if(a[cur]&1) {
            best=min(best,cur);
            add[cur]=1;
            a[cur+1]+=(a[cur]-1)/2;
        }
        else {
           // ans++;
            a[cur+1]+=a[cur]/2;
        }
        cur++;
    }
    ll shift = -a[n];
    if(best>=n) if((shift+old[n])<=k) if((shift+old[n])!=0) ans++;
    for(int i = n-1; i>=0; i--) {
        shift=2*shift-add[i];
        if(abs(shift)>2*k) break;
        if ((i<=best)&&(abs(shift+old[i])<=k)) ans++;
    }
        cout<<ans;
    return 0;
    
    // cout<<ans;
}