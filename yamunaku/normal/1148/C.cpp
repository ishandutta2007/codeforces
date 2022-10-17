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

vector<int> p;
vector<int> pos;

vector<pair<int,int>> ans;
void swp(int x,int pt){
  int px = pos[x];
  int t = p[pt];
  swap(p[px],p[pt]);
  swap(pos[x],pos[t]);
  ans.push_back({px,pt});
}

int main(){
  CFS;
  int n;
  cin >> n;
  p=vector<int>(n);
  pos=vector<int>(n);
  rep(i,n){
    cin >> p[i];
    p[i]--;
    pos[p[i]]=i;
  }
  rep(i,n/2){
    int x = n/2-i-1;
    int px = pos[x];
    if(px<n/2){ // n-1
      swp(x,n-1);
      swp(x,x);
    }else{ // 0 n-1
      swp(x,0);
      swp(x,n-1);
      swp(x,x);
    }
    int y = n/2+i;
    int py = pos[y];
    if(py<n/2){ // n-1 0
      swp(y,n-1);
      swp(y,0);
      swp(y,y);
    }else{ // 0
      swp(y,0);
      swp(y,y);
    }
  }
  int m = ans.size();
  cout << m << endl;
  rep(i,m){
    cout << ans[i].first+1 SP ans[i].second+1 << "\n";
  }
  cout << endl;
  return 0;
}