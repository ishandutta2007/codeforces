#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int N =s.length();

    queue<int> q[26];
    for(int i =0; i < N; i++) q[s[i]-'a'].push(i);
    for(int i =0; i < 26; i++) q[i].push(N);
    
    vector<long long> ans(27,0);
    for(int i =0; i < N; i++) {
        vector<int> v(27,N);
        for(int j =0; j < 26; j++) v[j] =q[j].front();
        sort(v.begin(),v.end());
        for(int j =1; j <= 26; j++) ans[j] +=v[j]-v[j-1];
        q[s[i]-'a'].pop();}
    
    for(int i =26; i > 0; i--) if(ans[i] > 0) {
        cout << i << "\n";
        break;}
    for(int i =1; i <= 26; i++)
        if(ans[i] != 0) cout << ans[i] << "\n";
    return 0;}