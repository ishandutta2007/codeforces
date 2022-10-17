#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"YES"<<endl;
#define CNO cout<<"NO"<<endl;

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<pair<string,int>> s(2*n);
  rep(i,n){
    cin >> s[2*i].first >> s[2*i+1].first;
    s[2*i].second = s[2*i+1].second = i+1;
  }
  sort(all(s));
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  int now=0;
  rep(i,2*n){
    if(s[i].second==p[now]) now++;
    if(now==n){
      CYES;
      return 0;
    }
  }
  CNO;
  return 0;
}