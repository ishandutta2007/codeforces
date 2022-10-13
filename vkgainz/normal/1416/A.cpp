#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    map<int,int> app;
    map<int,int> lastfreq;
    for(int i=0;i<n;i++){
        app[a[i]] = max(app[a[i]],i+1-lastfreq[a[i]]);
        lastfreq[a[i]] = i+1;
    }
    for(int i=0;i<n;i++)
        app[a[i]] = max(app[a[i]],n+1-lastfreq[a[i]]);
    int ans[n];
    memset(ans,-1,sizeof(ans));
    for(auto &it : app){
        for(int j=it.second-1;j<n;j++){
            if(ans[j]!=-1) break;
            else ans[j] = it.first;
        }
    }
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
    cout << endl;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        solve();
    }
}