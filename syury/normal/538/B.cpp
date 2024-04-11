#include<string>
#include<vector>
#include<iostream>

using namespace std;

string s;
vector<string>ans;

int main(){
  cin>>s;
  int n=-1;
  while(n!=0){
    n=0;string c=s;
    for (int i=0;i<c.length();i++){c[i]='0';}
    for (int i=0;i<s.length();i++){
      if(s[i]!='0'){
	n++;
	s[i]--;
	c[i]='1';
      }
    }
    if(n!=0){ans.push_back(c);}
  }
  cout<<ans.size()<<endl;
  for (int i=0;i<ans.size();i++){
    int fp=0;
    while((ans[i][fp]=='0')&&(fp<ans[i].length())){fp++;}
    cout<<ans[i].substr(fp,ans[i].length()-fp)<<" ";
  }
  return 0;
}