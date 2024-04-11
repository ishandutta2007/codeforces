#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        int mx = *max_element(a.begin(), a.end());
        if(k > n * mx) {
            cout << -1 << endl;
            continue;
        }
        int ans=-1;
        for(int i=1;i<=k;++i) {
            int pos=-1;
            for(int j=0;j<n-1;++j) {
                if(a[j]<a[j+1]) {
                    pos=j;
                    break;
                }
            }
            if(pos==-1) break;
            a[pos]++;
            if(i==k) ans=pos+1;
        }
        cout<<ans<<endl;
    }
}