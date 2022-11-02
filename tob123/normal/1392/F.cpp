#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<ll,ll> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

int N;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  vector<ll> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  ll h1=A[0];
  ll cnt1=1, cnt2=0;
  for(int i=1; i<N; i++){
    ll dif = A[i]-h1-(cnt1-1)-max(0ll,cnt2-1);
    //cout << dif << endl;
    if(dif == 1){
      if(cnt2)
        cnt2++;
      else
        cnt1++;
    }
    else{
      if(dif > cnt2){
        cnt1 += cnt2;
        if(cnt2)
          dif--;
        dif -= cnt2;
        cnt2 = 0;
        ll g = dif/(cnt1+1);
        h1 += g;
        dif -= g*(cnt1+1);
        if(dif > 1){
          swap(cnt1, cnt2);
          cnt2 -= dif-1;
          cnt1 += dif-1;
          cnt2++;
          h1++;
        }
        else if(dif == 1)
          cnt1++;
        else
          cnt2++;
      }
      else{
        cnt2 -= dif-1;
        cnt1 += dif-1;
        cnt2++;
      }
      if(cnt1 == 0)
        swap(cnt1, cnt2);
    }
    //cout << h1 << " " << cnt1 << " " << cnt2 << endl;
  }
  for(int i=0; i<cnt1; i++){
    cout << h1+i << " ";
  }
  for(int j=0; j<cnt2; j++){
    cout << h1+cnt1+j-1 << " ";
  }
  cout << "\n";
}