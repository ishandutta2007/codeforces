#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL n;
  cin >> n;
  vector<LL> num(10,0);
  while(n>0){
    num[n%10]++;
    n/=10;
  }
  vector<LL> now(10,0);
  for(int i=0;i<10;i++){
    if(num[i]) now[i]=1;
  }
  vector<LL> factorial(19);
  factorial[0]=factorial[1]=1;
  for(int i=2;i<19;i++){
    factorial[i]=i*factorial[i-1];
  }
  LL ans=0;
  bool flag;
  LL kosuu;
  LL kazu;
  while(1){
    kosuu=0;
    for(int i=0;i<10;i++){
      kosuu+=now[i];
    }
    kazu=factorial[kosuu-1]/(factorial[kosuu-1-now[0]])/factorial[now[0]];
    kosuu-=now[0];
    for(int i=1;i<10;i++){
      kazu*=factorial[kosuu]/(factorial[kosuu-now[i]])/factorial[now[i]];
      kosuu-=now[i];
    }
    ans+=kazu;
    flag=false;
    for(int i=0;i<10;i++){
      if(now[i]<num[i]){
        now[i]++;
        for(int j=0;j<i;j++){
          if(now[j]>0){
            now[j]=1;
          }
        }
        flag=true;
        break;
      }
    }
    if(!flag) break;
  }
  cout << ans << endl;
  return 0;
}