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
        string s;
        cin>>s;
        vector<int> v;
        int cnt=0;
        for(int i=0;i<s.size();++i) {
            if(s[i]=='1') {
                ++cnt;
            } else {
                v.push_back(cnt);
                cnt=0;
            }
        }
        if(cnt) v.push_back(cnt);
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i+=2) {
            ans+=v[i];
        }
        cout<<ans<<endl;
    }
}