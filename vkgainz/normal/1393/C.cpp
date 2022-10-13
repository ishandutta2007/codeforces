#include <bits/stdc++.h>
using namespace std;
int freq[100001];
int n,t;
void solve(){
    cin >> n;
    for(int i=0;i<=100000;i++) freq[i] = 0;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        freq[a]++;
    }
    int idx = 0;
    for(int i=0;i<=100000;i++){
        if(freq[i]>freq[idx]){
            idx = i;
        }
    }
    int tot = 0;
    for(int i=0;i<=100000;i++){
        if(i!=idx){
            if(freq[i]<freq[idx]){
                tot+=freq[i];
            }
            else{
                tot+=freq[i]-1;
            }
        }
    }
    cout << tot/(freq[idx]-1) << endl;
}
int main(){
    cin >> t;
    while(t--){
        solve();
    }
}