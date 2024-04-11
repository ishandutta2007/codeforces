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
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    map<ll, ll> l1;
    map<ll, ll> l2;
    ll ans=0;
    for(int i=0; i<n; i++) {
        ll cur=a[i];
        if(cur%k!=0) {
            l1[cur]++;
        }
        else {
            ll prev=cur/k;
            ans+=l2[prev];
            l2[cur]+=l1[prev];
            l1[cur]++;
        }
    }
    cout<<ans;
}