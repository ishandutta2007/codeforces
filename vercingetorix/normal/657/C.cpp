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
    int n,m,k,b,c;
    //string s;
    ll ans = 0;
    scanf("%d %d %d %d",&n,&k,&b,&c);
    vi t(n);
    forn(i,0,n) scanf("%d", &t[i]);
    sort(all(t));
    ll best = 999999999999999999;
    if(5*c<=b) {
        vll chsum(n);
        ll sum=0;
        forn(i,0,n) {
            sum+=(ll)t[i];
            chsum[i]=sum;
        }
        
        forn(i,k-1,n) {
            ll cost=chsum[i];
            if(i>k-1) cost-=chsum[i-k];
            cost = (ll)(k)*(ll)(t[i]) - cost;
            best=min(cost,best);
        }
        cout<<best;
        return 0;
    }
    vector<multiset<ll>> price(5);
    vll sum(5,0);
    vll addvalue(5,0);
    vll prevvalue(5,0);
    for(int i = 0; i<n; i++) {
        
        for(int add =0; add<5;add++) {

            int mod5 = ((t[i]+add)%5+5)%5;
            if(i>0) addvalue[mod5]+=(t[i]+add -prevvalue[mod5])/5 * b;
            prevvalue[mod5] = t[i]+add;
            if(price[mod5].size()<k) {
                price[mod5].insert((ll)add * c - addvalue[mod5]);
                sum[mod5]+=(ll)add * c - addvalue[mod5];
            }
            else if(*(--price[mod5].end()) > ((ll)add * c - addvalue[mod5])) {
                sum[mod5]+=(ll)add * c - addvalue[mod5] - *(--price[mod5].end());
                price[mod5].erase(--price[mod5].end());
                price[mod5].insert((ll)add * c - addvalue[mod5]);
            }
            if(price[mod5].size() == k) {
                best = min(best, sum[mod5]+k*addvalue[mod5]);
            }
        }
    }
    cout<<best;
    
    // cout<<ans;
}