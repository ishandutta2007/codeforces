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
int cnt[N]; 
int n,q,two,four;

int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    int x=read();
    cnt[x]++;
    if(cnt[x]%2==0)two++;
    if(cnt[x]%4==0)four++;
  }
  scanf("%d",&q);
  while(q--){
    char opt[5];
    int x;
    scanf("%s%d",opt,&x);
    if(opt[0]=='+'){
      cnt[x]++;
      if(cnt[x]%2==0)two++;
      if(cnt[x]%4==0)four++; 
    }else{
      if(cnt[x]%2==0)two--;
      if(cnt[x]%4==0)four--;
      cnt[x]--;
    }
    if(four>=1&&two>=4){
      puts("YES");
    }else{
      puts("NO");
    }
  } 
  return 0;
}