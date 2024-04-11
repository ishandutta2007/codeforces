#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        int b[n];
        int c[n];
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        for(int i=0;i<n;i++) cin >> c[i];
        vector<int> v;
        v.push_back(a[0]);
        for(int i=1;i<n-1;i++){
            if(a[i]==v[i-1]) v.push_back(b[i]);
            else v.push_back(a[i]);
        }
        if(v[v.size()-1] != a[n-1] && a[n-1] != v[0]){
            v.push_back(a[n-1]);
        }
        else if(v[v.size()-1] != b[n-1] && b[n-1] != v[0]){
            v.push_back(b[n-1]);
        }
        else{
            v.push_back(c[n-1]);
        }
        for(auto &it : v) cout << it << " ";
        cout << endl;
    }
}