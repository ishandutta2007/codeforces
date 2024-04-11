#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
int a[2005],n;
int main(){
  for(int T=read();T;T--){
    n=read();
    set<int>s;
    for(int i=1;i<=2*n;i++)s.insert(i);
    for(int i=1;i<=n;i++){
      a[2*i-1]=read();
      s.erase(a[2*i-1]);
    }
    int tag=0;
    for(int i=2;i<=2*n;i+=2){
      auto it=s.lower_bound(a[i-1]);
      if(it==s.end()){
        tag=1;break;
      }
      a[i]=*it,s.erase(it);
    }
    if(tag){
      puts("-1");continue;
    }
    for(int i=1;i<=2*n;i++)printf("%d ",a[i]);puts("");
  }
  return 0;
}