#include<bits/stdc++.h>
using namespace std;
int n, m, i, j, k, l, r;
string s, p;
int main(){
  cin>>n>>m>>s>>p;
  if(p[0]=='v'&& s[0]=='<'&&p[m-1]=='^'&&s[n-1]=='>'||p[0]=='^'&& s[0]=='>'&&p[m-1]=='v'&&s[n-1]=='<')cout<<"YES";
  else cout<<"NO";
}