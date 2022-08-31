#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int n,m;
  cin>>n>>m;
  vector<pair<int, pair<int,int>>> e;
  for(int i=0; i<m;i++){
      int u,v,w;
      cin>>u>>v>>w;
      e.pb(mp(w, mp(u,v)));
  }
  sort(e.begin(), e.end());
  vi beste(n+1, -1);
  vi newl(n+1,0);
  vi preve1(m+1, -1);
  vi preve2(m+1, -1);
  vi elen1(m+1, 0);
  vi elen2(m+1, 0);
  vector<pair<int,int>> besteup;
  int prevw=999999;

  for(int i=m-1; i>=0;i--){
      if(e[i].first<prevw){
          prevw=e[i].first;
          for(int j=0;j<besteup.size();j++){
              beste[besteup[j].first]=besteup[j].second;
              newl[besteup[j].first]=0;
          }
          besteup.clear();
      }
      int u=e[i].second.first;
      int v=e[i].second.second;
      if(beste[u]==-1){
          
          if(beste[v]==-1){
              //besteup.pb(mp(v,i));
              if((1)>newl[u]){
                  besteup.pb(mp(u,i));
                  newl[u]=1;
              }
              elen1[i]=1;
              //elen2[i]=1;
              continue;
          }
          int k=beste[v];
          int le=elen1[k];
          if(v==e[k].second.second) le=elen2[k];
          elen1[i]=le+1;
          if((le+1)>newl[u]){
              besteup.pb(mp(u,i));
              newl[u]=le+1;
          }
          continue;
      }

      if(beste[v]==-1){
          /*besteup.pb(mp(v,i));
          int k=beste[u];
          int le=elen1[k];
          if(u==e[k].second.second) le=elen2[k];
          elen2[i]=le+1;*/
          continue;
      }
      int k=beste[v];
      int lek=elen1[k];
      if(v==e[k].second.second) lek=elen2[k];
      int l=beste[u];
      int lel=elen1[l];
      if(u==e[l].second.second) lel=elen2[l];
      if((lek+1)>lel){
          if(lek+1>newl[u]){
              newl[u]=lek+1;
              besteup.pb(mp(u,i));
              elen1[i]=lek+1;
          }
      }
      /*if((lel+1)>lek){
          besteup.pb(mp(v,i));
          elen2[i]=lel+1;
      }*/

  }
  for(int j=0;j<besteup.size();j++) beste[besteup[j].first]=besteup[j].second;
  besteup.clear();
  int ans=0;
   for(int i=0; i<m;i++){
       if(elen1[i]>ans) ans=elen1[i];
       if(elen2[i]>ans) ans=elen2[i];
   }
   cout<<ans;



}