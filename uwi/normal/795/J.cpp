#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;

int main()
{
  cin >> n >> m;
  cin >> s;
  for(int i = 0;i < n-m+1;i++){
    if(i >= 1 && s[i-1] == 'N')continue;
    if(i+m < n && s[i+m] == 'N')continue;

    int ok = 1;
    for(int j = 0;j < m;j++){
      if(s[i+j] == 'Y'){
        ok = 0;
      }
    }
    int rep = 0;
    for(int j = 0;j < i;j++){
      if(s[j] == 'N'){
        if(++rep > m){
          ok = 0;
        }
      }else{
        rep = 0;
      }
    }
    rep = 0;
    for(int j = i+m;j < n;j++){
      if(s[j] == 'N'){
        if(++rep > m){
          ok = 0;
        }
      }else{
        rep = 0;
      }
    }
    if(ok){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}