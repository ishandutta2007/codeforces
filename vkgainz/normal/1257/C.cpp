#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> app[200001];
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=0;i<=n;i++) app[i].clear();
        for(int i=0;i<n;i++){
            int x; cin >> x;
            app[x].push_back(i);
        }
        int best = 10000000;
        for(int i=1;i<=n;i++){
            for(int j=0;j+1<app[i].size();j++){
                best = min(best,app[i][j+1]-app[i][j]+1);
            }
        }
        if(best==10000000){
            cout << -1 << endl;
        }
        else{
            cout << best << endl;
        }

        
    }
}