#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),count(101,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
    count[a[i]]++;
  }
  int c=0,th=-1;
  for(int i=1;i<=100;i++){
    if(count[i]==1) c++;
    else if(count[i]>=3) th=i;
  }
  int isa=0;
  bool ok=false;
  if(c%2==1&&th==-1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    if(c%2){
      for(int i=0;i<n;i++){
        if(count[a[i]]==1){
          if(isa) cout << "A";
          else cout << "B";
          isa=isa^1;
        }else if(a[i]==th){
          if(ok) cout << "B";
          else cout << "A";
          ok=true;
        }else{
          cout << "A";
        }
      }
    }else{
      for(int i=0;i<n;i++){
        if(count[a[i]]==1){
          if(isa) cout << "A";
          else cout << "B";
          isa=isa^1;
        }else{
          cout << "A";
        }
      }
      cout << endl;
    }
  }
  return 0;
}