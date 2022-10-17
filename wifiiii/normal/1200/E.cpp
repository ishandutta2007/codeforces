#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn=1000005;
int f[maxn];
void getf(string s) {
    f[0] = 0;
    for(int i=1;i<s.size();++i) {
        int j = f[i-1];
        while(j && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = j + 1;
        else f[i] = 0;
    }
}
int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    string ans=a[0];
    for(int i=1;i<n;++i) {
        int len=min(a[i].size(), ans.size());
        string tmp = a[i].substr(0, len) + "#" + ans.substr(ans.size() - len);
        getf(tmp);
        int mx = f[tmp.size()-1];
        ans += a[i].substr(mx);
    }
    cout << ans << endl;
}