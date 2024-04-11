#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int cnt[10];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    string S;
    cin >> S;
    int sum=0;

    for(int i=0; i<10; i++){
      cnt[i] = 0;
    }
    for(char c : S){
      cnt[c-'0']++;
      sum += c-'0';
    }
    bool pos = false;
    if(sum%3 == 0 && cnt[0] > 0){
      cnt[0]--;
      for(int i=0; i<10; i++){
        if(i%2==0 && cnt[i]){
          pos = true;
        }
      }
    }
    if(pos){
      cout << "red\n";
    }
    else{
      cout << "cyan\n";
    }

  }
  return 0;
}