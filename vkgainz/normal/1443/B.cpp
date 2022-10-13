#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main() {
    int t; cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        string s; cin >> s;
        bool zero = 1;
        for(int i=0;i<s.length();i++) if(s[i]=='1') zero = 0;
        if(zero) {
            cout << 0 << endl;
            continue;
        }
        bool found=  false;
        vector<int> v;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='1') {
                found = true;
                continue;
            }
            int num = 0;
            for(int j=i;j<s.length();j++) {
                if(s[j]=='0') ++num;
                else {
                    i = j-1;
                    if(found)
                        v.push_back(num);
                    break;
                }
            }
        }
        int ans = a*(v.size()+1);
        for(auto &it : v) {
            ans-=max(0,a-b*it);
        }
        cout << ans << endl;
    }
}