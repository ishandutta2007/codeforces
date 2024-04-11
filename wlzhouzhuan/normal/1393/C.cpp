#include<bits/stdc++.h>
using namespace std;

int read(){
  int x=0;
  char ch=getchar();
  while(!isdigit(ch))ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return x;
}

const int N=100005;
int a[N],cnt[N];
int n;

int main(){
  int T=read();
  while(T--){
    n=read();
    int maxx=-1,S=0;
    for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
      cnt[a[i]]++;
      if(cnt[a[i]]>maxx){
        maxx=cnt[a[i]];
        S=1;
      }else if(cnt[a[i]]==maxx){
        S++;
      }
    }
    printf("%d\n",(n-S*maxx)/(maxx-1)+(S-1));
    for(int i=1;i<=n;i++)cnt[a[i]]--; 
  }  
}