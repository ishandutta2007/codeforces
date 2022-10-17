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

int n;
vector<LL> bit;

LL sum(int i){
  i++;
  LL s=0;
  while(i>0){
    s+=bit[i];
    i-=i&(-i);
  }
  return s;
}

void add(int i,LL x){
  i++;
  while(i<=n){
    bit[i]+=x;
    i+=i&(-i);
  }
}

int main(){
  LL t;
  cin >> n >> t;
  bit=vector<LL>(n+1,0);
  vector<LL> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    add(i,a[i]);
  }
  LL ans=0;
  LL total;
  int l,r,mid;
  LL count=n;
  while(1){
    total=sum(n-1);
    if(total==0) break;
    ans+=t/total*count;
    t%=total;
    while(t<total){
      l=0,r=n;
      while(r-l>1){
        mid=(l+r)/2;
        if(sum(mid-1)<=t){
          l=mid;
        }else{
          r=mid;
        }
      }
      add(l,-a[l]);
      total=sum(n-1);
      count--;
      if(total==0) break;
    }
  }
  cout << ans << endl;
  return 0;
}