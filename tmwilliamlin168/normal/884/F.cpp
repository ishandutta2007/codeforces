#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t=0;
    string s;
    cin >> n >> s;
    int *b = new int[n];
    for(int i=0; i<n; ++i) {
        cin >> b[i];
        t+=b[i];
    }
    vector<int> a[2];
    for(int i=0; i<n/2; ++i)
        a[s[i]==s[n-1-i]].push_back(i);
    int cnt[26]={};
    for(int c : a[1]) {
        ++cnt[s[c]-'a'];
        t-=min(b[c], b[n-1-c]);
    }
    int d=-1;
    for(int i=0; i<26; ++i) {
        if(2*cnt[i]>a[1].size()) {
            d=i;
            break;
        }
    }
    if(d!=-1) {
        vector<int> e;
        for(int c : a[0])
            if(s[c]-'a'!=d&&s[n-1-c]-'a'!=d)
                e.push_back(min(b[c], b[n-1-c]));
        sort(e.begin(), e.end());
        for(int i=0; i<2*cnt[d]-a[1].size(); ++i)
            t-=e[i];
    }
    cout << t;
}