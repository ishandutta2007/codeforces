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
    ll n,x,y;
    cin>>n>>x>>y;
    //for(int i=0; i<n; i++) 
    ll d=gcd(x,y);
    ll xd=x/d;
    ll yd=y/d;
    ll nok=x/d*y;
    fo(i,0,n) {
        ll a;
        cin>>a;
        ll l=0;
        ll r=(a/(x+y)+2)*nok;
        while((r-l)>1) {
            ll m=(r+l)/2;
            ll hits=m/yd+m/xd;
            if(hits>=a) r=m;
            else l=m;
        }
        if(((r%yd)==0)&&((r%xd)==0)) cout<<"Both\n";
        else if(r%yd==0) cout<<"Vanya\n";
        else cout<<"Vova\n";
    }
    
}