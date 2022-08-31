#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

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
    long long a,b;
    long long ans=0;
    ll ans2;
    cin>>a>>b;
    ans=(b*(b-1)/2)%mod;
    ans2=(a*(a+1)/2)%mod;
    ans2=(ans2*b)%mod + a;
    ans=(ans*ans2)%mod;
    cout<<ans;
    
}