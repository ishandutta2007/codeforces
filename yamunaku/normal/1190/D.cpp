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

struct SegmentTree {
private:
  int n;
  vector<int> node;

public:
  SegmentTree(int sz) {
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1, 0);
    for(int i=0; i<sz; i++) node[i+n-1] = 1;
    for(int i=n-2; i>=0; i--) node[i] = node[2*i+1]+node[2*i+2];
  }

  void dec(int x) {
    x += (n - 1);
    node[x]--;
    while(x > 0) {
      x = (x - 1) / 2;
      node[x] = node[2*x+1] + node[2*x+2];
    }
  }

  LL getsum(int a, int b, int k=0, int l=0, int r=-1) {
    if(r < 0) r = n;
    if(r <= a || b <= l) return 0;
    if(a <= l && r <= b) return node[k];
    LL vl = getsum(a, b, 2*k+1, l, (l+r)/2);
    LL vr = getsum(a, b, 2*k+2, (l+r)/2, r);
    return vl+ vr;
  }
};

struct point{
  int x;
  int y;
};

int main(){
  LL n;
  cin >> n;
  vector<point> p(n);
  map<int,pair<int,int>> mp;
  set<int> aa;
  rep(i,n){
    cin >> p[i].x >> p[i].y;
    mp[p[i].x].first=max(mp[p[i].x].first,p[i].y);
  }
  int sz=0;
  for(auto &pp:mp){
    pp.second.second=sz++;
    // cout << pp.first SP pp.second.first SP pp.second.second << endl;
  }
  SegmentTree seg(sz);
  sort(all(p),[](point &l, point &r){
    return l.y==r.y?l.x<r.x:l.y<r.y;
  });
  LL ans=0;
  LL pre=0;
  LL idx=0;
  queue<int> q;
  rep(i,n){
    if(pre==p[i].y){
      ans += (seg.getsum(0,mp[p[i].x].second)-idx)*(seg.getsum(mp[p[i].x].second+1,sz)+1);
    }else{
      while(!q.empty()){
        seg.dec(q.front());
        q.pop();
      }
      ans += (seg.getsum(0,mp[p[i].x].second)+1)*(seg.getsum(mp[p[i].x].second+1,sz)+1);
    }
    // cout << ans << endl;
    if(mp[p[i].x].first==p[i].y) q.push(mp[p[i].x].second);
    pre=p[i].y;
    idx=seg.getsum(0,mp[p[i].x].second);
  }
  cout << ans << endl;
  return 0;
}