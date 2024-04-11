#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t; cin>>s>>t;
  map<char,int> c,v;
  for(char x:s) c[x]++;
  for(char x:t) v[x]++;
  if(c==v) return cout<<"array",0;
  for(char x:t) if(v[x]>c[x]) return cout<<"need tree",0;
  for(int n=s.size()-1,m=t.size()-1;n>=0&&m>=0;){
    if(s[n]==t[m]) n--,m--;
    else n--;
    if(m==-1){ cout<<"automaton";return 0;
    }
  }
  return cout<<"both",0;
}