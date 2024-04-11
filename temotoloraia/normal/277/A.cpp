#include<bits/stdc++.h>
using namespace std;
int n, m, i, j, k, l, r, w[100], f[100][100], fix[100], ans;
vector<int>v[101];
void dfs(int x){
fix[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(!fix[v[x][i]])dfs(v[x][i]);
    }
}
bool check(){
  for(i=0;i<n;i++)if(w[i])return false;
  return true;
}
int main(){
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>w[i];
        for(j=0;j<w[i];j++){
            cin>>f[i][j];
        }
    }
    if(check()){
      cout<<n;
      return 0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<w[i];j++){
            for(k=i+1;k<n;k++){
                for(l=0;l<w[k];l++){
                    if(f[i][j]==f[k][l]){
                        v[i].push_back(k);
                        v[k].push_back(i);
                        break;
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++){
        if(!fix[i]){ans++;dfs(i);}
    }
    ans--;
    cout<<ans<<endl;
}