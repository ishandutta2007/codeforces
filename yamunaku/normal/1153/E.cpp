#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  int ret;
  int p1,p2,ans1,ans2;
  bool ok=false;
  for(int i=1;i<n;i++){
    cout << "? 1 1" SP i SP n << endl;
    cin >> ret;
    if(ret%2){
      p1=i;
      ok=true;
      for(int j=i+1;j<=n;j++){
        cout << "? 1 1" SP j SP n << endl;
        cin >> ret;
        if(ret%2==0){
          p2=j;
          goto next;
        }
      }
    }
  }
  next:
  if(ok){
    int l=1,r=n+1;
    while(r-l>1){
      int mid=(l+r)/2;
      cout << "? 1 1" SP p1 SP mid-1 << endl;
      cin >> ret;
      if(ret%2) r=mid;
      else l=mid;
    }
    ans1=l;
    l=1,r=n+1;
    while(r-l>1){
      int mid=(l+r)/2;
      cout << "?" SP p1+1 SP 1 SP n SP mid-1 << endl;
      cin >> ret;
      if(ret%2) r=mid;
      else l=mid;
    }
    ans2=l;
    cout << "!" SP p1 SP ans1 SP p2 SP ans2 << endl; 
  }
  
  
  
  for(int i=1;i<n;i++){
    cout << "? 1 1" SP n SP i << endl;
    cin >> ret;
    if(ret%2){
      p1=i;
      ok=true;
      for(int j=i+1;j<=n;j++){
        cout << "? 1 1" SP n SP j << endl;
        cin >> ret;
        if(ret%2==0){
          p2=j;
          goto next2;
        }
      }
    }
  }
  next2:
  if(ok){
    int l=1,r=n+1;
    while(r-l>1){
      int mid=(l+r)/2;
      cout << "? 1 1" SP mid-1 SP p1 << endl;
      cin >> ret;
      if(ret%2) r=mid;
      else l=mid;
    }
    ans1=l;
    cout << "!" SP ans1 SP p1 SP ans1 SP p2 << endl; 
  }
  return 0;
}