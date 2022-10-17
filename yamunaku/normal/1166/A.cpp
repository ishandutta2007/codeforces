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
#define CYES cout<<"Yes"<<endl;
#define CNO cout<<"No"<<endl;

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<int> a(26,0);
  string s;
  rep(i,n){
    cin >> s;
    a[s[0]-'a']++;
  }
  int ans=0;
  rep(i,26){
    int x=a[i]/2;
    int y=a[i]-x;
    ans+=x*(x-1)/2+y*(y-1)/2;
  }
  cout << ans << endl;
  return 0;
}