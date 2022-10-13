#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int l[n];
        for(int i=0;i<n;i++) cin >> l[i];
        vector<int> pos;
        
        for(int i=0;i<n;i++){
            if(l[i]==0) pos.push_back(a[i]);
        }
        sort(pos.begin(),pos.end(),greater<int>());
        int ans[n];
        int j = 0;
        for(int i=0;i<n;i++){
            if(l[i]==1) ans[i] = a[i];
            else{
                ans[i] =pos[j++];
            }
        }
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
    }
}