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
    ll n,a,b;
    //ll ans=0;
    //forn(i,1,12) {
    cin>>n;
    //n  = i;
    if(n==0) {
        cout<<0<<" "<<0;
        return 0;
    }
    ll k = (ll)(sqrt((double)n/3));
    ll h;
    for(ll l=k-2; l<=k+2; l++) {
        if ((n>3*(l+1)*l) && (n<=3*(l+1)*(l+2))) {
            h=l;
            break;
        }
    }
    n-=3*(h+1)*h;
        n--;
        ll six = n/(h+1);
        ll step = n%(h+1)+1;
        pll ans;
        if(six==0) ans = {2*h+2-step, 2*step};
        if(six==1) ans = {h+1 -2*step, 2*h+2};
        if(six==2) ans = {-h-1-step, 2*h+2-2*step};
        if(six==3) ans = {-2*h-2+step, -2*step};
        if(six==4) ans = {-h-1+2*step, -2*h-2};
        if(six==5) ans = {h+1+step, -2*h-2+2*step};
        
        
       // cout<<i<<" ";
        cout<<ans.first<<" "<<ans.second<<endl;
    //}
    
    
    // cout<<ans;
}