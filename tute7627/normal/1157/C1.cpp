#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
ll MOD = 1e9+7;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }

int main(){
  ll i, j;
  ll n;
  cin >> n;
  vector<ll> a(n);
  string result;
  for(i = 0; i < n; i++)
    cin >> a[i];
  
  ll buf = 0;
    
  for(i = 0, j = n - 1; i <= j;){
    if((a[i] <= a[j] && buf < a[i]) || (a[j] < buf && a[i] > buf)){
      result.push_back('L');
      //cout << "tsts" << endl;
      buf = a[i];
      i++;
      
    }
    else if(buf < a[j]){
      result.push_back('R');
      buf = a[j];
      //cout << "tsts" << endl;
      j--;
    }
    else{
      //cout <<buf spa a[i] spa a[j] << endl;
      break;
    }
  }
  cout << result.size() << endl;
  cout << result << endl;

  return 0;
}