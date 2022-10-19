#include <bits/stdc++.h>
using namespace std;

const int INF=1e9+7;
 
int as[200005], bs[200005];
         
vector<pair<int,int> > start[200005];
int ans[200005];
int where[200005];
int N;
         
void show(){
  for(int i=1;i<=N;i++)
    cout<<ans[i]<<' ';
  cout<<endl;
}
 
pair<int,int> st[400005];
 
int query(int l,int r){
  l--;
  pair<int,int> res{INF,INF};
  for(l+=N,r+=N;l<r;l>>=1,r>>=1){
    if(l&1) res=min(res,st[l++]);
    if(r&1) res=min(res,st[--r]);
  }
  return res.second;
}
         
int main(){
  cin>>N; 
  for(int i=1;i<=N;i++){
    cin>>as[i]>>bs[i];
    start[as[i]].push_back({bs[i],i});
  }
  set<pair<int,int> > active;//(right,index)
  for(int i=1;i<=N;i++){
    active.insert(start[i].begin(),start[i].end());
    ans[active.begin()->second]=i;
    where[i]=active.begin()->second;
    active.erase(active.begin());
  }
  for(int i=0;i<N;i++){
    st[i+N]={as[where[i+1]],i+1};
  }
  for(int i=N-1;i>0;i--){
    st[i]=min(st[i<<1],st[i<<1|1]);
  }
  for(int i=1;i<=N;i++){
    int j=query(i+1,bs[where[i]]);
    if(j==INF) continue;
    if(as[where[j]]<=i){
      cout<<"NO"<<endl;
      show();
      swap(ans[where[i]],ans[where[j]]);
      show();
      return 0;
    }
  }
  cout<<"YES"<<endl;
  show();
}