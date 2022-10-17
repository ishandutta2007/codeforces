#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n-1;++i) {
            while(k && a[i]) {
                --k,--a[i],++a.back();
            }
        }
        for(int i:a) cout<<i<<" ";cout<<endl;
    }
}