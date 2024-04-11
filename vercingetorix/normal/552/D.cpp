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
    ll n;
    cin>>n;
    vpi pts;
    for(int i=0; i<n; i++) {
        int x,y;
        cin>>x>>y;
        pts.pb(mp(x,y));
    }
    int zeroarea=0;
    for(int i=0; i<n; i++) {
        map<pi,int> numline;
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            int x=pts[j].first-pts[i].first;
            int y=pts[j].second-pts[i].second;
            if(x<0) {x=-x; y=-y;}
            if((x==0)&&(y<0)) y=-y;
            int d=gcd(abs(x),abs(y));
            x/=d;
            y/=d;
            pi dir=mp(x,y);
            zeroarea+=numline[dir];
            numline[dir]++;
        }
    }
    zeroarea/=3;
    ll ans=(n*(n-1)*(n-2))/6-zeroarea;
    cout<<ans;
}