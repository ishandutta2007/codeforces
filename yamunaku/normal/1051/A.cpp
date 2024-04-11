#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int t;
  cin >> t;
  string s;
  int a,b,c,pa,pb,pc;
  for(int i=0;i<t;i++){
    cin >> s;
    a=b=c=0;
    for(int j=0;j<s.length();j++){
      if(0<=s[j]-'a'&&s[j]-'a'<26){
        a++;
        pa=j;
      }else if(0<=s[j]-'A'&&s[j]-'A'<26){
        b++;
        pb=j;
      }else{
        c++;
        pc=j;
      }
    }
    if(a==0){
      if(b==0){
        s[0]='a';
        s[1]='A';
      }else if(c==0){
        s[0]='a';
        s[1]='0';
      }else{
        if(b>1){
          s[pb]='a';
        }else{
          s[pc]='a';
        }
      }
    }else if(b==0){
      if(c==0){
        s[0]='A';
        s[1]='0';
      }else{
        if(a>1){
          s[pa]='A';
        }else{
          s[pc]='A';
        }
      }
    }else if(c==0){
      if(a>1){
        s[pa]='0';
      }else{
        s[pb]='0';
      }
    }
    cout << s << endl;
  }
  return 0;
}