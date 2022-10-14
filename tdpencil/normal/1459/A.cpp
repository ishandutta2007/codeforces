#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define atoi(x) (x-'0')
int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;
    int acount=0,bcount=0;
    for(int i =0; i < N; i++) {
      if(atoi(s[i]) > atoi(t[i])) {
        acount++;
      } else if(atoi(t[i]) > atoi(s[i])) {
        bcount++;
      }
    }
    if(acount==bcount) {
      puts("EQUAL");
    } else if(acount > bcount) {
      puts("RED");
    } else {
      puts("BLUE");
    }
  }
}