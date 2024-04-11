#include<bits/stdc++.h>

using namespace std;
 
#define ll long long
#define ar array
 
#define fi first
#define se second

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>l(n),r(n);
    vector<int>st;
    int inf=2e9+7;
    for(int i=0;i<n;i++){
      cin>>l[i]>>r[i];
      l[i]=l[i]*2;
      r[i]=r[i]*2;
      st.push_back(l[i]-1);
      st.push_back(l[i]+1);
      st.push_back(l[i]);
      st.push_back(r[i]);
    }
    st.push_back(-inf);
    sort(st.begin(),st.end());
    st.resize(unique(st.begin(),st.end())-st.begin());
    vector<int>ok(st.size()+1);
    vector <ll>who(st.size()+1);
    vector<vector<int>>her(st.size());
    for(int i=0;i<n;i++){
      l[i]=lower_bound(st.begin(),st.end(),l[i])-st.begin();
      r[i]=lower_bound(st.begin(),st.end(),r[i])-st.begin();
      who[l[i]]+=i;
      who[r[i]+1]-=i;
      ok[l[i]]++;
      ok[r[i]+1]--;
      her[l[i]].push_back(i);
    }
    for(int i=1;i<(int)st.size();i++){
      ok[i]+=ok[i-1];
      who[i]+=who[i-1];
    }
    int ans=0;
    vector<int>delta(n);
    for(int i=1;i<(int)st.size();i++){
      if (her[i].empty())continue;
      if (her[i].size()==1){
        if(!ok[i-1]){
          ans++;
          delta[her[i][0]]--;
        }else{
          if(ok[i-1]==1){
            delta[who[i-1]]++;
          }
        }
      }else{
        if(!ok[i-1]){
          ans++;
        }else{
          if(ok[i-1]==1){
            delta[who[i-1]]++;
          }
        }
      }
    }
    cout<<ans+*max_element(delta.begin(),delta.end())<<'\n';
  }
}