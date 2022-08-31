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
    ll c,hr,hb,wr,wb;
    ll ans=0;
    //for(int i=0; i<n; i++) 
    cin>>c>>hr>>hb>>wr>>wb;
    if(hb*wr>hr*wb){
        swap(hr,hb);
        swap(wr,wb);
    }
    // hr/wr>=hb/wb
    ll r=c/wr;
    if(wb>=1000) {
        for(int i=0; i<=c/wb; i++) {
            ll pans=i*hb;
            pans+=((c-i*wb)/wr)*hr;
            if(pans>ans) ans=pans;
        }
        cout<<ans;
    }
    else {
        for(int i=r; i>=r-min(r,wb); i--) {
            ll pans=i*hr;
            pans+=((c-i*wr)/wb)*hb;
            if(pans>ans) ans=pans;
        }
        cout<<ans;
    }
    
}