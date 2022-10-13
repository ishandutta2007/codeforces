#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>> x;
        for(int i=0;i<2*n;i++){
            int a,b; cin >> a >> b;
            x.push_back({a,b});
        }
        if(m%2){
            cout << "NO" << endl;
        }
        else{
            bool found = false;
            for(int i=0;i<n;i++){
                if(x[2*i].second==x[2*i+1].first){
                    found = true;
                    break;
                }
            }
            if(found) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}