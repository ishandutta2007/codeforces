#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  cin.tie(0);ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for(int q=0;q<t;q++){
    int n;
    cin >> n;
    int ll=200000,rr=0;
    vector<int> l(n),r(n);
    set<int> se;
    map<int,int> idx;
    for(int i=0;i<n;i++){
      cin >> l[i] >> r[i];
      se.insert(l[i]),se.insert(r[i]);
    }
    int no=0;
    for(auto i:se){
      idx[i]=no;
      no++;
    }
    vector<int> c(no,0);
    for(int i=0;i<n;i++){
      c[idx[l[i]]]++,c[idx[r[i]]]--;
      ll=min(ll,idx[l[i]]);
      rr=max(rr,idx[r[i]]);
    }
    for(int i=1;i<no;i++) c[i]+=c[i-1];
    for(int i=ll;i<rr;i++){
      if(c[i]==0){
        for(int j=0;j<n;j++){
          if(i<idx[l[j]]) cout << "2 ";
          else cout << "1 ";
        }
        cout << endl;
        goto next;
      }
    }
    cout << -1 << endl;
    next:
    continue;
  }
  return 0;
}