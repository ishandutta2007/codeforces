#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<int> vis(26);
        for(char c : s) vis[c-'a'] = 1;
        int viscnt = 0;
        for(int i=0;i<26;++i) if(vis[i]) viscnt++;
        string ans;
        while(viscnt--) {
            for(int i=25;i>=0;--i) {
                if(!vis[i]) continue;
                int p=0; while(s[p]-'a'!=i) ++p;
                vector<int> vis2(26);
                for(int j=p+1;j<s.size();++j) {
                    vis2[s[j]-'a']=1;
                }
                int cnt=0;
                for(int j=0;j<26;++j) {
                    if(vis2[j] && i!=j) ++cnt;
                }
                if(cnt==viscnt) {
                    ans+=i+'a';
                    string nxt;
                    for(int j=p+1;j<s.size();++j) {
                        if(s[j]-'a'!=i) nxt+=s[j];
                    }
                    s=nxt;
                    vis[i]=0;
                    break;
                }

            }
        }
        cout<<ans<<endl;
    }
}