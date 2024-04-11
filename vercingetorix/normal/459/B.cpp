#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif




ll n,m,k;
int ma=0, mi=1000000001;
ll u=0,v=0;
cin>>n;
for(int i=0; i<n; i++){
    int b;
    cin>>b;
    if(b==mi) u++;
    if(b==ma) v++;
    if(b<mi){
        mi=b;
        u=1;
    }
    if(b>ma){
        ma=b;
        v=1;
    }
}
if(ma>mi){
    cout<<(ma-mi)<<" "<<u*v;
}
else{
    cout<<0<<" "<<(u*(u-1))/2;
}
  return 0;
}