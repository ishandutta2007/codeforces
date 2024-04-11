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
for(int i=0; i<n; i++){
    cin>>a[i];
    //a[x]++;
}
std::sort(a.begin(),a.end());
vi st(n+1,0);
for(int i=0; i<n; i++){
    int f=false;
    for(int j=0;j<n+1;j++){
        if(st[j]<=a[i]){
            st[j]++;
            break;
        }
    }
}
int x=0;
while(st[x]>0) x++;
cout<<x;
  return 0;
}