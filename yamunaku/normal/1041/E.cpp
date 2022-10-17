#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<int> e(n-1);
  int a,b;
  for(int i=0;i<n-1;i++){
    cin >> a >> b;
    e[i]=a;
    if(b!=n){
      cout << "NO" << endl;
      return 0;
    }
  }
  sort(e.begin(),e.end());
  vector<int> count(n-1,0),aki(n-1,-1);
  vector<vector<int>> wariate(n-1,vector<int>(n-1,-1));
  int c=0,next=0;
  for(int i=0;i<n-1;i++) count[e[i]-1]++;
  for(int i=0;i<n-1;i++){
    if(count[i]==0) aki[c]=i,c++;
  }
  for(int i=0;i<n-1;i++){
    for(int j=0;j<count[i]-1;j++){
      if(aki[next]>=i){
        cout << "NO" << endl;
        return 0;
      }
      wariate[i][j]=aki[next];
      next++;
    }
  }
  cout << "YES" << endl;
  int pre;
  for(int i=0;i<n-1;i++){
    if(count[i]>0){
      pre=n;
      for(int j=0;j<count[i]-1;j++){
        cout << pre << " " << wariate[i][j]+1 << endl;
        pre=wariate[i][j]+1;
      }
      cout << pre << " " << i+1 << endl;
    }
  }
  return 0;
}