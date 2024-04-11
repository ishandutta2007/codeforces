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
        map<int,int> mp;
        for(int i=0;i<n;++i) {
            int x;
            cin>>x;
            mp[x]++;
        }
        int cnt=0;
        for(auto p:mp) cnt=max(cnt,p.second);
        cout << max(n & 1, cnt - n + cnt) << endl;
    }
}