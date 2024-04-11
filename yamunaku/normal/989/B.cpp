#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,p;
  cin >> n >> p;
  string s;
  cin >> s;
  bool zero,one;
  for(int i=0;i<p;i++){
    zero=one=false;
    if(i+p<n){
      for(int j=i;j<n;j+=p){
        if(s[j]=='.'){
          for(int k=i;k<n;k+=p){
            if(s[k]=='0'){
              zero=true;
            }else if(s[k]=='1'){
              one=true;
            }
          }
          for(int k=0;k<n;k++){
            if(s[k]=='.') s[k]='0';
          }
          if(zero){
            s[j]='1';
          }else if(one){
            s[j]='0';
          }else{
            if(j==i){
              s[j]='0';
              s[j+p]='1';
            }else{
              s[j]='0';
              s[j-p]='1';
            }
          }
          cout << s << endl;
          return 0;
        }else if(s[j]=='0'){
          zero=true;
        }else if(s[j]=='1'){
          one=true;
        }
        if(zero&one){
          for(int k=0;k<n;k++){
            if(s[k]=='.') s[k]='0';
          }
          cout << s << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}