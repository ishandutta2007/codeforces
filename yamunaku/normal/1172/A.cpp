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
  vector<int> a(n),b(n);
  rep(i,n){
    cin >> a[i];
  }
  int now=0;
  rep(i,n){
    cin >> b[i];
    if(b[i]==now+1) now++;
    else now=0;
  }
  int ans=0;
  vector<bool> f(n+1,false);
  if(now>0){
    rep(i,n) f[a[i]]=true;
    int c=0;
    repp(i,now+1,n+1){
      if(!f[i]) goto next;
      f[b[c]]=true;
      c++;
    }
    cout << n-now << endl;
    return 0;
    next:;
  }
  int count=0;
  int c=0;
  rep(i,n) f[a[i]]=true;
  repp(i,1,n+1){
    while(!f[i]){
      if(c<n) f[b[c]]=true;
      c++;
      count++;
    }
    if(c<n) f[b[c]]=true;
    c++;
    count++;
  }
  cout << count << endl;
  return 0;
}