#include <bits/stdc++.h>
using namespace std;

string s, t;
int flag, i;

int main(){
  cin >> s >> t;
  for(int i=0;i<s.size();i++){
    if(s[i]<t[i]) flag=1;
  }
  if(flag) printf("-1\n");
  else printf("%s\n",t.c_str());
  return 0;
}