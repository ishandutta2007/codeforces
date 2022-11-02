#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m,ans=0;

int main(){
  scanf("%d%d",&n,&m);
  if(n>m){swap(n,m);}
  while((n>0)&&(n<m)){ans++;n--;m-=2;}
  if(n>0){
    while(n>=3){
      n-=3;m-=3;ans+=2;
    }
    if(n==2){ans++;}
  }
  printf("%d",ans);
  return 0;
}