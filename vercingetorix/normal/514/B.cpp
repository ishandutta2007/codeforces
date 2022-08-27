#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

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
    ll n, x0, y0;
    cin>>n>>x0>>y0;
    int ans=0;
    ll x,y;
    map<pair<int,int>, int> dir;
    for(int i=0; i<n; i++) {
        cin>>x>>y;
        x-=x0;
        y-=y0;
        int d=gcd(abs(x), abs(y));
        x/=d;
        y/=d;
        if(x<0) {
            x=-x;
            y=-y;
        }
        if (x==0) {
            if(y<0) y=-y;
        }
        if(++dir[mp(x,y)]==1) ans++;
    }
    cout<<ans;



}