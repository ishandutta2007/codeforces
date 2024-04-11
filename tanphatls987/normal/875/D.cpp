#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

#define X first
#define Y second

const int N=3e5+10;
const int inf=1e9+10;

int n,a[N],pos[40];

vector <int> imp[N];
ii ra[N];
struct segtree{
  int cov[N<<2],b[N<<2];
  void update(int node,int L,int R,int l,int r,int type){
    if (L>r||R<l) return;
    if (l<=L&&R<=r){
      cov[node]+=type;
      if (cov[node]) b[node]=R-L+1;
      else b[node]=(L<R)?b[node*2+1]+b[node*2]:0;
      return;
    }
    update(node*2,L,(L+R)/2,l,r,type);
    update(node*2+1,(L+R)/2+1,R,l,r,type);
    if (cov[node]) b[node]=R-L+1;
    else b[node]=b[node*2]+b[node*2+1];
  }
}mseg;

ll solve(){
  ll ans=0;
  for(int i=1;i<=n;i++){
    mseg.update(1,1,n,ra[i].X+1,i,1);
    for(auto j:imp[i])
      mseg.update(1,1,n,ra[j].X+1,j,-1);
    
    mseg.update(1,1,n,i+1,n,1);
    ans+=n-mseg.b[1];
    //cout<<i<<" "<<ans<<'\n';
    mseg.update(1,1,n,i+1,n,-1);
  }
  return ans;
}
int main(){
  
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=1;i<=n;i++){
    for(int j=0,val=a[i];j<=31;j++,val>>=1){
      if (val&1) pos[j]=i;
      else ra[i].X=max(ra[i].X,pos[j]);
    }
  }
  fill(pos,pos+32,n+1);
  for(int i=n;i>=1;i--){
    ra[i].Y=n+1;
    for(int j=0,val=a[i];j<=31;j++,val>>=1){
      if (val&1) pos[j]=i;
      else ra[i].Y=min(ra[i].Y,pos[j]);
    }
  }
  for(int i=1;i<=n;i++)
    imp[ra[i].Y].push_back(i);
  
  //for(int i=1;i<=n;i++) cout<<ra[i].X<<" "<<ra[i].Y<<'\n';
  cout<<solve();
}