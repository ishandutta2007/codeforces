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

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,k;
    cin>>n;
    vi a(n);
    int d=0;
    multiset<pi> lol;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        //d=gcd(d,a[i]);
        int d=a[i];
        int deg2=0;
        while(d%2==0) {
            d/=2; 
            deg2++;
        }
        lol.insert(mp(d, deg2));
    }
    int ans=0;
    while(lol.begin()->first!=(--lol.end())->first) {
        auto it=--lol.end();
        ans+=it->second+1;
        int x=it->first/2;
        lol.erase(it);
        int d2=0;
        while(x%2==0) {
            x/=2;
            d2++;
        }
        lol.insert(mp(x,d2));
    }
    vi deg(20,0);
    for(auto it=lol.begin(); it!=lol.end(); it++) {
        deg[it->second]++;
    }
    int mi=99999999;
    for(int i=0; i<20; i++) {
        int newans=0;
        for(int j=0; j<20; j++) {
            newans+=deg[j]*abs(j-i);
        }
        if(newans<mi) mi=newans;
    }
    cout<<ans+mi;
}