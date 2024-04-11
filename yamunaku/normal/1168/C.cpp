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

struct query{
  int x;
  int y;
  int id;
};

int main(){
  CFS;
  int n,t;
  cin >> n >> t;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<vector<int>> p(n);
  vector<query> q(t); 
  rep(i,t){
    cin >> q[i].x >> q[i].y;
    q[i].x--,q[i].y--;
    q[i].id=i;
  }
  sort(all(q),[](const query &l, const query &r){
    return l.y<r.y;
  });
  vector<bool> ans(t,false);
  vector<vector<int>> r(20,vector<int>(20,-1));
  int idx=0;
  rep(i,n){
    vector<int> tmp(20,-1);
    rep(j,20){
      if(a[i]&(1<<j)){
        tmp[j]=i;
        rep(k,20){
          tmp[k]=max(tmp[k],r[j][k]);
        }
      }
    }
    rep(j,20){
      if(a[i]&(1<<j)){
        rep(k,20){
          r[j][k]=max(r[j][k],tmp[k]);
        }
      }
    }
    while(idx<t){
      if(q[idx].y>i) break;
      rep(j,20){
        rep(k,20){
          if((a[q[idx].x]&(1<<k))&&(a[q[idx].y]&(1<<j))){
            if(q[idx].x<=r[j][k]){
              ans[q[idx].id]=true;
              goto next;
            }
          }
        }
      }
      next:;
      idx++;
    }
  }
  rep(i,t){
    cout << (ans[i]?"Shi":"Fou") << "\n";
  }
  cout << flush;
  return 0;
}