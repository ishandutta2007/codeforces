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
  
int m,n,k;
cin>>n;
vi a(n);
int l=0;
int r=0;
ll ans=0;
for(int i=0; i<n; i++){
    int x;
    cin>>x;
    
    if(x==0){
        ans+=r;
        l++;
    }
    if(x==1){
        r++;
    }
    //a[x]++;
}
cout<<ans;

  return 0;
}