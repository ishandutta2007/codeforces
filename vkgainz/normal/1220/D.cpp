#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; 
    scanf("%d",&n);
    ll b[n];
    for(int i=0;i<n;i++)
        cin >> b[i];
    sort(b,b+n,greater<int>());
    vector<vector<ll>> x;
    for(int i=0;i<61;i++){
        vector<ll> temp;
        x.push_back(temp);
    }
    for(int i=0;i<n;i++){
        int t = 0;
        ll temp = b[i];
        while(temp%2==0){
            temp/=2;
            t++;
        }
        x[t].push_back(b[i]);
    }
    int best = 0;
    int m= 0;
    for(int i=0;i<=60;i++){
        if(x[i].size()>m){
            m = x[i].size();
            best = i;
        }
    }
    vector<ll> ans;
    for(int i=0;i<=60;i++){
        if(i!=best){
            for(int j=0;j<x[i].size();j++) ans.push_back(x[i][j]);
        }
    }
    cout << ans.size() << endl;
    for(auto &it : ans)
        cout << it << endl;
}