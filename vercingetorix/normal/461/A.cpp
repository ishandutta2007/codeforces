#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvll;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
ll n,x;
ll ans=0;
cin>>n;
vll a;
for(int i=0; i<n; i++){
    cin>>x;
    a.pb(x);
}
sort(a.begin(), a.end());
if(n==1){
    cout<<a[0];
    return 0;
}

for(ll i=0; i<n-1; i++){
    ans+=(i+2)*a[i];
}
ans+=n*a[n-1];

cout<<ans;




//cout<<ans;

 return 0;
}