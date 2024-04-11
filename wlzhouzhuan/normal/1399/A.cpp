#include<bits/stdc++.h>
using namespace std;
const int N=55;
int a[N],n;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ok=1;
    if(n==1){
      puts("YES");
      continue;
    }
    for(int i=1;i<n;i++){
      if(a[i+1]-a[i]>1){
        ok=0;
        break;
      }
    }
    puts(ok?"YES":"NO");
  }
  return 0;
}