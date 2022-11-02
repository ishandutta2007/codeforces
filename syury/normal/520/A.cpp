#include<string>
#include<vector>
#include<iostream>
#include<cctype>

using namespace std;
vector<char>a(26,false);

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  for (size_t i=0;i<s.length();i++){
    s[i]=tolower(s[i]);
    a[s[i]-'a']=true;
  }
  for (size_t i=0;i<26;i++){
    if(a[i]==false){cout<<"NO"<<endl;return 0;}
  }
  cout<<"YES"<<endl;
  return 0;
}