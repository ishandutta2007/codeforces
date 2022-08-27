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
  
  int m,n,t,p;

  cin>>t;
  for(int i=0;i<t;i++){
    vb eused(25*25,false);
    cin>>n>>p;
    for(int i=0; i<n;i++) cout<<i+1<<" "<<(i+1)%n+1<<endl;
    for(int i=0; i<n;i++) cout<<i+1<<" "<<(i+2)%n+1<<endl;
    int s=3;
    int cnt=0;
    while(p>0){
        p--;
        cout<<cnt+1<<" "<<(cnt+s)%n+1<<endl;
        cnt++;
        if(cnt==n){
            cnt=0;
            s++;
        }
    }

  }
  

  return 0;
}