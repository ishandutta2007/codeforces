#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    if(s.length()%2==1 || s[0]==')' || s[s.length()-1]=='(') 
      cout << "No" << "\n";
    else 
      cout << "Yes" << "\n";
  }
}