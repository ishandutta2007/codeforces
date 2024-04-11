#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string s,ss;
set<string>se;
int main(){
   cin>>s;
   n=s.size();
   se.insert(s);
   for (int i=1;i<n;i++){
      ss=s[n-1];
      for (int j=0;j<n-1;j++)ss+=s[j];
      se.insert(ss);
      s=ss;
   }
   cout<<se.size()<<endl;
	return 0;	
}