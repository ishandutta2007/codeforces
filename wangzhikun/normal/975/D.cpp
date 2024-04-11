#include <bits/stdc++.h>
const int MX = 2e5+5;
using namespace std;
typedef long long ll;
int main() {
  int n;cin>>n;ll a,b;cin>>a>>b;
  map<ll,ll> vis;
  map<pair<int,int>,int> sim;
  ll ans = 0;
  for(int i=1;i<=n;i++)
  {
        int x,vx,vy;
       scanf("%d%d%d",&x,&vx,&vy);
        ans += vis[a*vx-vy] - sim[{vx,vy}];
        vis[a*vx-vy]++;
        sim[{vx,vy}]++;
  }
  cout<<2*ans<<endl;
}