#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
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
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ll n,r,avg;
    cin>>n>>r>>avg;
    //for(int i=0; i<n; i++) 
    vpi ba;
    ll a,b;
    ll sum=0;
    fo(i,0,n) {
        cin>>a>>b;
        ba.pb(mp(b,a));
        sum+=a;
    }
    sort(all(ba));
    ll sn=avg*n;
    ll ans=0;
    for(int i=0; i<n; i++) {
        if(sum<sn) {
            ll step=min(sn-sum, r-ba[i].second);
            sum+=step;
            ans+=step*ba[i].first;
        }
    }
    cout<<ans;
}