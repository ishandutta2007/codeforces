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

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ll n,m,dx,dy;
    cin>>n>>m>>dx>>dy;
    ll u,v;
    ll d = gcd(dx, n, u, v);
    ll coef = (2*n-u)%n;
    //for(int i=0; i<n; i++) 
    vll num0x(n,0);
    fo(i,0,m){
        ll x,y;
        cin>>x>>y;
        ll step=(coef*x) % n;
        ll newy = (y+dy*step) %n;
        num0x[newy]++;
    }
    int ans=0;
    int feat=0;
    fo(i,0,n) {
        if(num0x[i]>ans) {
            ans=num0x[i];
            feat=i;
        }
        //cout<<num0x[i]<<endl;
    }
    
    cout<<"0 "<<feat;
}