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
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
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
    ll n,m;
    ll ans = 0;
    cin>>n;
    vvi a(n, vi(n, 0));
    for(int i=0; i<n; i++)
        for(int j=0;j<n; j++) {
            char c;
            cin>>c;
            if(c=='C') a[i][j]=1;
        }
    
    for(int i=0; i<n; i++){
        int d =0; int b=0;
        for(int j=0;j<n; j++) {
            d+=a[i][j];
            b+=a[j][i];
        }
        ans+=d*(d-1)/2;
        ans+=b*(b-1)/2;
    }
    
    
    cout<<ans;
}