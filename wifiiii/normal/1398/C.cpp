#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<int,int> mp;
        ll ans=0,cur=0;
        mp[cur]++;
        for(int i=1;i<=s.size();++i) {
            cur+=s[i-1]-'0';
            ans+=mp[cur-i];
            mp[cur-i]++;
        }
        cout<<ans<<endl;
    }
}