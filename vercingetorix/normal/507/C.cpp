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
    ll h,n;
    cin>>h>>n;
    n--;
    ll ans=0;
    ll p2=1;
    ll dopp2=2;
    int deg=0;
    fo(i,0,h) {
        deg++; p2*=2;
    }
    vi path(h+1);
    for(int i=h; i>0; i--) {
        path[i]=(n%2);
        n/=2;
        
    }
    path[0]=1;
    for(int i=h; i>0; i--) {
        if(path[i]==path[i-1]) {
            ans+=dopp2;
        }
        else {
            ans++;
        }
        dopp2*=2;
    }
    
    
    cout<<ans;
}