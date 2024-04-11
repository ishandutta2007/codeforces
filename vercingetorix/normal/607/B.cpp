#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
    
    //ll ans = 0;
    cin >> n;
    vi a(n);
    forn(i,0,n) cin>>a[i];
    vi ans(500*500, 0);
    for(int l = 1; l <= n; l++) {
        for(int s=0; s<=n-l; s++) {
            int e = s+l-1;
            int cur = s*500+e;
            if(l == 1) ans[cur] = 1;
            else if(l==2) {
                if(a[e]==a[s]) ans[cur]=1;
                else ans[cur]=2;
            }
            else {
                ans[cur] = ans[s*500+e-1] + 1;
                if (a[e-1]==a[e]) ans[cur]=min(ans[cur], ans[s*500+e-2] +1);
                forn(j, s+1, e-1) {
                    if(a[j]==a[e]) ans[cur]= min(ans[cur], ans[s*500+j-1] + ans[500*(j+1)+ e-1]);
                }
                if(a[s]==a[e]) ans[cur]=min(ans[cur], ans[(s+1)*500+e-1]);
            }
        }
    }
    
    cout<<ans[n-1];
}