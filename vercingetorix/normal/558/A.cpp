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
typedef std::vector<std::pair<ll, ll> > vpll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;

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
    int n;
    cin>>n;
    //vi x(n);
    //vi a(n);
    int a,x;
    vpi pos;
    vpi neg;
    for(int i=0; i<n; i++) {
        cin>>x>>a;
        if(x>0) pos.pb(mp(x,a));
        else neg.pb(mp(-x,a));
    }
    sort(all(pos));
    sort(all(neg));
    int k=min(pos.size(), neg.size());
    int ans=0;
    for(int i=0; i<k; i++) {
        ans+=pos[i].second;
        ans+=neg[i].second;
    }
    if(pos.size()>k) ans+=pos[k].second;
    if(neg.size()>k) ans+=neg[k].second;
    cout<<ans;
}