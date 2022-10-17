#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a.begin(),a.end());
        if(n<=2) {
            for(int i:a) cout<<i<<" ";cout<<endl;
            continue;
        }
        int pos=0,mn=2e9;
        for(int i=0;i<n-1;++i) {
            if(a[i+1]-a[i]<mn) {
                mn=a[i+1]-a[i];
                pos=i;
            }
        }
        for(int i=pos+1;i<a.size();++i) cout<<a[i]<<" ";
        for(int i=0;i<=pos;++i) cout<<a[i]<<" ";
        cout<<'\n';
    }
}