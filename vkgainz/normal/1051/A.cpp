#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    //1 dig, 1 uppercase, 1 lowercase
    bool found = false;
    bool dig = false, upper = false, lower = false;
    for(int i=0;i<s.length();i++) {
      if(s[i]-'0'<=9) dig = true;
      else if(isupper(s[i])) upper = true;
      else if(islower(s[i])) lower = true;
    }
    if(dig && upper && lower) {
      cout << s << "\n";
      continue;
    }
    string ans = "";
    for(int i=0;i<s.length();i++) {
      dig = false, upper = false, lower = false;
      for(int j=0;j<i;j++) {
        if(s[j]-'0'<=9) dig = 1;
        else if(isupper(s[j])) upper = 1  ;
        else if(islower(s[j])) lower = 1;

      }
      for(int j=i+1;j<s.length();j++) {
        if(s[j]-'0'<=9) dig = 1;
        else if(isupper(s[j])) upper = 1  ;
        else if(islower(s[j])) lower = 1;
      }
      if((dig+upper+lower)>=2) {
        found = true;
        if(!lower) {
          ans = s.substr(0, i) + 'a' + s.substr(i+1, s.length()-(i+1));
        }
        else if(!upper) {
          ans = s.substr(0, i) + 'A' + s.substr(i+1, s.length()-(i+1));
        }
        else if(!dig) {
          ans = s.substr(0, i) + '0' + s.substr(i+1, s.length()-(i+1));
        }
        break;
      }
    }
    if(found) {
      cout << ans << "\n";
      continue;
    }
    for(int i=0;i<s.length()-1;i++) {
      dig = false, upper = false, lower = false;
      for(int j=0;j<i;j++) {
        if(s[j]-'0'<=9) dig = 1;
        else if(isupper(s[j])) upper = 1  ;
        else if(islower(s[j])) lower = 1;
      }
      for(int j=i+2;j<s.length();j++) {
        if(s[j]-'0'<=9) dig = 1;
        else if(isupper(s[j])) upper = 1  ;
        else if(islower(s[j])) lower = 1;
      }
      if((dig+upper+lower)>=1) {
        found = true;
        if(lower) {
          ans = s.substr(0, i) + "A9" + s.substr(i+2, s.length()-(i+2));
        }
        else if(upper) {
          ans = s.substr(0, i) + "a9" + s.substr(i+2, s.length()-(i+2));
        }
        else if(dig) {
          ans = s.substr(0, i) + "Aa" + s.substr(i+2, s.length()-(i+2));
        }
        break;
      }
    }
    if(found) {
      cout << ans << "\n";
      continue;
    }
    ans = s.substr(0, s.length()-3)+"aA9";
    cout << ans << "\n";
  }
}