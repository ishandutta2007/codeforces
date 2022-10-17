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
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  CFS;
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  int ans=0;
  vector<int> aa={4,8,15,16,23,42};
  vector<int> idx(6,0);
  while(1){
    rep(i,6){
      repp(j,idx[i],n){
        if(a[j]==aa[i]){
          idx[i]=j+1;
          if(i<5) idx[i+1]=max(idx[i+1],j+1);
          else ans++;
          goto next;
        }
      }
      goto answer;
      next:;
    }
  }
  answer:;
  cout << n-ans*6 << endl;
  return 0;
}