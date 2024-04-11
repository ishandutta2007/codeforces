#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;
string S;
int n;

vector<int> d1;
vector<int> d2;
void manacher(){
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && S[i - k] == S[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }

  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && S[i - k - 1] == S[i + k]) {
      k++;
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k ;
    }
  }
}



int longPalOdd(int ind){
  int l = ind-1, r=ind+1;
  int cur = 1;
  while(l >= 0 && r < sz(S) && S[l] == S[r]){
    l--; r++;
    cur += 1;
  }
  return cur;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> S;
    int cnt = 0;
    for(int i=0; i<sz(S)/2; i++){
      if(S[i] == S[sz(S)-i-1])
        cnt++;
      else
        break;
    }
    n = sz(S);
    d1.resize(sz(S));
    d2.resize(sz(S));
    manacher();
    int best = 0;
    int l, r, c;
    for(int i=0; i<sz(S); i++){
      int pal = d1[i];
      //cout << i << ": " << pal << endl;
      int curCnt = min(i+1-pal, sz(S)-i-pal);
      int res = 2*pal-1+2*curCnt;
      bool found = false;
      if(pal+cnt >= i+1){
        if(res > best){
          found = true;
        }
      }
      if(pal+cnt >= sz(S)-i){
        if(res > best){
          found = true;
        }
      }
      if(found){
        best = res;
        c = curCnt;
        l = i-pal+1;
        r = i+pal-1;
      }
    }
    for(int i=1; i<sz(S); i++){
      int pal = d2[i];
      //cout << i << ": " << pal << endl;
      int curCnt = min(i-pal, sz(S)-i-pal);
      int res = 2*pal+2*curCnt;
      bool found = false;
      if(pal+cnt >= i){
        if(res > best){
          found = true;
        }
      }
      if(pal+cnt >= sz(S)-i){
        if(res > best){
          found = true;
        }
      }
      if(found){
        best = res;
        c = curCnt;
        l = i-pal;
        r = i+pal-1;
      }
    }
    //cout << best << endl;
    string res = "";
    for(int i=0; i<c; i++) res.push_back(S[i]);
    for(int i=l; i<=r; i++) res.push_back(S[i]);
    for(int i=sz(S)-c; i<sz(S); i++) res.push_back(S[i]);
    cout << res << "\n";
  }

  return 0;
}