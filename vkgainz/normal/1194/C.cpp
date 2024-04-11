#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isSubstring(string &x, string &y){
    int i = 0;
    int j = 0;
    while(i<x.length() && j<y.length()){
        if(x[i]==y[j]){
            ++i;
        }
        ++j;
    }
    return i==x.length();
}
void solve(){
    string s,t,p;
    cin >> s >> t >> p;
    if(isSubstring(s,t)){
        int freq1[26];
        int freq2[26];
        memset(freq1,0,sizeof(freq1));
        memset(freq2,0,sizeof(freq2));
        for(int i=0;i<s.length();i++){
            ++freq1[s[i]-'a'];
        }
        for(int i=0;i<t.length();i++){
            ++freq2[t[i]-'a'];
        }
        for(int i=0;i<p.length();i++){
            ++freq1[p[i]-'a'];
        }
        bool work = true;
        for(int i=0;i<26;i++){
            work = work&&(freq1[i]>=freq2[i]);
        }
        if(work) cout << "YES" << endl;
        else cout << "NO" << endl;
    
    }
    else{
        cout << "NO" << endl;
    }
    
}
int main(){
    int q; cin >> q;
    while(q--){
        solve();
    }
}