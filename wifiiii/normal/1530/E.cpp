#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> getf(string s) {
    vector<int> f(s.size());
    f[0] = 0;
    for(int i=1;i<s.size();++i) {
        int j = f[i-1];
        while(j && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = j + 1;
        else f[i] = 0;
    }
    return f;
}
string comb(vector<int> cnt) {
    string ret;
    for(int i = 0; i < 26; ++i) {
        ret += string(cnt[i], 'a' + i);
    }
    return ret;
}
string solve(string s) {
    int n = s.size();
    sort(s.begin(), s.end());
    vector<int> cnt(26);
    for(char c : s) cnt[c - 'a']++;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] == 1) {
            --cnt[i];
            string ans = string(1, i + 'a');
            ans += comb(cnt);
            return ans;
        }
    }
    int mn = *min_element(s.begin(), s.end()) - 'a';
    int mx = *max_element(s.begin(), s.end()) - 'a';
    if( mn == mx ) return s;
    if( cnt[mn] - 1 <= (n - cnt[mn]) + 1 ) {
        string ans = string(1, mn + 'a');
        --cnt[mn];
        for(int i = mn + 1; i < 26; ++i) {
            while(cnt[i]) {
                if(cnt[mn]) --cnt[mn], ans += mn + 'a';
                --cnt[i], ans += i + 'a';
            }
        }
        if(cnt[mn]) --cnt[mn], ans += mn + 'a';
        assert(!cnt[mn]);
        return ans;
    }
    for(int i = mn + 1; i < 26; ++i) {
        if(!cnt[i]) continue;
        if(i == mx) {
            --cnt[mn];
            return string(1, mn + 'a') + string(cnt[i], i + 'a') + string(cnt[mn], mn + 'a');
        }
        int k = i + 1;
        while(!cnt[k]) ++k;
        string ans;
        --cnt[mn]; ans += mn + 'a';
        --cnt[i]; ans += i + 'a';
        ans += string(cnt[mn], mn + 'a'); cnt[mn] = 0;
        if(cnt[i]) {
            --cnt[k]; ans += k + 'a';
        }
        ans += comb(cnt);
        return ans;
    }
    assert(-1);
    return "";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
}