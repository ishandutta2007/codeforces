#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<pair<int,int>> edges;
int main(){
    int n,m; 
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        --u; --v;
        edges.insert({u,v});
    }
    int pos[30001];
    for(int i=0;i<n;i++){
        bool found = false;
        for(int j=i-1;j>=0 && !found;j--){
            if(edges.count({pos[j],i})){
                
            }
            else{
                found = true;
                for(int x=i-1;x>=j+1;x--){
                    pos[x+1] = pos[x];
                }
                pos[j+1] = i;
            }
        }
        if(!found){
            for(int x=i-1;x>=0;x--){
                pos[x+1] = pos[x];
            }
            pos[0] = i;
        }
    }
    bool work = true;
    for(int i=0;i<n-1;i++) work = work&&(!edges.count({pos[i],pos[i+1]}));
    if(work)
        for(int i=0;i<n;i++) cout << pos[i]+1 << " ";
    else
        cout << -1 << endl;

    
}