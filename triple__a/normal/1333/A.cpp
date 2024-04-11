#include<bits/stdc++.h>
using namespace std;

int t,n,m;
bool vis[127][127];
int main(){
    cin>>t;
    while (t--){
        cin>>n>>m;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                vis[i][j]=(i+j)%2;
            }
        }
        if (n*m%2==0) vis[1][2]=vis[2][1]=0, vis[2][2]=1;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                cout<<(vis[i][j]?"W":"B");
            }
            cout<<endl;
        }
        
    }
}