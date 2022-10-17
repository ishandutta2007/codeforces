#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> pos(n);
  vector<int> p(n);
  int now=0;
  stack<int> st;
  for(int i=0;i<n;i++){
    if(s[i]=='('){
      st.push(i);
      p[now]=i;
      now++;
    }else{
      pos[st.top()]=i;
      st.pop();
    }
  }
  vector<bool> ok(n,false);
  for(int i=0;i<k/2;i++){
    ok[p[i]]=ok[pos[p[i]]]=true;
  }
  string ans="";
  for(int i=0;i<n;i++){
    if(ok[i]) printf("%c",s[i]);
  }
  cout << endl;
  return 0;
}