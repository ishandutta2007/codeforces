#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
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

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n;
    
    ll x1, x2;
    ll y1, y2;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>n;
    int ans=0;
    ll a,b,c;
    for(int i=0; i<n; i++) {
        cin>>a>>b>>c;
        
        if(((a*x1+b*y1+c)<0) && ((a*x2+b*y2+c)>0)) ans++;
        if(((a*x1+b*y1+c)>0) && ((a*x2+b*y2+c)<0)) ans++;
    }
    cout<<ans;
    
}