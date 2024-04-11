#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        map<int,int> freq;
        for(int i=0;i<n;i++){
            for(int j=30;j>=0;j--){
                if(1<<j<=a[i]){
                    ++freq[j];
                    break;
                }
            }
        }
        ll ans = 0;
        for(auto &it : freq){
            ans+=(it.second)*1LL*(it.second-1)/2;
        }
        cout << ans << endl;
    }
}