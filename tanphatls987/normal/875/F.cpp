#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,ii> iii;

#define X first
#define Y second

const int N=3e5+10;
const int inf=1e9+10;

int n,m;
iii a[N];

int t[N],cir[N];

int root(int x){
  if (t[x]<0) return x;
  return t[x]=root(t[x]);
}
bool merge(int x,int y){
  int rx=root(x),ry=root(y);
  if (rx==ry){
    if (cir[rx]==1) return 0;
    cir[rx]=1;
    return 1;
  }
  if (cir[rx]&&cir[ry]) return 0;
  if (t[rx]>t[ry]) swap(rx,ry);
  cir[rx]+=cir[ry];
  t[rx]+=t[ry];
  t[ry]=rx;
  return 1;
}
int main(){
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    cin>>a[i].Y.X>>a[i].Y.Y>>a[i].X;
  sort(a+1,a+m+1);

  memset(t,-1,sizeof(t));
  ll ans=0;
  for(int i=m;i>=1;i--) if (merge(a[i].Y.X,a[i].Y.Y))
    ans+=a[i].X;
  cout<<ans;
}