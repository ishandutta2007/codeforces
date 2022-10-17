#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i=0;i<n;i++){
    cin >> p[i];
    p[i]--;
  }
  int now;
  for(int i=0;i<n;i++){
    vector<bool> a(n,false);
    now=i;
    while(!a[now]){
      a[now]=true;
      now=p[now];
    }
    cout << now+1;
    if(i<n-1) cout << " " << flush;
    else cout << endl;
  }
  return 0;
}