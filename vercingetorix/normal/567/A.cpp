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
    vll c(n);
    vll ansmax(n);
    vll ansmin(n);
    for(ll i=0; i<n; i++) {
        ll x;
        cin>>x;
        c[i]=x;
    }
    for(ll i=0; i<n; i++) {
        if(i==0) cout<<c[1]-c[0]<<' '<<c[n-1]-c[0]<<endl;
        else if(i==n-1) cout<<c[n-1]-c[n-2]<<' '<<c[n-1]-c[0]<<endl;
        else {
            cout<<min(c[i]-c[i-1], c[i+1]-c[i])<<' ';
            cout<<max(c[n-1]-c[i], c[i]-c[0])<<endl;
        }
    }
    
    
}