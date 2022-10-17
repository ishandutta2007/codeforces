#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n),b(m);
  vector<vector<int>> v(n,vector<int>(m,0));
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<m;i++) cin >> b[i];
  int at,bt,now;
  for(int i=0;i<32;i++){
    at=bt=0;
    for(int j=0;j<n;j++) if(a[j]&(1<<i)) at++;
    for(int j=0;j<m;j++) if(b[j]&(1<<i)) bt++;
    if((at-bt)%2){
      cout << "NO" << endl;
      return 0;
    }
    now=0;
    if(at<bt){
      for(int j=0;j<n;j++){
        if(a[j]&(1<<i)){
          while(!(b[now]&(1<<i))) now++;
          v[j][now]+=(1<<i);
          now++;
        }
      }
      for(;now<m;now++){
        if(b[now]&(1<<i)) v[0][now]+=(1<<i);
      }
    }else{
      for(int j=0;j<m;j++){
        if(b[j]&(1<<i)){
          while(!(a[now]&(1<<i))) now++;
          v[now][j]+=(1<<i);
          now++;
        }
      }
      for(;now<n;now++){
        if(a[now]&(1<<i)) v[now][0]+=(1<<i);
      }
    }
  }
  cout << "YES" << endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%d",v[i][j]);
      if(j<m-1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}