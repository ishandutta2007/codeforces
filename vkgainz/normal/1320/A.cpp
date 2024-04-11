#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,ll> freq;
int main(){
    int n; cin >> n;
    int b[n];
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++)
        freq[b[i]-i]+=b[i];
    ll ret = 0;
    for(auto &it : freq){
        ret = max(ret,it.second);
    }
    cout << ret << endl;
    
    
}