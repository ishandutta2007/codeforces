#include <bits/stdc++.h>
using namespace std;

int N, T;
string S;
set<char> Cs;
vector<char> C;

char nextBest(char c){
  for(int i=0; i<C.size(); i++){
    if(C[i] == c){
      return C[i+1];
    }
  }
  cerr << "fail" << endl;
  exit(0);
  return '-';
}

int main(){
  cin >> N >> T;
  cin >> S;
  for(int i=0; i<N; i++){
    if(Cs.count(S[i]) == 0){
      C.push_back(S[i]); 
      Cs.insert(S[i]);
    }
  }
  sort(C.begin(), C.end());

  string news = S.substr(0, T);
  for(int i=0; i<T-N; i++){
    news.push_back(C[0]);
  }
  if(T > N){
    cout << news << endl;
    return 0;
  }

  for(int i=T-1; i>=0; i--){
    if(news[i] != C[C.size()-1]){
      news[i] = nextBest(news[i]);
      break;
    }
    else{
      news[i] = C[0];
    }
  }

  cout << news << endl;

  return 0;
}