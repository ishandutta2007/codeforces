#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> block;

int t, n;
int a[4001];
bool pos(){
    bool dp[n+3];
    memset(dp,false,sizeof(dp));
    dp[0] = true;
    auto it = block.begin();
    while(it!=block.end()){
        for(int i=n+2;i>=*it;i--){
            dp[i] = dp[i-*it]||dp[i];
        }
        it++;
    }
    
    return dp[n];
}
void solve(){
    set<int> s;
    for(int i=1;i<=2*n;i++){
        s.insert(i);
    }
    int l = 2*n-1;
    int r = 2*n-1;
    while(l>=0){
        while(r>=0 && *s.rbegin() !=a[r]){
            s.erase(a[r]);
            r--;
            
        }
        s.erase(a[r]);
        block.push_back((l-r)+1);
        l = r;
        l--;
        r--;
    }
    if(pos()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        block.clear();
        for(int i=0;i<2*n;i++){
            cin >> a[i];
        }
        solve();
    }
}