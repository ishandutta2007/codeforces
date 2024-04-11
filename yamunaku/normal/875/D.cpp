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
#define lINF 10000000
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

struct no{
  int v;
  int nu;
};

class LazySegmentTree{
private:
  int n;
  vector<struct no> node;
  vector<int> lazy;
public:
  LazySegmentTree(vector<int> v){
    int sz= (int)v.size();
    n=1;
    while(n<sz) n*=2;
    node.resize(2*n-1);
    lazy.resize(2*n-1,0);
    for(int i=0;i<sz;i++) node[i+n-1]={v[i],1};
    for(int i=n-2;i>=0;i--){
      if(node[i*2+1].v<node[i*2+2].v){
        node[i]=node[i*2+1];
      }else if(node[i*2+1].v>node[i*2+2].v){
        node[i]=node[i*2+2];
      }else{
        node[i]={node[i*2+1].v,node[i*2+1].nu+node[i*2+2].nu};
      }
    }
  }
  void eval(int k,int l,int r){
    if(lazy[k]!=0){
      node[k].v+=lazy[k];
      if(r-l>1){
        lazy[2*k+1]+=lazy[k];
        lazy[2*k+2]+=lazy[k];
      }
      lazy[k]=0;
    }
  }
  void add(int a,int b,int x,int k=0,int l=0,int r=-1){
    if(r<0) r=n;
    eval(k,l,r);
    if(b<=l||r<=a) return;
    if(a<=l&&r<=b){
      lazy[k]+=x;
      eval(k,l,r);
      return;
    }
    add(a,b,x,2*k+1,l,(l+r)/2);
    add(a,b,x,2*k+2,(l+r)/2,r);
    if(node[k*2+1].v<node[k*2+2].v){
      node[k]=node[k*2+1];
    }else if(node[k*2+1].v>node[k*2+2].v){
      node[k]=node[k*2+2];
    }else{
      node[k]={node[k*2+1].v,node[k*2+1].nu+node[k*2+2].nu};
    }
  }
  struct no getmin(int a,int b,int k=0,int l=0,int r=-1){
    if(r<0) r=n;
    eval(k,l,r);
    if(b<=l||r<=a) return {lINF,0};
    if(a<=l&&r<=b) return node[k];
    struct no vl=getmin(a,b,2*k+1,l,(l+r)/2);
    struct no vr=getmin(a,b,2*k+2,(l+r)/2,r);
    if(vl.v<vr.v) return vl;
    else if(vl.v>vr.v) return vr;
    else return {vl.v,vl.nu+vr.nu};
  }
};

struct qry{
  int v;
  int id;
  bool operator<(const struct qry & right) const{
    return v>right.v;
  }
};

int main(){
  int n;
  cin >> n;
  vector<int> a(n,0);
  LazySegmentTree seg(a);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  vector<vector<int>> kl(32,vector<int>(n)),kr(32,vector<int>(n));
  vector<int> l(n,-1),r(n,n);
  for(int i=0;i<32;i++){
    if(a[0]&(1<<i)){
      kl[i][0]=0;
    }else{
      kl[i][0]=-1;
    }
    if(a[n-1]&(1<<i)){
      kr[i][n-1]=n-1;
    }else{
      kr[i][n-1]=n;
    }
    for(int j=1;j<n;j++){
      if(a[j]&(1<<i)){
        kl[i][j]=j;
      }else{
        kl[i][j]=kl[i][j-1];
      }
      if(a[n-j-1]&(1<<i)){
        kr[i][n-j-1]=n-j-1;
      }else{
        kr[i][n-j-1]=kr[i][n-j];
      }
    }
  }
  priority_queue<struct qry> que;
  struct qry now;
  struct no re;
  vector<int> added(n,1);
  for(int i=0;i<n;i++){
    for(int j=0;j<32;j++){
      if(kl[j][i]!=i) l[i]=max(l[i],kl[j][i]);
      if(kr[j][i]!=i) r[i]=min(r[i],kr[j][i]);
    }
    que.push({l[i],i});
    que.push({i,i});
  }
  LL ans=0;
  for(int i=0;i<n;i++){
    while(que.top().v<i){
      now=que.top();
      que.pop();
      seg.add(now.id,r[now.id],added[now.id]);
      added[now.id]*=-1;
    }
    re=seg.getmin(i+1,n);
    if(re.v==0) ans+=re.nu;
  }
  cout << ans << endl;
  return 0;
}