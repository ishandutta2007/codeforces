#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        rep(i,n)cin>>a[i];
        vector<int> can_swap(n-1);
        rep(i,m){
            int x;cin>>x;
            can_swap[x-1]=1;
        }
        rep(i,n){
            rep(j,n-1){
                if(can_swap[j] && a[j]>a[j+1])swap(a[j],a[j+1]);
            }
        }
        bool sorted = true;
        rep(i,n-1)if(a[i]>a[i+1])sorted = false;
        puts(sorted?"YES":"NO");
    }
    return 0;
}