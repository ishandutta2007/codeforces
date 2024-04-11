#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  for(int t=0;t<n;t++){
    string s;
    cin >> s;
    bool aaa=false;
    vector<bool> usd(27,false);
    for(int i=0;i<s.length();i++){
      if(usd[s[i]-'a'+1]){
        cout << "No" << endl;
        goto next;
      }else{
        usd[s[i]-'a'+1]=true;
      }
    }
    for(int i=0;i<26;i++){
      if(!usd[i]&&usd[i+1]){
        if(aaa){
          cout << "No" << endl;
          goto next;
        }else{
          aaa=true;
        }
      }
    }
    cout << "Yes" << endl;
    next:;
  }
  return 0;
}