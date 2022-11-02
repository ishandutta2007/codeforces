#include<string>
#include<iostream>

using namespace std;

string s;

int main(){
  cin>>s;
  if(s.length()<=10){cout<<"NO"<<endl;return 0;}
  int l1=0,l2=0;
  string p="CODEFORCES";
  for (int i=0;i<=9;i++){
    if(p[i]!=s[i]){break;}
    l1++;
  }
  for (int j=0;j<=9;j++){
    if(p[9-j]!=s[s.length()-1-j]){break;}
    l2++;
  }
  if(l1+l2>=10){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
  return 0;
}