#include <bits/stdc++.h>

using namespace std;

const string a[5]={"Danil", "Olya", "Slava", "Ann",  "Nikita"};


int h[5];
string s;
int main(){
  cin>>s;
  for(int i=0;i<s.length();i++) {
    for(int j=0;j<5;j++)
      if (s.length()-i>=a[j].length()){
        if (s.substr(i,a[j].length())==a[j]) h[j]++;
      }
  }
  int sum=0;
  for(int i=0;i<5;i++) sum+=h[i];
  if (sum==1) cout<<"YES";
  else cout<<"NO";
}