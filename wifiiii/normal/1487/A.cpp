#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i : a) {
            if(i > a[0]) ++ans;
        }
        cout << ans << endl;
    }
}